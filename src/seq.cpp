#include <cstdlib>
#include <exception>
#include <iostream>

#include "run.h"
#include "sort.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Incorrect number of arguments" << std::endl;
    return EXIT_FAILURE;
  }
  try {
    constexpr int ATTEMPTS = 5;
    long n = std::stol(argv[1]);
    double time = 0;
    for (int i = 0; i < ATTEMPTS; i++) {
      time += run(n, sort_seq<Seq>);
    }
    std::cout.precision(4);
    std::cout << std::fixed;
    std::cout << "Average time: " << time / ATTEMPTS << std::endl;
    return EXIT_SUCCESS;
  } catch (std::exception &ex) {
    std::cerr << ex.what() << std::endl;
    return EXIT_FAILURE;
  }
}
