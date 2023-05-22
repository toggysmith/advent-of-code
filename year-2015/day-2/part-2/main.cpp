#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>

int
get_feet_of_ribbon_needed(int length, int width, int height) {
  // Calculate the shortest distance
  std::vector<int> dimensions{ length, width, height };

  auto dimensions_it{ std::min_element(std::begin(dimensions), std::end(dimensions)) };

  int shortest_dimension{ *dimensions_it };

  // Calculate the next shortest distance
  std::vector<int> dimensions_without_shortest;

  bool did_already_remove_shortest_dimension{ false }; // Necessary because if we have 1x1x4 we don't want to remove both 1's

  std::copy_if(dimensions.begin(), dimensions.end(), std::back_inserter(dimensions_without_shortest), [shortest_dimension, &did_already_remove_shortest_dimension](int dimension) {
    if (dimension != shortest_dimension) return true;
    if (did_already_remove_shortest_dimension) return true;

    did_already_remove_shortest_dimension = true;
    return false;
  });

  auto dimensions_without_shortest_it{ std::min_element(std::begin(dimensions_without_shortest), std::end(dimensions_without_shortest)) };

  int next_shortest_dimension{ *dimensions_without_shortest_it };

  std::cout << shortest_dimension << " " << next_shortest_dimension << std::endl;

  // Calculate perimeter of face with shortest perimeter
  int perimeter_of_face_with_shortest_perimeter{ shortest_dimension * 2 + next_shortest_dimension * 2 };

  // Calculate cubic volume of the box
  int cubic_volume{ length * width * height };

  // Ribbon needed = perimeter of face with shortest perimeter + cubic volume of box
  return perimeter_of_face_with_shortest_perimeter + cubic_volume;
}

bool
run_test(int length, int width, int height, int expected_feet_of_ribbon_needed) {
  int actual_feet_of_ribbon_needed{
    get_feet_of_ribbon_needed(length, width, height)
  };
  bool does_match{ actual_feet_of_ribbon_needed == expected_feet_of_ribbon_needed };

  std::cout << std::left
            << std::setw(7) << length
            << std::setw(7) << width 
            << std::setw(7) << height 
            << std::setw(40) << expected_feet_of_ribbon_needed 
            << std::setw(40) << actual_feet_of_ribbon_needed 
            << '\n';

  return does_match;
}

bool
run_tests() {
  // Table headings
  std::cout << std::left
            << std::setw(7) << "Length"
            << std::setw(7) << "Width"
            << std::setw(7) << "Height"
            << std::setw(40) << "Expected Feet of Ribbon Needed"
            << std::setw(40) << "Actual Feet of Ribbon Needed"
            << "\n\n";

  // Gather test results
  std::vector<bool> test_results = {
    run_test(2, 3, 4, 34),
    run_test(1, 1, 10, 14),
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

  return EXIT_SUCCESS;
}
