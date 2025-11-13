#include <algorithm>
#include <cstdint>

#include <parlay/parallel.h>
#include <parlay/primitives.h>
#include <parlay/sequence.h>

namespace detail {
template <typename Range> auto partition(Range vec, uint64_t l, uint64_t r) {
  auto pivot = vec[r];
  auto i = l;
  for (auto j = l; j < r; j++) {
    if (vec[j] < pivot) {
      std::swap(vec[i++], vec[j]);
    }
  }
  std::swap(vec[i], vec[r]);
  return i;
}

constexpr uint64_t N = 100000;

template <typename Range> void sort_seq_impl(Range vec) {
  auto n = vec.size();
  if (n < N) {
    std::sort(vec.begin(), vec.end());
    return;
  }
  auto pivot = partition(vec, 0, n - 1);
  sort_seq_impl(vec.cut(0, pivot));
  sort_seq_impl(vec.cut(pivot + 1, n));
}

template <typename Range> void sort_par_impl(Range vec) {
  auto n = vec.size();
  if (n < N) {
    std::sort(vec.begin(), vec.end());
    return;
  }
  auto pivot = partition(vec, 0, n - 1);
  parlay::par_do([&] { sort_par_impl(vec.cut(0, pivot)); },
                 [&] { sort_par_impl(vec.cut(pivot + 1, n)); });
}
} // namespace detail

template <typename Range> auto sort_seq(Range &vec) {
  detail::sort_seq_impl(vec.cut(0, vec.size()));
}

template <typename Range> auto sort_par(Range &vec) {
  detail::sort_par_impl(vec.cut(0, vec.size()));
}
