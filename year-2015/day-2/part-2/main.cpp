#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <array>

int
get_feet_of_ribbon_needed(int length, int width, int height) {
  return 0;
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
