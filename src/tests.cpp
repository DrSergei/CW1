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

void check(uint64_t n = N, uint64_t max = N) {
  parlay::execute_with_scheduler(4, [=]() {
    auto vec1 = generate(N, max);
    auto vec2 = vec1;
    auto vec3 = vec1;
    std::sort(vec1.begin(), vec1.end());
    sort_seq(vec2);
    eq(vec1, vec2);
    sort_par(vec3);
    eq(vec1, vec3);
  });
}

void check_random() { check(N); }

void check_small() { check(N, 10); }

void check_01() { check(N, 1); }

void check_common() {
  std::vector<parlay::sequence<long>> cases = {
      {},
      {0},
      {0, 0},
      {0, 0, 0},
      {0, 1},
      {1, 0},
      {0, 1, 2},
      {0, 2, 1},
      {1, 0, 2},
      {1, 2, 0},
      {2, 0, 1},
      {2, 1, 0},
      {0, 1, 1},
      {1, 0, 1},
      {1, 1, 0},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
      {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
      {1, -1, 1, -1, 1, -1, 1, -1, -1, 1},
      {-1, 1, -1, 1, -1, 1, -1, -1, 1, -1},
  };
  for (size_t i = 0; i < 50; i++) {
    cases.push_back(generate(1000, 10));
  }
  for (const auto &test : cases) {
    auto vec1 = test;
    sort_seq<decltype(vec1), 1>(vec1);
    auto vec2 = test;
    sort_par<decltype(vec2), 1>(vec2);
    eq(vec1, vec2);
    if (!std::is_sorted(vec1.begin(), vec1.end())) {
      throw std::runtime_error("not sorted");
    }
  }
}

int main() {
  try {
    for (int i = 0; i < 20; i++) {
      check_random();
      check_small();
      check_01();
    }
    check_common();
    std::cout << "Tests success" << std::endl;
    return EXIT_SUCCESS;
  } catch (...) {
    std::cerr << "Tests failed" << std::endl;
    return EXIT_FAILURE;
  }
}
