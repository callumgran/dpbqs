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

void insertion_sort(int *left, int *right)
{
	for (int *i = left + 1; i <= right; i++) {
		if (*i < *left) {
			SWAP(i, left);
		}
	}

	for (int *i = left + 2; i <= right; i++) {
		int high = *i;
		int *j = i - 1;
		while (high < *j) {
			*(j + 1) = *j;
			j--;
		}
		*(j + 1) = high;
	}
}