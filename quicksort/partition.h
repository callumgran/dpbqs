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
#ifndef PARTITION_H
#define PARTITION_H

#define BLOCK_SIZE 512
#define MEDIAN_OF_FIVE_OF_THREE_LIMIT 512
#define MEDIAN_OF_FIVE_OF_FIFTEEN_LIMIT 16384

void hoare_dc(int *left, int *right, int **pl, int **pr);

void hoare(int *left, int *right, int **p);

void lomuto(int *left, int *right, int **p);

void yaroslavskiy(int *left, int *right, int div);

void hoare_dc_blocked(int *left, int *right, int **pl, int **pr);

void hoare_blocked(int *left, int *right, int **p);

void lomuto_blocked(int *left, int *right, int **p);

void lomuto_dp_blocked(int *left, int *right, int **pl, int **pr);

void yaroslavskiy_blocked(int *left, int *right, int div);

#endif // PARTITION_H