// #include <benchmark/benchmark.h>
// #include <MeLibInternal.hpp>

// #include <array>
// #include <numeric>

// template <int NB> void BM_Copy(benchmark::State& state) {
//     std::array<int, 1000> src, dst;
//     std::iota(src.begin(), src.end(), 0);

//     for (auto _ : state) {
//         melib::copy<NB>(dst.data(), src.data(), 1000);
//     }
// }
// BENCHMARK_TEMPLATE(BM_Copy, 1);
// BENCHMARK_TEMPLATE(BM_Copy, 2);
// BENCHMARK_TEMPLATE(BM_Copy, 4);
// BENCHMARK_TEMPLATE(BM_Copy, 8);
// BENCHMARK_TEMPLATE(BM_Copy, 16);
// BENCHMARK_TEMPLATE(BM_Copy, 32);
// BENCHMARK_TEMPLATE(BM_Copy, 64);
// BENCHMARK_TEMPLATE(BM_Copy, 128);

// BENCHMARK_MAIN();

#include <iostream>

int main() {
    std::cout << 2 << std::endl;
}