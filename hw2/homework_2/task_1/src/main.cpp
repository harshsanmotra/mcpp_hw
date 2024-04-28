#include <cstdlib>
#include <iostream>
#include <limits>

#include "random_gen.hpp"

using std::cin;
using std::cout;
using std::endl;

int main() {
  int guess;
  int target = RandomNum();

  while (true) {
    cout << "Enter your guess: ";
    cin >> guess;

    if (cin.fail()) {
      std::cerr << "[WARNING] : Number must be between 0 and 99" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      /*1) cin.ignore - To ignore (extract and discard) values that we don't
      want on the stream 2) cin.clear - To clear the internal state of stream.
      After using cin.clear internal state is set again back to goodbit, which
      means that there are no 'errors'.*/
      continue;
    }
    if (guess == target) {
      std::cout
          << "Congratulations! You've guessed the number. The number was: "
          << target << std::endl;
      return EXIT_SUCCESS;
    } else if (guess < target) {
      std::cout << "My number is larger." << std::endl;
    } else {
      std::cout << "My number is smaller." << std::endl;
    }
  }
  std::cerr << "Error encountered, exiting..." << std::endl;
  return EXIT_FAILURE;
}