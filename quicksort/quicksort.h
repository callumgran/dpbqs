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
#ifndef QUICKSORT_H
#define QUICKSORT_H

void hoare_qs_dc(int *arr, int size);

void hoare_qs(int *arr, int size);

void lomuto_qs(int *arr, int size);

void yaroslavskiy_qs(int *arr, int size);

void hoare_dc_bqs(int *arr, int size);

void hoare_bqs(int *arr, int size);

void lomuto_bqs(int *arr, int size);

void lomuto_dp_bqs(int *arr, int size);

void dp_bqs(int *arr, int size);

#endif // QUICKSORT_H