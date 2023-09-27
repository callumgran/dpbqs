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

#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define SWAP(a, b)                 \
	do {                           \
		register int __tmp = *(a); \
		*(a) = *(b);               \
		*(b) = __tmp;              \
	} while (0)

#define ROTATE(a, b, c)            \
	do {                           \
		register int __tmp = *(a); \
		*(a) = *(b);               \
		*(b) = *(c);               \
		*(c) = __tmp;              \
	} while (0)

#define FIND_MID(high, low) (((high) - (low)) >> 1)

#define FIND_FIRST_QUART(high, low) (((high) - (low)) >> 2)

#define FIND_THIRD_QUART(high, low) ((3 * ((high) - (low))) >> 2)

#define FIND_DIV(high, low, div) (((high) - (low)) / (div))

#define RUN_INSERTION 27

#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#endif // COMMON_H