#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

int get_no_of_lights_on(const std::vector<const std::string> actions) {
  std::array<std::array<bool, 1000>, 1000> lights;

  for (int i = 0; i < lights.size(); i++) {
    lights[i].fill(false);
  }

  const auto get_bounds_from_action =
      [](const std::string &action) -> std::tuple<int, int, int, int> {
    std::stringstream action_stream{action};
    std::string action_part;
    std::vector<std::string> action_parts;

    while (std::getline(action_stream, action_part, ' ')) {
      action_parts.push_back(action_part);
    }
    const auto convert_coords_to_values =
        [](const std::string &coords) -> std::tuple<int, int> {
      std::stringstream coords_stream{coords};
      std::string coord_1, coord_2;

      std::getline(coords_stream, coord_1, ',');
      std::getline(coords_stream, coord_2, ',');

      return std::make_tuple(std::stoi(coord_1), std::stoi(coord_2));
    };

    const auto [top_left_x, top_left_y] =
        convert_coords_to_values(action_parts[0]);
    const auto [bottom_right_x, bottom_right_y] =
        convert_coords_to_values(action_parts[2]);

    return std::make_tuple(top_left_x, top_left_y, bottom_right_x - top_left_x,
                           bottom_right_y - top_left_y);
  };

  for (const auto &action : actions) {
    if (action.substr(0, 7) == "turn on") {
      const auto [x, y, w, h] =
          get_bounds_from_action(action.substr(8, action.size()));
      for (int i_x = x; i_x <= x + w; i_x++) {
        for (int i_y = y; i_y <= y + h; i_y++) {
          lights[i_x][i_y] = true;
        }
      }
    } else if (action.substr(0, 8) == "turn off") {
      const auto [x, y, w, h] =
          get_bounds_from_action(action.substr(9, action.size()));
      for (int i_x = x; i_x <= x + w; i_x++) {
        for (int i_y = y; i_y <= y + h; i_y++) {
          lights[i_x][i_y] = false;
        }
      }
    } else {
      const auto [x, y, w, h] =
          get_bounds_from_action(action.substr(7, action.size()));
      for (int i_x = x; i_x <= x + w; i_x++) {
        for (int i_y = y; i_y <= y + h; i_y++) {
          lights[i_x][i_y] = !lights[i_x][i_y];
        }
      }
    }
  }

  int number_of_lights_on = 0;

  for (int x = 0; x < 1'000; x++) {
    for (int y = 0; y < 1'000; y++) {
      number_of_lights_on += static_cast<int>(lights[x][y]);
    }
  }

  return number_of_lights_on;
}

int main() {
  // Read in the input file line-by-line.
  std::ifstream input_file;

  input_file.open("puzzle-input", std::ios_base::in);

  std::string line;

  std::vector<const std::string> actions;

  while (std::getline(input_file, line)) {
    actions.push_back(line);
  }

  int no_of_lights_on{get_no_of_lights_on(actions)};

  input_file.close();

  std::cout << "The number of lights on is " << no_of_lights_on << '\n';

  return EXIT_SUCCESS;
}
