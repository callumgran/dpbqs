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

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../quicksort/quicksort.h"
#include "benchmark_commons.h"

#define SIZE 100000

bool run_with_validation(int *arr, int size, void (*sort)(int *, int))
{
	bool valid = true;
	long long before = sum_array(arr, size);
	sort(arr, size);
	valid &= test_sorted(arr, size);
	long long after = sum_array(arr, size);
	valid &= test_values(before, after);
	return valid;
}

void test_function(int *arr, int size, void (*sort)(int *, int), char *func_name)
{
	int *copy_arr = malloc(sizeof(int) * size);
	copy(arr, copy_arr, SIZE);

	bool valid = run_with_validation(copy_arr, size, sort);
	printf("%s passes: %s\n", func_name, valid ? "true" : "false");

	free(copy_arr);
}

int main(void)
{
	srand(time(NULL));

	int *arr = malloc(sizeof(int) * SIZE);

	printf("------------------------------------------------------------\n");
	printf("Testing with random data\n");
	fill_random(arr, SIZE);

	test_function(arr, SIZE, hoare_qs_dc, "hoare_qs_dc");

	test_function(arr, SIZE, hoare_qs, "hoare_qs");

	test_function(arr, SIZE, lomuto_qs, "lomuto_qs");

	test_function(arr, SIZE, yaroslavskiy_qs, "yaroslavskiy");

	test_function(arr, SIZE, hoare_dc_bqs, "hoare_dc_bqs");

	test_function(arr, SIZE, hoare_bqs, "hoare_bqs");

	test_function(arr, SIZE, lomuto_bqs, "lomuto_bqs");

	test_function(arr, SIZE, lomuto_dp_bqs, "lomuto_dp_bqs");

	test_function(arr, SIZE, dp_bqs, "dp_bqs");
	printf("------------------------------------------------------------\n");

	printf("------------------------------------------------------------\n");
	printf("Testing with sorted data\n");
	fill_sorted(arr, SIZE);

	test_function(arr, SIZE, hoare_qs_dc, "hoare_qs_dc");

	test_function(arr, SIZE, hoare_qs, "hoare_qs");

	test_function(arr, SIZE, lomuto_qs, "lomuto_qs");

	test_function(arr, SIZE, yaroslavskiy_qs, "yaroslavskiy");

	test_function(arr, SIZE, hoare_dc_bqs, "hoare_dc_bqs");

	test_function(arr, SIZE, hoare_bqs, "hoare_bqs");

	test_function(arr, SIZE, lomuto_bqs, "lomuto_bqs");

	test_function(arr, SIZE, lomuto_dp_bqs, "lomuto_dp_bqs");

	test_function(arr, SIZE, dp_bqs, "dp_bqs");
	printf("------------------------------------------------------------\n");

	printf("------------------------------------------------------------\n");
	printf("Testing with reverse sorted data\n");
	fill_reverse_sorted(arr, SIZE);

	test_function(arr, SIZE, hoare_qs_dc, "hoare_qs_dc");

	test_function(arr, SIZE, hoare_qs, "hoare_qs");

	test_function(arr, SIZE, lomuto_qs, "lomuto_qs");

	test_function(arr, SIZE, yaroslavskiy_qs, "yaroslavskiy");

	test_function(arr, SIZE, hoare_dc_bqs, "hoare_dc_bqs");

	test_function(arr, SIZE, hoare_bqs, "hoare_bqs");

	test_function(arr, SIZE, lomuto_bqs, "lomuto_bqs");

	test_function(arr, SIZE, lomuto_dp_bqs, "lomuto_dp_bqs");

	test_function(arr, SIZE, dp_bqs, "dp_bqs");
	printf("------------------------------------------------------------\n");

	printf("------------------------------------------------------------\n");
	printf("Testing with half-duplicate data\n");
	fill_half_random(arr, SIZE);

	test_function(arr, SIZE, hoare_qs_dc, "hoare_qs_dc");

	test_function(arr, SIZE, hoare_qs, "hoare_qs");

	test_function(arr, SIZE, lomuto_qs, "lomuto_qs");

	test_function(arr, SIZE, yaroslavskiy_qs, "yaroslavskiy");

	test_function(arr, SIZE, hoare_dc_bqs, "hoare_dc_bqs");

	test_function(arr, SIZE, hoare_bqs, "hoare_bqs");

	test_function(arr, SIZE, lomuto_bqs, "lomuto_bqs");

	test_function(arr, SIZE, lomuto_dp_bqs, "lomuto_dp_bqs");

	test_function(arr, SIZE, dp_bqs, "dp_bqs");
	printf("------------------------------------------------------------\n");

	printf("------------------------------------------------------------\n");
	printf("Testing with small range data\n");
	fill_half_random(arr, SIZE);

	test_function(arr, SIZE, hoare_qs_dc, "hoare_qs_dc");

	test_function(arr, SIZE, hoare_qs, "hoare_qs");

	test_function(arr, SIZE, lomuto_qs, "lomuto_qs");

	test_function(arr, SIZE, yaroslavskiy_qs, "yaroslavskiy");

	test_function(arr, SIZE, hoare_dc_bqs, "hoare_dc_bqs");

	test_function(arr, SIZE, hoare_bqs, "hoare_bqs");

	test_function(arr, SIZE, lomuto_bqs, "lomuto_bqs");

	test_function(arr, SIZE, lomuto_dp_bqs, "lomuto_dp_bqs");

	test_function(arr, SIZE, dp_bqs, "dp_bqs");
	printf("------------------------------------------------------------\n");

	free(arr);
	return 0;
}