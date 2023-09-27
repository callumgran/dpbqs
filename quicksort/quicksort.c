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

#include "common.h"
#include "insertion.h"
#include "partition.h"

static void hoare_qs_dc_internal(int *left, int *right)
{
	if (right - left > RUN_INSERTION) {
		int *pr;
		int *pl;

		hoare_dc(left, right, &pl, &pr);
		hoare_qs_dc_internal(left, pl - 1);
		hoare_qs_dc_internal(pr + 1, right);
	} else {
		insertion_sort(left, right);
	}
}

void hoare_qs_dc(int *arr, int size)
{
	hoare_qs_dc_internal(arr, arr + size - 1);
}

static void hoare_qs_internal(int *left, int *right)
{
	if (right - left > RUN_INSERTION) {
		int *piv;

		hoare(left, right, &piv);
		hoare_qs_internal(left, piv - 1);
		hoare_qs_internal(piv + 1, right);
	} else {
		insertion_sort(left, right);
	}
}

void hoare_qs(int *arr, int size)
{
	hoare_qs_internal(arr, arr + size - 1);
}

static void lomuto_qs_internal(int *left, int *right)
{
	if (right - left > RUN_INSERTION) {
		int *piv;

		lomuto(left, right, &piv);
		lomuto_qs_internal(left, piv - 1);
		lomuto_qs_internal(piv + 1, right);
	} else {
		insertion_sort(left, right);
	}
}

void lomuto_qs(int *arr, int size)
{
	lomuto_qs_internal(arr, arr + size - 1);
}

void yaroslavskiy_qs(int *arr, int size)
{
	yaroslavskiy(arr, arr + size - 1, 3);
}

static void hoare_bqs_dc_internal(int *left, int *right)
{
	if (right - left > RUN_INSERTION) {
		int *pr;
		int *pl;

		hoare_dc_blocked(left, right, &pl, &pr);
		hoare_bqs_dc_internal(left, pl - 1);
		hoare_bqs_dc_internal(pr + 1, right);
	} else {
		insertion_sort(left, right);
	}
}

void hoare_dc_bqs(int *arr, int size)
{
	hoare_bqs_dc_internal(arr, arr + size - 1);
}

static void hoare_bqs_internal(int *left, int *right)
{
	if (right - left > RUN_INSERTION) {
		int *piv;

		hoare_blocked(left, right, &piv);
		hoare_bqs_internal(left, piv - 1);
		hoare_bqs_internal(piv + 1, right);
	} else {
		insertion_sort(left, right);
	}
}

void hoare_bqs(int *arr, int size)
{
	hoare_bqs_internal(arr, arr + size - 1);
}

static void lomuto_bqs_internal(int *left, int *right)
{
	if (right - left > RUN_INSERTION) {
		int *piv;

		lomuto_blocked(left, right, &piv);
		lomuto_bqs_internal(left, piv - 1);
		lomuto_bqs_internal(piv + 1, right);
	} else {
		insertion_sort(left, right);
	}
}

void lomuto_bqs(int *arr, int size)
{
	lomuto_bqs_internal(arr, arr + size - 1);
}

static void lomuto_dp_bqs_internal(int *left, int *right)
{
	if (right - left > RUN_INSERTION) {
		int *pr;
		int *pl;

		lomuto_dp_blocked(left, right, &pl, &pr);
		lomuto_dp_bqs_internal(left, pl - 1);
		lomuto_dp_bqs_internal(pl + 1, pr - 1);
		lomuto_dp_bqs_internal(pr + 1, right);
	} else {
		insertion_sort(left, right);
	}
}

void lomuto_dp_bqs(int *arr, int size)
{
	lomuto_dp_bqs_internal(arr, arr + size - 1);
}

void dp_bqs(int *arr, int size)
{
	yaroslavskiy_blocked(arr, arr + size - 1, 3);
}