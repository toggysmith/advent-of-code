#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

int
get_number_of_houses_with_a_present(const std::string_view movements) {
  struct Location {
    int x, y;

    bool operator==(const Location& other_location) const {
      return this->x == other_location.x && this->y == other_location.y;
    }
  };

  struct VisitedLocations {
    std::vector<Location> visited_locations{
      Location{0, 0},
    };

    void add(Location visited_location) {
      const auto it{
        std::find_if(visited_locations.begin(), visited_locations.end(), [visited_location](Location& location) {
          return location.x == visited_location.x && location.y == visited_location.y;
        })
      };

      if (it == visited_locations.end()) {
        visited_locations.push_back(visited_location);
      }
    }

    size_t size() { 
      return visited_locations.size();
    }
  };

  std::string santa_movements;
  std::string robo_santa_movements;

  {
    int index{ 0 };
    std::copy_if(movements.begin(), movements.end(), std::back_inserter(robo_santa_movements), [index](auto _) mutable {
      return index++ % 2;
    });
  }

  {
    int index{ 0 };
    std::copy_if(movements.begin(), movements.end(), std::back_inserter(santa_movements), [index](auto _) mutable {
      return !(index++ % 2);
    });
  }

  const auto get_visited_locations = [](std::string_view movements) {
    Location current_location{ 0, 0 };
    VisitedLocations visited_locations;

    for (const auto movement : movements) {
      switch (movement) {
        case '<':
          current_location.x--;
          visited_locations.add(current_location);
          break;
        case '>':
          current_location.x++;
          visited_locations.add(current_location);
          break;
        case '^':
          current_location.y--;
          visited_locations.add(current_location);
          break;
        case 'v':
          current_location.y++;
          visited_locations.add(current_location);
          break;
      }
    }
    
    return visited_locations;
  };

  VisitedLocations combined_visited_locations_without_duplicates{ get_visited_locations(santa_movements) };
  VisitedLocations robo_santa_visited_locations{ get_visited_locations(robo_santa_movements) };

  std::copy_if(robo_santa_visited_locations.visited_locations.begin(), robo_santa_visited_locations.visited_locations.end(), std::back_inserter(combined_visited_locations_without_duplicates.visited_locations), [combined_visited_locations_without_duplicates](Location location) {
    const auto it{
      std::find(combined_visited_locations_without_duplicates.visited_locations.begin(), combined_visited_locations_without_duplicates.visited_locations.end(), location)
    };

    return it == combined_visited_locations_without_duplicates.visited_locations.end();
  });

  return combined_visited_locations_without_duplicates.size();
}

bool
run_test(const std::string_view movements, int expected_number_of_houses_with_a_present) {
  int actual_number_of_houses_with_a_present{
    get_number_of_houses_with_a_present(movements)
  };
  bool does_match{ expected_number_of_houses_with_a_present == actual_number_of_houses_with_a_present };

  std::cout << std::left
            << std::setw(20) << movements
            << std::setw(50) << expected_number_of_houses_with_a_present 
            << std::setw(50) << actual_number_of_houses_with_a_present 
            << '\n';

  return does_match;
}

bool
run_tests() {
  // Table headings
  std::cout << std::left
            << std::setw(20) << "Movements"
            << std::setw(50) << "Expected Number of Houses With a Present"
            << std::setw(50) << "Actual Number of Houses With a Present"
            << "\n\n";

  // Gather test results
  std::vector<bool> test_results = {
    run_test("^v", 3),
    run_test("^>v<", 3),
    run_test("^v^v^v^v^v", 11),
  };

  // Say whether any of the tests failed
  const auto failed_test{ std::find(test_results.begin(), test_results.end(), 0) };

  bool does_failed_test_exist{ failed_test != test_results.end() };

  if (does_failed_test_exist) {
    std::cout << "\nTests failed.\n";
  } else {
    std::cout << "\nTests passed.\n";
  }

  return !does_failed_test_exist;
}

int
main() {
  bool did_tests_pass{ run_tests() };

  if (!did_tests_pass) return EXIT_SUCCESS;

  // Read in the input file
  std::ifstream input_file;

  input_file.open("puzzle-input", std::ios_base::in);

  std::stringstream file_buffer;

  file_buffer << input_file.rdbuf();

  std::string file_contents{ file_buffer.str() };

  // Pass the input into the function and print the output
  int number_of_houses_with_a_present{ get_number_of_houses_with_a_present(file_contents) };

  std::cout << "\nThe number of houses with a present is " << number_of_houses_with_a_present << '\n';

  return EXIT_SUCCESS;
}
