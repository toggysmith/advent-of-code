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
  } while (hash.substr(0, 6) != "000000");

  return number;
}

int
main() {
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
