#include <optional>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>

int
get_parenthesis_which_enters_basement(std::string parentheses) {
  return 0;
}

bool
run_test(std::string parentheses, int expected_parenthesis_which_enters_basement) {
  int parenthesis_which_enters_basement{ get_parenthesis_which_enters_basement(parentheses) };
  bool does_match{ parenthesis_which_enters_basement == expected_parenthesis_which_enters_basement };

  std::cout << std::left
            << std::setw(20) << parentheses
            << std::setw(20) << parenthesis_which_enters_basement
            << '\n';

  return does_match;
}

bool
run_tests() {
  // Table headings
  std::cout << std::left
            << std::setw(20) << "Parentheses"
            << std::setw(20) << "Parenthesis Which Enters Basement"
            << "\n\n";

  // Gather test results
  std::vector<bool> test_results = {
    run_test(")", 1),
    run_test("()())", 5),
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
  // Run all the tests first before trying it on the real thing
  bool did_tests_pass{ run_tests() };

  if (!did_tests_pass) return EXIT_SUCCESS;

  return EXIT_SUCCESS;
}
