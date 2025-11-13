#include <cstdint>
#include <functional>

#include <parlay/internal/get_time.h>
#include <parlay/io.h>
#include <parlay/parallel.h>
#include <parlay/primitives.h>
#include <parlay/random.h>
#include <parlay/sequence.h>

using Seq = parlay::sequence<long, parlay::allocator<long>, false>;

inline auto generate(uint64_t n) {
  static std::random_device rnd;
  parlay::random_generator gen(rnd());
  std::uniform_int_distribution<long> dis(0, n - 1);
  auto vec = parlay::tabulate(n, [&](long i) {
    auto r = gen[i];
    return dis(r);
  });
  return vec;
}

inline double run(uint64_t n, std::function<void(Seq &)> cb) {
  auto vec = generate(n);
  parlay::internal::timer t;
  cb(vec);
  return t.next_time();
}
