#include "benchmarks/benchmark_pgm.h"

#include "benchmark.h"
#include "benchmarks/common.h"
#include "competitors/pgm_index.h"
//#include "competitors/port_infer.h"

template <template <typename> typename Searcher>
void benchmark_32_pgm(sosd::Benchmark<uint32_t, Searcher>& benchmark,
                      bool pareto) {

}

template <template <typename> typename Searcher>
void benchmark_64_pgm(sosd::Benchmark<uint64_t, Searcher>& benchmark,
                      bool pareto) {
  benchmark.template Run<PGM<uint64_t, 16>>();
}

INSTANTIATE_TEMPLATES(benchmark_32_pgm, uint32_t);
INSTANTIATE_TEMPLATES(benchmark_64_pgm, uint64_t);
