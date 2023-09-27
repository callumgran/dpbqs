/*
 *  Copyright (C) 2023 Callum Gran
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../quicksort/quicksort.h"
#include "benchmark_commons.h"

#define SIZE (3000000)

double hoare_qs_dc_with_time_ret(int *data)
{
	struct timespec start, end;
	double elapsed = 0;
	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	hoare_qs_dc(data, SIZE);
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	elapsed += (end.tv_sec - start.tv_sec);
	elapsed += (end.tv_nsec - start.tv_nsec) / 1000000000.0;
	elapsed *= 1000;
	return elapsed;
}

double hoare_qs_with_time_ret(int *data)
{
	struct timespec start, end;
	double elapsed = 0;
	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	hoare_qs(data, SIZE);
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	elapsed += (end.tv_sec - start.tv_sec);
	elapsed += (end.tv_nsec - start.tv_nsec) / 1000000000.0;
	elapsed *= 1000;
	return elapsed;
}

double lomuto_qs_with_time_ret(int *data)
{
	struct timespec start, end;
	double elapsed = 0;
	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	lomuto_qs(data, SIZE);
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	elapsed += (end.tv_sec - start.tv_sec);
	elapsed += (end.tv_nsec - start.tv_nsec) / 1000000000.0;
	elapsed *= 1000;
	return elapsed;
}

double yaroslavskiy_with_time_ret(int *data)
{
	struct timespec start, end;
	double elapsed = 0;
	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	yaroslavskiy_qs(data, SIZE);
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	elapsed += (end.tv_sec - start.tv_sec);
	elapsed += (end.tv_nsec - start.tv_nsec) / 1000000000.0;
	elapsed *= 1000;
	return elapsed;
}

double hoare_dc_bqs_with_time_ret(int *data)
{
	struct timespec start, end;
	double elapsed = 0;
	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	hoare_dc_bqs(data, SIZE);
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	elapsed += (end.tv_sec - start.tv_sec);
	elapsed += (end.tv_nsec - start.tv_nsec) / 1000000000.0;
	elapsed *= 1000;
	return elapsed;
}

double hoare_bqs_with_time_ret(int *data)
{
	struct timespec start, end;
	double elapsed = 0;
	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	hoare_bqs(data, SIZE);
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	elapsed += (end.tv_sec - start.tv_sec);
	elapsed += (end.tv_nsec - start.tv_nsec) / 1000000000.0;
	elapsed *= 1000;
	return elapsed;
}

double lomuto_bqs_with_time_ret(int *data)
{
	struct timespec start, end;
	double elapsed = 0;
	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	lomuto_bqs(data, SIZE);
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	elapsed += (end.tv_sec - start.tv_sec);
	elapsed += (end.tv_nsec - start.tv_nsec) / 1000000000.0;
	elapsed *= 1000;
	return elapsed;
}

double lomuto_dp_bqs_with_time_ret(int *data)
{
	struct timespec start, end;
	double elapsed = 0;
	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	lomuto_dp_bqs(data, SIZE);
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	elapsed += (end.tv_sec - start.tv_sec);
	elapsed += (end.tv_nsec - start.tv_nsec) / 1000000000.0;
	elapsed *= 1000;
	return elapsed;
}

double dp_bqs_with_time_ret(int *data)
{
	struct timespec start, end;
	double elapsed = 0;
	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	dp_bqs(data, SIZE);
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	elapsed += (end.tv_sec - start.tv_sec);
	elapsed += (end.tv_nsec - start.tv_nsec) / 1000000000.0;
	elapsed *= 1000;
	return elapsed;
}

int main()
{
	srand(time(NULL));
	int *data = (int *)(malloc(SIZE * sizeof(int)));
	int *copy_arr = (int *)(malloc(SIZE * sizeof(int)));
	double elapsed_hoare_dc = 0;
	double elapsed_hoare = 0;
	double elapsed_lomuto = 0;
	double elapsed_yaroslavskiy = 0;
	double elapsed_hoare_dc_b = 0;
	double elapsed_hoare_b = 0;
	double elapsed_lomuto_b = 0;
	double elapsed_lomuto_dp_b = 0;
	double elapsed_dp_b = 0;

	printf("--------------------------------------------------------\n");
	printf("Random Numbers: %d million. \n\n", SIZE / 1000000);

	for (int i = 0; i < 10; i++) {
		fill_random(data, SIZE);

		copy(data, copy_arr, SIZE);
		elapsed_hoare_dc += hoare_qs_dc_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_hoare += hoare_qs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_lomuto += lomuto_qs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_yaroslavskiy += yaroslavskiy_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_hoare_dc_b += hoare_dc_bqs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_hoare_b += hoare_bqs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_lomuto_b += lomuto_bqs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_lomuto_dp_b += lomuto_dp_bqs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_dp_b += dp_bqs_with_time_ret(copy_arr);
	}
	elapsed_hoare_dc /= 10;
	elapsed_hoare /= 10;
	elapsed_lomuto /= 10;
	elapsed_yaroslavskiy /= 10;
	elapsed_hoare_dc_b /= 10;
	elapsed_hoare_b /= 10;
	elapsed_lomuto_b /= 10;
	elapsed_lomuto_dp_b /= 10;
	elapsed_dp_b /= 10;

	printf("Average time taken for hoare with duplicate checking was: %fms\n", elapsed_hoare_dc);
	printf("Average time taken for hoare was: %fms\n", elapsed_hoare);
	printf("Average time taken for lomuto was: %fms\n", elapsed_lomuto);
	printf("Average time taken for yaroslavskiy was: %fms\n", elapsed_yaroslavskiy);
	printf(
		"Average time taken for hoare with duplicate checking and block partitioning was: %fms\n",
		elapsed_hoare_dc_b);
	printf("Average time taken for hoare with block partitioning was: %fms\n", elapsed_hoare_b);
	printf("Average time taken for lomuto with block partitioning was: %fms\n", elapsed_lomuto_b);
	printf("Average time taken for lomuto with dual pivot and block partitioning was: %fms\n",
		   elapsed_lomuto_dp_b);
	printf("Average time taken for my dual pivot block partitioning was: %fms\n", elapsed_dp_b);

	printf("--------------------------------------------------------\n");
	elapsed_hoare_dc = 0;
	elapsed_hoare = 0;
	elapsed_lomuto = 0;
	elapsed_yaroslavskiy = 0;
	elapsed_hoare_dc_b = 0;
	elapsed_hoare_b = 0;
	elapsed_lomuto_b = 0;
	elapsed_lomuto_dp_b = 0;
	elapsed_dp_b = 0;
	printf("--------------------------------------------------------\n");
	printf("Sqrt(%d) range Numbers: %d million. \n\n", SIZE, SIZE / 1000000);

	for (int i = 0; i < 10; i++) {
		fill_sqrt(data, SIZE);

		copy(data, copy_arr, SIZE);
		elapsed_hoare_dc += hoare_qs_dc_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_hoare += hoare_qs_with_time_ret(copy_arr);

		// copy(data, copy_arr, SIZE);
		// elapsed_lomuto += lomuto_qs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_yaroslavskiy += yaroslavskiy_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_hoare_dc_b += hoare_dc_bqs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_hoare_b += hoare_bqs_with_time_ret(copy_arr);

		// copy(data, copy_arr, SIZE);
		// elapsed_lomuto_b += lomuto_bqs_with_time_ret(copy_arr);

		// copy(data, copy_arr, SIZE);
		// elapsed_lomuto_dp_b += lomuto_dp_bqs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_dp_b += dp_bqs_with_time_ret(copy_arr);
	}
	elapsed_hoare_dc /= 10;
	elapsed_hoare /= 10;
	elapsed_lomuto /= 10;
	elapsed_yaroslavskiy /= 10;
	elapsed_hoare_dc_b /= 10;
	elapsed_hoare_b /= 10;
	elapsed_lomuto_b /= 10;
	elapsed_lomuto_dp_b /= 10;
	elapsed_dp_b /= 10;

	printf("Average time taken for hoare with duplicate checking was: %fms\n", elapsed_hoare_dc);
	printf("Average time taken for hoare was: %fms\n", elapsed_hoare);
	// printf("Average time taken for lomuto was: %fms\n", elapsed_lomuto);
	printf("Average time taken for yaroslavskiy was: %fms\n", elapsed_yaroslavskiy);
	printf(
		"Average time taken for hoare with duplicate checking and block partitioning was: %fms\n",
		elapsed_hoare_dc_b);
	printf("Average time taken for hoare with block partitioning was: %fms\n", elapsed_hoare_b);
	// printf("Average time taken for lomuto with block partitioning was: %fms\n",
	// elapsed_lomuto_b); printf("Average time taken for lomuto with dual pivot and block
	// partitioning was: %fms\n", elapsed_lomuto_dp_b);
	printf("Average time taken for my dual pivot block partitioning was: %fms\n", elapsed_dp_b);

	printf("--------------------------------------------------------\n\n");
	elapsed_hoare_dc = 0;
	elapsed_hoare = 0;
	elapsed_lomuto = 0;
	elapsed_yaroslavskiy = 0;
	elapsed_hoare_dc_b = 0;
	elapsed_hoare_b = 0;
	elapsed_lomuto_b = 0;
	elapsed_lomuto_dp_b = 0;
	elapsed_dp_b = 0;
	printf("--------------------------------------------------------\n");
	printf("10 %% of %d range Numbers: %d million. \n\n", SIZE, SIZE / 1000000);
	for (int i = 0; i < 10; i++) {
		fill_10_percent(data, SIZE);

		copy(data, copy_arr, SIZE);
		elapsed_hoare_dc += hoare_qs_dc_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_hoare += hoare_qs_with_time_ret(copy_arr);

		// copy(data, copy_arr, SIZE);
		// elapsed_lomuto += lomuto_qs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_yaroslavskiy += yaroslavskiy_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_hoare_dc_b += hoare_dc_bqs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_hoare_b += hoare_bqs_with_time_ret(copy_arr);

		// copy(data, copy_arr, SIZE);
		// elapsed_lomuto_b += lomuto_bqs_with_time_ret(copy_arr);

		// copy(data, copy_arr, SIZE);
		// elapsed_lomuto_dp_b += lomuto_dp_bqs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_dp_b += dp_bqs_with_time_ret(copy_arr);
	}
	elapsed_hoare_dc /= 10;
	elapsed_hoare /= 10;
	elapsed_lomuto /= 10;
	elapsed_yaroslavskiy /= 10;
	elapsed_hoare_dc_b /= 10;
	elapsed_hoare_b /= 10;
	elapsed_lomuto_b /= 10;
	elapsed_lomuto_dp_b /= 10;
	elapsed_dp_b /= 10;

	printf("Average time taken for hoare with duplicate checking was: %fms\n", elapsed_hoare_dc);
	printf("Average time taken for hoare was: %fms\n", elapsed_hoare);
	// printf("Average time taken for lomuto was: %fms\n", elapsed_lomuto);
	printf("Average time taken for yaroslavskiy was: %fms\n", elapsed_yaroslavskiy);
	printf(
		"Average time taken for hoare with duplicate checking and block partitioning was: %fms\n",
		elapsed_hoare_dc_b);
	printf("Average time taken for hoare with block partitioning was: %fms\n", elapsed_hoare_b);
	// printf("Average time taken for lomuto with block partitioning was: %fms\n",
	// elapsed_lomuto_b); printf("Average time taken for lomuto with dual pivot and block
	// partitioning was: %fms\n", elapsed_lomuto_dp_b);
	printf("Average time taken for my dual pivot block partitioning was: %fms\n", elapsed_dp_b);

	printf("--------------------------------------------------------\n\n");
	elapsed_hoare_dc = 0;
	elapsed_hoare = 0;
	elapsed_lomuto = 0;
	elapsed_yaroslavskiy = 0;
	elapsed_hoare_dc_b = 0;
	elapsed_hoare_b = 0;
	elapsed_lomuto_b = 0;
	elapsed_lomuto_dp_b = 0;
	elapsed_dp_b = 0;
	printf("--------------------------------------------------------\n");
	printf("Sorted Numbers: %d million. \n\n", SIZE / 1000000);
	for (int i = 0; i < 10; i++) {
		fill_sorted(data, SIZE);

		copy(data, copy_arr, SIZE);
		elapsed_hoare_dc += hoare_qs_dc_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_hoare += hoare_qs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_lomuto += lomuto_qs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_yaroslavskiy += yaroslavskiy_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_hoare_dc_b += hoare_dc_bqs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_hoare_b += hoare_bqs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_lomuto_b += lomuto_bqs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_lomuto_dp_b += lomuto_dp_bqs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_dp_b += dp_bqs_with_time_ret(copy_arr);
	}
	elapsed_hoare_dc /= 10;
	elapsed_hoare /= 10;
	elapsed_lomuto /= 10;
	elapsed_yaroslavskiy /= 10;
	elapsed_hoare_dc_b /= 10;
	elapsed_hoare_b /= 10;
	elapsed_lomuto_b /= 10;
	elapsed_lomuto_dp_b /= 10;
	elapsed_dp_b /= 10;

	printf("Average time taken for hoare with duplicate checking was: %fms\n", elapsed_hoare_dc);
	printf("Average time taken for hoare was: %fms\n", elapsed_hoare);
	printf("Average time taken for lomuto was: %fms\n", elapsed_lomuto);
	printf("Average time taken for yaroslavskiy was: %fms\n", elapsed_yaroslavskiy);
	printf(
		"Average time taken for hoare with duplicate checking and block partitioning was: %fms\n",
		elapsed_hoare_dc_b);
	printf("Average time taken for hoare with block partitioning was: %fms\n", elapsed_hoare_b);
	printf("Average time taken for lomuto with block partitioning was: %fms\n", elapsed_lomuto_b);
	printf("Average time taken for lomuto with dual pivot and block partitioning was: %fms\n",
		   elapsed_lomuto_dp_b);
	printf("Average time taken for my dual pivot block partitioning was: %fms\n", elapsed_dp_b);


	printf("--------------------------------------------------------\n\n");
	elapsed_hoare_dc = 0;
	elapsed_hoare = 0;
	elapsed_lomuto = 0;
	elapsed_yaroslavskiy = 0;
	elapsed_hoare_dc_b = 0;
	elapsed_hoare_b = 0;
	elapsed_lomuto_b = 0;
	elapsed_lomuto_dp_b = 0;
	elapsed_dp_b = 0;
	printf("--------------------------------------------------------\n");
	printf("Reverse sorted Numbers: %d million. \n\n", SIZE / 1000000);
	for (int i = 0; i < 10; i++) {
		fill_reverse_sorted(data, SIZE);

		copy(data, copy_arr, SIZE);
		elapsed_hoare_dc += hoare_qs_dc_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_hoare += hoare_qs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_lomuto += lomuto_qs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_yaroslavskiy += yaroslavskiy_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_hoare_dc_b += hoare_dc_bqs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_hoare_b += hoare_bqs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_lomuto_b += lomuto_bqs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_lomuto_dp_b += lomuto_dp_bqs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_dp_b += dp_bqs_with_time_ret(copy_arr);
	}
	elapsed_hoare_dc /= 10;
	elapsed_hoare /= 10;
	elapsed_lomuto /= 10;
	elapsed_yaroslavskiy /= 10;
	elapsed_hoare_dc_b /= 10;
	elapsed_hoare_b /= 10;
	elapsed_lomuto_b /= 10;
	elapsed_lomuto_dp_b /= 10;
	elapsed_dp_b /= 10;

	printf("Average time taken for hoare with duplicate checking was: %fms\n", elapsed_hoare_dc);
	printf("Average time taken for hoare was: %fms\n", elapsed_hoare);
	printf("Average time taken for lomuto was: %fms\n", elapsed_lomuto);
	printf("Average time taken for yaroslavskiy was: %fms\n", elapsed_yaroslavskiy);
	printf(
		"Average time taken for hoare with duplicate checking and block partitioning was: %fms\n",
		elapsed_hoare_dc_b);
	printf("Average time taken for hoare with block partitioning was: %fms\n", elapsed_hoare_b);
	printf("Average time taken for lomuto with block partitioning was: %fms\n", elapsed_lomuto_b);
	printf("Average time taken for lomuto with dual pivot and block partitioning was: %fms\n",
		   elapsed_lomuto_dp_b);
	printf("Average time taken for my dual pivot block partitioning was: %fms\n", elapsed_dp_b);

	printf("--------------------------------------------------------\n\n");
	elapsed_hoare_dc = 0;
	elapsed_hoare = 0;
	elapsed_lomuto = 0;
	elapsed_yaroslavskiy = 0;
	elapsed_hoare_dc_b = 0;
	elapsed_hoare_b = 0;
	elapsed_lomuto_b = 0;
	elapsed_lomuto_dp_b = 0;
	elapsed_dp_b = 0;
	printf("--------------------------------------------------------\n");
	printf("Half random Numbers: %d million. \n\n", SIZE / 1000000);
	for (int i = 0; i < 10; i++) {
		fill_half_random(data, SIZE);

		copy(data, copy_arr, SIZE);
		elapsed_hoare_dc += hoare_qs_dc_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_hoare += hoare_qs_with_time_ret(copy_arr);

		// copy(data, copy_arr, SIZE);
		// elapsed_lomuto += lomuto_qs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_yaroslavskiy += yaroslavskiy_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_hoare_dc_b += hoare_dc_bqs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_hoare_b += hoare_bqs_with_time_ret(copy_arr);

		// copy(data, copy_arr, SIZE);
		// elapsed_lomuto_b += lomuto_bqs_with_time_ret(copy_arr);

		// copy(data, copy_arr, SIZE);
		// elapsed_lomuto_dp_b += lomuto_dp_bqs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_dp_b += dp_bqs_with_time_ret(copy_arr);
	}
	elapsed_hoare_dc /= 10;
	elapsed_hoare /= 10;
	elapsed_lomuto /= 10;
	elapsed_yaroslavskiy /= 10;
	elapsed_hoare_dc_b /= 10;
	elapsed_hoare_b /= 10;
	elapsed_lomuto_b /= 10;
	elapsed_lomuto_dp_b /= 10;
	elapsed_dp_b /= 10;

	printf("Average time taken for hoare with duplicate checking was: %fms\n", elapsed_hoare_dc);
	printf("Average time taken for hoare was: %fms\n", elapsed_hoare);
	// printf("Average time taken for lomuto was: %fms\n", elapsed_lomuto);
	printf("Average time taken for yaroslavskiy was: %fms\n", elapsed_yaroslavskiy);
	printf(
		"Average time taken for hoare with duplicate checking and block partitioning was: %fms\n",
		elapsed_hoare_dc_b);
	printf("Average time taken for hoare with block partitioning was: %fms\n", elapsed_hoare_b);
	// printf("Average time taken for lomuto with block partitioning was: %fms\n",
	// elapsed_lomuto_b); printf("Average time taken for lomuto with dual pivot and block
	// partitioning was: %fms\n", elapsed_lomuto_dp_b);
	printf("Average time taken for my dual pivot block partitioning was: %fms\n", elapsed_dp_b);

	printf("--------------------------------------------------------\n\n");
	elapsed_hoare_dc = 0;
	elapsed_hoare = 0;
	elapsed_lomuto = 0;
	elapsed_yaroslavskiy = 0;
	elapsed_hoare_dc_b = 0;
	elapsed_hoare_b = 0;
	elapsed_lomuto_b = 0;
	elapsed_lomuto_dp_b = 0;
	elapsed_dp_b = 0;
	printf("--------------------------------------------------------\n");
	printf("Low range Numbers: %d million. \n\n", SIZE / 1000000);
	for (int i = 0; i < 10; i++) {
		fill_small_range(data, SIZE);

		copy(data, copy_arr, SIZE);
		elapsed_hoare_dc += hoare_qs_dc_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_hoare += hoare_qs_with_time_ret(copy_arr);

		// copy(data, copy_arr, SIZE);
		// elapsed_lomuto += lomuto_qs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_yaroslavskiy += yaroslavskiy_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_hoare_dc_b += hoare_dc_bqs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_hoare_b += hoare_bqs_with_time_ret(copy_arr);

		// copy(data, copy_arr, SIZE);
		// elapsed_lomuto_b += lomuto_bqs_with_time_ret(copy_arr);

		// copy(data, copy_arr, SIZE);
		// elapsed_lomuto_dp_b += lomuto_dp_bqs_with_time_ret(copy_arr);

		copy(data, copy_arr, SIZE);
		elapsed_dp_b += dp_bqs_with_time_ret(copy_arr);
	}
	elapsed_hoare_dc /= 10;
	elapsed_hoare /= 10;
	elapsed_lomuto /= 10;
	elapsed_yaroslavskiy /= 10;
	elapsed_hoare_dc_b /= 10;
	elapsed_hoare_b /= 10;
	elapsed_lomuto_b /= 10;
	elapsed_lomuto_dp_b /= 10;
	elapsed_dp_b /= 10;

	printf("Average time taken for hoare with duplicate checking was: %fms\n", elapsed_hoare_dc);
	printf("Average time taken for hoare was: %fms\n", elapsed_hoare);
	// printf("Average time taken for lomuto was: %fms\n", elapsed_lomuto);
	printf("Average time taken for yaroslavskiy was: %fms\n", elapsed_yaroslavskiy);
	printf(
		"Average time taken for hoare with duplicate checking and block partitioning was: %fms\n",
		elapsed_hoare_dc_b);
	printf("Average time taken for hoare with block partitioning was: %fms\n", elapsed_hoare_b);
	// printf("Average time taken for lomuto with block partitioning was: %fms\n",
	// elapsed_lomuto_b); printf("Average time taken for lomuto with dual pivot and block
	// partitioning was: %fms\n", elapsed_lomuto_dp_b);
	printf("Average time taken for my dual pivot block partitioning was: %fms\n", elapsed_dp_b);
	printf("--------------------------------------------------------\n\n");

	free(data);
	free(copy_arr);

	return 0;
}