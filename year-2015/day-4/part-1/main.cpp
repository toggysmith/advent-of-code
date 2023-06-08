#include <iostream>
#include <string_view>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>

#include "md5.h"

long long
get_answer(const std::string& secret_key) {
  long long number{ -1 };
  std::string hash{ "" };

  do {
    hash = md5(secret_key + std::to_string(++number));
  } while (hash.substr(0, 5) != "00000");

  return number;
}

bool
run_test(const std::string& secret_key, int expected_number) {
  long long actual_number{ get_answer(secret_key) };
  bool does_match{ expected_number == actual_number };

  std::cout << std::left
            << std::setw(20) << secret_key
            << std::setw(50) << expected_number 
            << std::setw(50) << actual_number
            << '\n';

  return does_match;
}

bool
run_tests() {
  // Table headings
  std::cout << std::left
            << std::setw(20) << "Secret Key"
            << std::setw(50) << "Expected Number"
            << std::setw(50) << "Actual Number"
            << "\n";

  // Gather test results
  std::vector<bool> test_results = {
    run_test("abcdef", 609043),
    run_test("pqrstuv", 1048970),
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
  file_contents.erase(std::remove(file_contents.begin(), file_contents.end(), '\n'), file_contents.cend());

  // Pass the input into the function and print the output
  long long number{ get_answer(file_contents) };

  std::cout << "\nThe number is " << number << '\n';

  return EXIT_SUCCESS;
}
