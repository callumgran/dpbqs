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

#ifndef BENCHMARK_COMMONS_H
#define BENCHMARK_COMMONS_H

#include <stdlib.h>

void fill_random(int *data, int len);

void fill_sorted(int *data, int len);

void fill_reverse_sorted(int *data, int len);

void fill_half_random(int *data, int len);

void fill_small_range(int *data, int len);

void fill_sqrt(int *data, int len);

void fill_10_percent(int *data, int len);

bool test_sorted(int *data, int len);

long long sum_array(int *data, int len);

void copy(int *data, int *copy, int len);

bool test_values(long long sum1, long long sum2);

#endif // BENCHMARK_COMMONS_H