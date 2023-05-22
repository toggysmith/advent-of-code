#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <array>

double
get_square_feet_of_wrapping_paper_needed(int length, int width, int height) {
  // The box is made up of three pairs of sides. We calculate the combined area for each pair.
  int pair_1_area{ 2 * length * width };
  int pair_2_area{ 2 * width * height };
  int pair_3_area{ 2 * height * length };

  // We then calculate the total surface area of the box.
  int total_surface_area{ pair_1_area + pair_2_area + pair_3_area };

  // We work out which side pair is smallest.
  int area_of_smallest_side_pair{ std::min({pair_1_area, pair_2_area, pair_3_area}) };

  // We can then work out the area of the smallest side by dividing the pair's area in two.
  double area_of_smallest_side{ area_of_smallest_side_pair / 2.0 };

  // Total wrapping paper needed = surface area + area of smallest side
  return total_surface_area + area_of_smallest_side;
}

bool
run_test(int length, int width, int height, int expected_square_feet_of_wrapping_paper_needed) {
  double actual_square_feet_of_wrapping_paper_needed{
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

  if (!did_tests_pass) return EXIT_SUCCESS;

  // Read the input file line-by-line.
  std::ifstream input_file;

  input_file.open("puzzle-input", std::ios_base::in);

  std::string line;

  double total_area{ 0.0 };

  while (input_file >> line) {
    std::array<int, 3> dimensions;

    std::stringstream line_stream{ line };
    int dimensions_added{ 0 };
    std::string dimension;

    while (getline(line_stream, dimension, 'x')) {
      dimensions[dimensions_added++] = std::stoi(dimension);
    }

    total_area += get_square_feet_of_wrapping_paper_needed(dimensions[0], dimensions[1], dimensions[2]);
  }

  input_file.close();

  // Show the total amount needed
  std::cout << "\nThe total amount of wrapping paper needed is " << std::fixed << total_area << " square feet.\n";

  return EXIT_SUCCESS;
}
