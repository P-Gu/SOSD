#include "benchmarks/benchmark_port.h"

#include <string>

#include "benchmark.h"
#include "benchmarks/common.h"
//#include "competitors/analysis-rmi/include/rmi/models.hpp"
//#include "competitors/analysis-rmi/include/rmi/rmi_robust.hpp"
//#include "competitors/rmi_cpp_robust.h"

template <template <typename> typename Searcher>
void benchmark_32_port(sosd::Benchmark<uint32_t, Searcher>& benchmark,
                      bool pareto) {
}

template <template <typename> typename Searcher>
void benchmark_64_port(sosd::Benchmark<uint64_t, Searcher>& benchmark,
                      bool pareto) {
  /*benchmark.template Run<
      RMICppRobust<uint64_t, rmi::LinearRegression, rmi::LinearRegression,
                   rmi::RmiLAbsRobust, 128, 1>>();*/
}

INSTANTIATE_TEMPLATES(benchmark_32_port, uint32_t);
INSTANTIATE_TEMPLATES(benchmark_64_port, uint64_t);
