#include <benchmark/benchmark.h>
#include <cpp-project-template/module/module.h>

static void BM_ModuleFunction(benchmark::State& state)
{
  for (auto _ : state) {
    module::module_function(common::Common{"true"}, "true");
  }
}

BENCHMARK(BM_ModuleFunction);

BENCHMARK_MAIN();