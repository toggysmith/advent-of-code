#include <optional>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

int
get_floor(std::string parentheses) {
  return 0;
}

bool
run_test(std::string parentheses, int expected_floor) {
  int actual_floor{ get_floor(parentheses) };
  bool does_match{ expected_floor == actual_floor };

  std::cout << std::left
            << std::setw(20) << parentheses
            << std::setw(20) << expected_floor
            << std::setw(20) << actual_floor
            << '\n';

  return does_match;
}

void
run_tests() {
  // Table headings
  std::cout << std::left
            << std::setw(20) << "Parentheses"
            << std::setw(20) << "Expected Floor"
            << std::setw(20) << "Actual Floor"
            << "\n\n";

  // Gather test results
  std::vector<bool> test_results = {
    // Floor 0
    run_test("(())", 0),
    run_test("()()", 0),

    // Floor 3
    run_test("(((", 3),
    run_test("(()(()(", 3),
    run_test("))(((((", 3),

    // Floor -1
    run_test("())", -1),
    run_test("))(", -1),

    // Floor -3
    run_test(")))", -3),
    run_test(")())())", -3),
  };

  // Say whether any of the tests failed
  const auto failed_test{ std::find(test_results.begin(), test_results.end(), true) };

  bool does_failed_test_exist{ failed_test != test_results.end() };

  if (does_failed_test_exist) {
    std::cout << "\nTests failed.\n";
  } else {
    std::cout << "\nTests passed.\n";
  }
}

int
main() {
  run_tests();

  return EXIT_SUCCESS;
}
