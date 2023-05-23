#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

int
get_number_of_houses_with_a_present(const std::string_view movements) {
  return 0;
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
    run_test(">", 2),
    run_test("^>v<", 4),
    run_test("^v^v^v^v^v", 2),
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
