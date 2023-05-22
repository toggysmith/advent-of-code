#include <optional>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>

int
get_floor(std::string parentheses) {
  int floor{ 0 };

  for (const auto parenthesis : parentheses) {
    switch (parenthesis) {
      case '(':
        floor++;
        break;
      case ')':
        floor--;
        break;
    }
  }

  return floor;
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

bool
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

  // Read in the input file
  std::ifstream input_file;

  input_file.open("puzzle-input", std::ios_base::in);

  std::stringstream file_buffer;

  file_buffer << input_file.rdbuf();

  std::string file_contents{ file_buffer.str() };

  // Pass the input into the function and print the output
  int floor{ get_floor(file_contents) };

  std::cout << "\nThe current floor is " << floor << '\n';

  return EXIT_SUCCESS;
}
