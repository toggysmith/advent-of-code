#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>

bool
is_naughty(std::string_view input) {
  // 1. Check for naughty substrings.
  for (int i = 0; i < input.size() - 1; i++) {
    const std::string_view substring{ input.substr(i, 2) };

    if (substring == "ab" || substring == "cd" || substring == "pq" || substring == "xy") {
      return true;
    }
  }

  // 2. Check for letters appearing twice and at least three vowels.
  char previous_character{ 'A' }; // Set it to an uppercase because this can't occur in the input.
  const std::vector<char> vowels{ 'a', 'e', 'i', 'o', 'u' };
  int number_of_vowels_encountered{ 0 };

  bool does_a_letter_appear_twice{ false };

  for (const auto character : input) {
    // 2.1. Don't bother checking for characters appearing twice if we already found one.
    if (!does_a_letter_appear_twice) {
      does_a_letter_appear_twice = previous_character == character;
      previous_character = character;
    }

    // 2.2. Check for vowels.
    if (number_of_vowels_encountered != 3) {
      if (std::find(vowels.begin(), vowels.end(), character) != vowels.end()) {
        number_of_vowels_encountered++;
      }
    }
  }

  // 3. Return whether both conditions are met.
  return !(does_a_letter_appear_twice && number_of_vowels_encountered >= 3);
}

bool
run_test(const std::string& input_string, bool expected_is_naughty) {
  bool actual_is_naughty{ is_naughty(input_string) };
  bool does_match{ expected_is_naughty == actual_is_naughty };

  std::cout << std::left
            << std::setw(20) << input_string
            << std::setw(30) << (expected_is_naughty ? "true" : "false")
            << std::setw(30) << (actual_is_naughty ? "true" : "false")
            << '\n';

  return does_match;
}

bool
run_tests() {
  // Table headings
  std::cout << std::left
            << std::setw(20) << "Secret Key"
            << std::setw(30) << "Expected Is Naughty"
            << std::setw(30) << "Actual Is Naughty"
            << "\n";

  // Gather test results
  std::vector<bool> test_results = {
    run_test("ugknbfddgicrmopn", false),
    run_test("aaa", false),
    run_test("jchzalrnumimnmhp", true),
    run_test("haegwjzuvuyypxyu", true),
    run_test("dvszwmarrgswjxmb", true),
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

  // Read in the input file line-by-line.
  std::ifstream input_file;

  input_file.open("puzzle-input", std::ios_base::in);

  std::string line;
  int number_of_nice_strings{ 0 };

  while (input_file >> line) {
    if (!is_naughty(line)) {
      number_of_nice_strings++;
    }
  }

  input_file.close();

  std::cout << "The number of nice strings is " << number_of_nice_strings << '\n';

  return EXIT_SUCCESS;
}
