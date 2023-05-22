#include <iostream>
#include <vector>
#include <iomanip>

int
get_square_feet_of_wrapping_paper_needed(int length, int width, int height) {
  return 0;
}

bool
run_test(int length, int width, int height, int expected_square_feet_of_wrapping_paper_needed) {
  int actual_square_feet_of_wrapping_paper_needed{
    get_square_feet_of_wrapping_paper_needed(length, width, height)
  };
  bool does_match{ actual_square_feet_of_wrapping_paper_needed == expected_square_feet_of_wrapping_paper_needed };

  std::cout << std::left
            << std::setw(7) << length
            << std::setw(7) << width 
            << std::setw(7) << height 
            << std::setw(40) << expected_square_feet_of_wrapping_paper_needed 
            << std::setw(40) << actual_square_feet_of_wrapping_paper_needed 
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
            << std::setw(40) << "Expected Feet^2 of Wrapping Paper"
            << std::setw(40) << "Actual Feet^2 of Wrapping Paper"
            << "\n\n";

  // Gather test results
  std::vector<bool> test_results = {
    run_test(2, 3, 4, 58),
    run_test(1, 1, 10, 43),
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

  return EXIT_SUCCESS;
}
