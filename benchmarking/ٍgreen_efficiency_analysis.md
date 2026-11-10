# Green Efficiency Analysis

## Measurement Methodology

All measurements were taken by running the provided C programs on the same machine and recording the execution time printed by each program. Each program was compiled with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89` and executed three times without modifying the algorithm logic, input data, or timing logic. Running each program three times allowed me to check whether the results were consistent or affected by random variation.

Two experiments were used:

- **Baseline loop (`baseline_loop.c`):** a simple loop of 100,000,000 iterations.
- **Algorithm comparison (`comparison_algorithms.c`):** two implementations that count even numbers in an array of 50,000 elements, a naive version (`count_even_naive`) and a single-pass version (`count_even_single_pass`).

## Observed Performance Differences

The baseline loop recorded 0.195718 s, 0.222525 s, and 0.103108 s across three runs, an average of about 0.174 s.

The algorithm comparison showed a much larger difference:

| Implementation | Run 1 (s) | Run 2 (s) | Run 3 (s) | Average (s) |
|---|---|---|---|---|
| A: Naive | 2.743697 | 2.749978 | 2.744245 | 2.745973 |
| B: Single-pass | 0.000106 | 0.000106 | 0.000106 | 0.000106 |

The naive implementation was about 25,905 times slower than the single-pass implementation (2.745973 / 0.000106). The reason is the amount of work: the naive version uses a nested loop and performs about 1.25 billion iterations (O(n²)), while the single-pass version scans the array once with 50,000 iterations (O(n)).

## Relation Between Runtime and Energy Consumption

When a program runs, the CPU stays active and draws power for the whole execution time. A program that runs longer on the same hardware keeps the processor busy longer, so it consumes more energy. Based on my measurements, the naive implementation kept the CPU busy for about 2.75 seconds, while the single-pass version finished in about 0.0001 seconds for the same input. Assuming similar power draw during both runs, the naive version would consume far more energy simply because it runs thousands of times longer. Execution time is therefore a useful indirect indicator of energy use.

## Limitations of the Experiment

- **Energy was not measured directly.** Only execution time was recorded, so the energy conclusions are estimates based on runtime, not real power readings.
- **Results vary between runs.** The baseline loop ranged from 0.103108 s to 0.222525 s, about a 2x difference for the same code, which shows that other processes and system activity affect timing.
- **Small sample size.** Each program was run only three times, which is not enough for strong statistical conclusions.
- **Single machine.** All tests ran on one computer, so results may differ on other hardware or compilers.

## Practical Engineering Takeaway

Choosing an efficient algorithm has a much bigger impact than small code tweaks. In my measurements, replacing an O(n²) approach with an O(n) approach reduced runtime from 2.745973 s to 0.000106 s. Less runtime means less CPU work and less energy, which matters when code runs many times or at large scale. Engineers should measure performance, avoid unnecessary nested loops, and treat efficiency as part of writing sustainable software.
