#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

int
get_number_of_houses_with_a_present(const std::string_view movements) {
  struct Location {
    int x, y;
  };

  struct VisitedLocations {
    std::vector<Location> visited_locations{
      Location{0, 0},
    };

    void add(Location visited_location) {
      const auto it{
        std::find_if(visited_locations.begin(), visited_locations.end(), [visited_location](Location& location) {
          return location.x == visited_location.x && location.y == visited_location.y;
        })
      };

      if (it == visited_locations.end()) {
        visited_locations.push_back(visited_location);
      }
    }

    size_t size() { 
      return visited_locations.size();
    }
  };

  VisitedLocations visited_locations;

  Location current_location{ 0, 0 };

  for (const auto movement : movements) {
    switch (movement) {
      case '<':
        current_location.x--;
        visited_locations.add(current_location);
        break;
      case '>':
        current_location.x++;
        visited_locations.add(current_location);
        break;
      case '^':
        current_location.y--;
        visited_locations.add(current_location);
        break;
      case 'v':
        current_location.y++;
        visited_locations.add(current_location);
        break;
    }
  }

  return visited_locations.size();
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
