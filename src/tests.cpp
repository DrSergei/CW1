#include <cstdlib>
#include <stdexcept>

#include "run.h"
#include "sort.h"

constexpr uint64_t N = 10000000;

template <typename T> void eq(T &l, T &r) {
  if (l == r) {
    return;
  }
  throw std::runtime_error("not equal");
}

int main() {
  try {
    for (int i = 0; i < 100; i++) {
      auto vec1 = generate(N);
      auto vec2 = vec1;
      auto vec3 = vec1;
      std::sort(vec1.begin(), vec1.end());
      sort_seq(vec2);
      eq(vec1, vec2);
      sort_par(vec3);
      eq(vec1, vec3);
    }
    std::cout << "Tests success" << std::endl;
    return EXIT_SUCCESS;
  } catch (...) {
    std::cerr << "Tests failed" << std::endl;
    return EXIT_FAILURE;
  }
}
