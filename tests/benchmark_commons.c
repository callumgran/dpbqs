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

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "benchmark_commons.h"

void fill_random(int *data, int len)
{
	for (int i = 0; i < len; i++)
		*(data + i) = (int)rand();
}

void fill_sorted(int *data, int len)
{
	for (int i = 0; i < len; i++)
		*(data + i) = i;
}

void fill_reverse_sorted(int *data, int len)
{
	for (int i = 0; i < len; i++)
		*(data + i) = len - i;
}

void fill_half_random(int *data, int len)
{
	int j = len >> 1;
	int k = len / 3;
	for (int i = 0; i < len; i++) {
		if (i % 2 == 0)
			*(data + i) = rand();
		else if (i % 3 == 0)
			*(data + i) = k;
		else
			*(data + i) = j;
	}
}

void fill_small_range(int *data, int len)
{
	for (int i = 0; i < len; i++)
		*(data + i) = rand() % 5;
}

void fill_sqrt(int *data, int len)
{
	int sqrt_len = sqrt(len);
	for (int i = 0; i < len; i++)
		*(data + i) = rand() % sqrt_len;
}

void fill_10_percent(int *data, int len)
{
	int ten_prc = len / 10;
	for (int i = 0; i < len; i++)
		*(data + i) = rand() % ten_prc;
}

bool test_sorted(int *data, int len)
{
	for (int i = 1; i < len; i++) {
		if (*(data + i) < *(data + i - 1)) {
			printf("Failed at index %d\n", i);
			return false;
		}
	}
	return true;
}

long long sum_array(int *data, int len)
{
	long long sum = 0;
	for (int i = 0; i < len; i++) {
		sum += *(data + i);
	}
	return sum;
}

void copy(int *data, int *copy, int len)
{
	for (int i = 0; i < len; i++) {
		*(copy + i) = *(data + i);
	}
}

bool test_values(long long sum1, long long sum2)
{
	return sum1 == sum2;
}