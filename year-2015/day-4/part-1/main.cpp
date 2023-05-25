#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <string_view>
#include "dynamic_bitset.hpp"

int
get_lowest_number_for_hash(const std::string_view secret_key) {
  DynamicBitset dynamic_bitset;

  dynamic_bitset.expand(1, true);
  dynamic_bitset.expand(4, false);

  if (dynamic_bitset.test(1)) {
    std::cout << "is true\n";
  }

  std::cout << dynamic_bitset << std::endl;

  dynamic_bitset.set(2, true);

  std::cout << dynamic_bitset << std::endl;

  return 0;
}

bool
run_test(const std::string_view secret_key, int expected_lowest_number_for_hash) {
  int actual_lowest_number_for_hash{
    get_lowest_number_for_hash(secret_key)
  };
  bool does_match{ expected_lowest_number_for_hash == actual_lowest_number_for_hash };

  std::cout << std::left
            << std::setw(12) << secret_key
            << std::setw(35) << expected_lowest_number_for_hash
            << std::setw(50) << actual_lowest_number_for_hash 
            << '\n';

  return does_match;
}

bool
run_tests() {
  // Table headings
  std::cout << std::left
            << std::setw(12) << "Secret Key"
            << std::setw(35) << "Expected Lowest Number for Hash"
            << std::setw(50) << "Actual Lowest Number for Hash"
            << "\n\n";

  // Gather test results
  std::vector<bool> test_results = {
    run_test("abcdef", 609043),
    run_test("pqrstuv", 1048970)
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
    DynamicBitset dynamic_bitset;

  dynamic_bitset.expand(1, true);
  dynamic_bitset.expand(4, false);

  if (dynamic_bitset.test(1)) {
    std::cout << "is true\n";
  }

  std::cout << dynamic_bitset << std::endl;

  dynamic_bitset.set(2, true);

  std::cout << dynamic_bitset << std::endl;


  return 0;

//////////////////////////////////////////

  bool did_tests_pass{ run_tests() };

  if (!did_tests_pass) return EXIT_SUCCESS;

  // Read in the input file
  std::ifstream input_file;

  input_file.open("puzzle-input", std::ios_base::in);

  std::stringstream file_buffer;

  file_buffer << input_file.rdbuf();

  std::string file_contents{ file_buffer.str() };

  // Pass the input into the function and print the output
  int lowest_number_for_hash{ get_lowest_number_for_hash(file_contents) };

  std::cout << "\nThe lowest number for the hash is " << lowest_number_for_hash << '\n';

  return EXIT_SUCCESS;
}
