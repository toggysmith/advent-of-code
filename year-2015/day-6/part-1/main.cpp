#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

int get_no_of_lights_on(const std::vector<const std::string> actions) {
  return 0;
}

int main() {
  // Read in the input file line-by-line.
  std::ifstream input_file;

  input_file.open("puzzle-input", std::ios_base::in);

  std::string line;

  std::vector<const std::string> actions;

  while (input_file >> line) {
    actions.push_back(line);
  }

  int no_of_lights_on{get_no_of_lights_on(actions)};

  input_file.close();

  std::cout << "The number of lights on is " << no_of_lights_on << '\n';

  return EXIT_SUCCESS;
}
