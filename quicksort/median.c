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

int *median_three(int *left, int *right)
{
	int *mid = left + FIND_MID(right, left);

	if (*mid < *left) {
		if (*right < *left) {
			if (*right < *mid) {
				SWAP(left, right);
			} else {
				ROTATE(left, mid, right);
			}
		} else {
			SWAP(left, mid);
		}
	} else {
		if (*right < *mid) {
			if (*right < *left) {
				ROTATE(right, mid, left);
			} else {
				SWAP(mid, right);
			}
		}
	}

	return mid;
}

int *median_five_of_three(int *left, int *right)
{
	int half = FIND_MID(right, left);
	int quarter = half >> 1;
	int *t_first_quarter = left + quarter;
	int *t_mid = left + half;
	int *t_third_quarter = right - quarter;
	int *left_mid = median_three(left, t_mid);
	int *mid = median_three(t_first_quarter, t_third_quarter);
	int *right_mid = median_three(t_mid, right);

	if (*left_mid < *left)
		SWAP(left, left_mid);
	if (*right < *right_mid)
		SWAP(right_mid, right);
	if (*right_mid < *left)
		SWAP(left, right_mid);
	if (*right < *left_mid)
		SWAP(left_mid, right);
	if (*right_mid < *mid)
		SWAP(mid, right_mid);
	if (*mid < *left_mid)
		SWAP(left_mid, mid);
	if (*right_mid < *mid)
		SWAP(right_mid, mid);

	return mid;
}

int *median_five_of_fifteen(int *left, int *right)
{
	int half = FIND_MID(right, left);
	int quarter = half >> 1;
	int *t_first_quarter = left + quarter;
	int *t_mid = left + half;
	int *t_third_quarter = right - quarter;
	int *left_mid = median_five_of_three(left, t_mid);
	int *mid = median_five_of_three(t_first_quarter, t_third_quarter);
	int *right_mid = median_five_of_three(t_mid, right);

	if (*left_mid < *left)
		SWAP(left, left_mid);
	if (*right < *right_mid)
		SWAP(right_mid, right);
	if (*right_mid < *left)
		SWAP(left, right_mid);
	if (*right < *left_mid)
		SWAP(left_mid, right);
	if (*right_mid < *mid)
		SWAP(mid, right_mid);
	if (*mid < *left_mid)
		SWAP(left_mid, mid);
	if (*right_mid < *mid)
		SWAP(right_mid, mid);

	return mid;
}

int *median_three_r(int *left, int *right)
{
	int *mid = left + FIND_MID(right, left);

	if (*mid < *left) {
		if (*right < *left) {
			if (*right < *mid) {
				SWAP(left, right);
			} else {
				ROTATE(left, mid, right);
			}
		} else {
			SWAP(left, mid);
		}
	} else {
		if (*right < *mid) {
			if (*right < *left) {
				ROTATE(right, mid, left);
			} else {
				SWAP(mid, right);
			}
		}
	}

	SWAP(right, mid);

	return right;
}

int *median_five_of_three_r(int *left, int *right)
{
	int half = FIND_MID(right, left);
	int quarter = half >> 1;
	int *t_first_quarter = left + quarter;
	int *t_mid = left + half;
	int *t_third_quarter = right - quarter;
	int *left_mid = median_three(left, t_mid);
	int *mid = median_three(t_first_quarter, t_third_quarter);
	int *right_mid = median_three(t_mid, right);

	if (*left_mid < *left)
		SWAP(left, left_mid);
	if (*right < *right_mid)
		SWAP(right_mid, right);
	if (*right_mid < *left)
		SWAP(left, right_mid);
	if (*right < *left_mid)
		SWAP(left_mid, right);
	if (*right_mid < *mid)
		SWAP(mid, right_mid);
	if (*mid < *left_mid)
		SWAP(left_mid, mid);
	if (*right_mid < *mid)
		SWAP(right_mid, mid);

	SWAP(right, mid);

	return right;
}

int *median_five_of_fifteen_r(int *left, int *right)
{
	int half = FIND_MID(right, left);
	int quarter = half >> 1;
	int *t_first_quarter = left + quarter;
	int *t_mid = left + half;
	int *t_third_quarter = right - quarter;
	int *left_mid = median_five_of_three(left, t_mid);
	int *mid = median_five_of_three(t_first_quarter, t_third_quarter);
	int *right_mid = median_five_of_three(t_mid, right);

	if (*left_mid < *left)
		SWAP(left, left_mid);
	if (*right < *right_mid)
		SWAP(right_mid, right);
	if (*right_mid < *left)
		SWAP(left, right_mid);
	if (*right < *left_mid)
		SWAP(left_mid, right);
	if (*right_mid < *mid)
		SWAP(mid, right_mid);
	if (*mid < *left_mid)
		SWAP(left_mid, mid);
	if (*right_mid < *mid)
		SWAP(right_mid, mid);

	SWAP(right, mid);

	return right;
}