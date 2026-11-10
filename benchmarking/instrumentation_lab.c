#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
	*state = (*state * 1103515245u) + 12345u;
	return *state;
}

static void build_dataset(void)
{
	unsigned int state;
	int i;

	state = SEED_VALUE;

	for (i = 0; i < DATASET_SIZE; i++)
		dataset[i] = (int)(next_value(&state) % 100000);
}

static void process_dataset(void)
{
	int i;
	int v;

	for (i = 0; i < DATASET_SIZE; i++)
	{
		v = dataset[i];
		v = (v * 3) + (v / 7) - (v % 11);
		if (v < 0)
			v = -v;
		dataset[i] = v;
	}
}

static unsigned long reduce_checksum(void)
{
	unsigned long sum;
	int i;

	sum = 0;
	for (i = 0; i < DATASET_SIZE; i++)
		sum = (sum * 131ul) + (unsigned long)dataset[i];

	return sum;
}

/* Converts a clock interval to seconds using CLOCKS_PER_SEC. */
static double elapsed_seconds(clock_t start, clock_t end)
{
	return ((double)(end - start) / (double)CLOCKS_PER_SEC);
}

int main(void)
{
	unsigned long checksum;
	clock_t total_start;
	clock_t total_end;
	clock_t start;
	clock_t end;
	double build_time;
	double process_time;
	double reduce_time;

	/* TOTAL boundary: from just before the first phase to just after the last */
	total_start = clock();

	/* Each phase is measured around its single function call only */
	start = clock();
	build_dataset();
	end = clock();
	build_time = elapsed_seconds(start, end);

	start = clock();
	process_dataset();
	end = clock();
	process_time = elapsed_seconds(start, end);

	start = clock();
	checksum = reduce_checksum();
	end = clock();
	reduce_time = elapsed_seconds(start, end);

	total_end = clock();

	if (checksum == 0ul)
		printf("impossible\n");

	printf("TOTAL seconds: %.6f\n", elapsed_seconds(total_start, total_end));
	printf("BUILD_DATA seconds: %.6f\n", build_time);
	printf("PROCESS seconds: %.6f\n", process_time);
	printf("REDUCE seconds: %.6f\n", reduce_time);

	return (0);
}
