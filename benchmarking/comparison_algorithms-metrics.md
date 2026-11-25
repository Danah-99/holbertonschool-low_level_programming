# Algorithmic Efficiency Comparison

## Setup

- Program: `comparison_algorithms.c`
- Compilation: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 comparison_algorithms.c -o comparison_algorithms`
- Array size: 50000
- Number of executions: 3
- Algorithm logic, input data, and timing logic were not modified.

## Raw Execution Times

| Run | Implementation A: Naive (seconds) | Implementation B: Single-pass (seconds) |
|---|---|---|
| 1 | 2.743697 | 0.000106 |
| 2 | 2.749978 | 0.000106 |
| 3 | 2.744245 | 0.000106 |

## Average Execution Time

| Implementation | Average time (seconds) |
|---|---|
| A: Naive (`count_even_naive`) | 2.745973 |
| B: Single-pass (`count_even_single_pass`) | 0.000106 |

Calculation:

- Naive average = (2.743697 + 2.749978 + 2.744245) / 3 = **2.745973 s**
- Single-pass average = (0.000106 + 0.000106 + 0.000106) / 3 = **0.000106 s**

## Relative Difference

- Ratio = 2.745973 / 0.000106 ≈ **25905**
- **Implementation A (naive) is ~25,905 times slower than Implementation B (single-pass).**

## Observations

- The naive implementation uses a nested loop: for each index `i`, it scans all elements from `0` to `i`. This performs about n(n+1)/2 ≈ 1.25 billion iterations, so its complexity is **O(n²)**.
- The single-pass implementation scans the array once, performing 50000 iterations, so its complexity is **O(n)**.
- Execution times were very stable across the three runs (naive varied by less than 0.01 s), so the measurements are consistent.
- The two functions also return different results (naive: 625025000, single-pass: 25000) because the naive version re-counts earlier elements on every outer iteration.
