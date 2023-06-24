#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

bool is_naughty(std::string_view input) {
  bool repeating_letter{false};
  bool duplicate_pair{false};

  std::unordered_map<std::string, int> pairs;

  for (size_t i = 0; i < input.size(); i++) {
    // Check if the string contains at least one letter which repeats with
    // exactly one letter between them.
    if (!repeating_letter && i != 0 && input[i] == input[i - 2]) {
      repeating_letter = true;
    }

    // Check if the string contains a pair of two letters that appears twice
    // without overlapping.
    if (!duplicate_pair) {
      const std::string pair{input.substr(i, 2)};

      try {
        const int index_of_other_pair{pairs.at(pair)};

        if (i - index_of_other_pair > 1) {
          duplicate_pair = true;
        }
      } catch (std::out_of_range e) {
        pairs[pair] = i;
      }
    }
  }

  return !(repeating_letter && duplicate_pair);
}

bool run_test(const std::string &input_string, bool expected_is_naughty) {
  bool actual_is_naughty{is_naughty(input_string)};
  bool does_match{expected_is_naughty == actual_is_naughty};

  std::cout << std::left << std::setw(20) << input_string << std::setw(30)
            << (expected_is_naughty ? "true" : "false") << std::setw(30)
            << (actual_is_naughty ? "true" : "false") << '\n';

  return does_match;
}

bool run_tests() {
  // Table headings
  std::cout << std::left << std::setw(20) << "Secret Key" << std::setw(30)
            << "Expected Is Naughty" << std::setw(30) << "Actual Is Naughty"
            << "\n";

  // Gather test results
  std::vector<bool> test_results = {
      run_test("qjhvhtzxzqqjkmpb", false),
      run_test("xxyxx", false),
      run_test("uurcxstgmygtbstg", true),
      run_test("ieodomkazucvgmuy", true),
  };

  // Say whether any of the tests failed
  const auto failed_test{
      std::find(test_results.begin(), test_results.end(), 0)};

  bool does_failed_test_exist{failed_test != test_results.end()};

  if (does_failed_test_exist) {
    std::cout << "\nTests failed.\n";
  } else {
    std::cout << "\nTests passed.\n";
  }

  return !does_failed_test_exist;
}

int main() {
  bool did_tests_pass{run_tests()};

  if (!did_tests_pass)
    return EXIT_SUCCESS;

  // Read in the input file line-by-line.
  std::ifstream input_file;

  input_file.open("puzzle-input", std::ios_base::in);

  std::string line;
  int number_of_nice_strings{0};

  while (input_file >> line) {
    if (!is_naughty(line)) {
      number_of_nice_strings++;
    }
  }

  input_file.close();

  std::cout << "The number of nice strings is " << number_of_nice_strings
            << '\n';

  return EXIT_SUCCESS;
}
