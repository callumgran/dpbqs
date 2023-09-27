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
#include <stddef.h>
#include <stdio.h>

#include "common.h"
#include "insertion.h"
#include "median.h"
#include "partition.h"

void hoare_dc(int *left, int *right, int **pl, int **pr)
{
	int *l = left + 1;
	int *r = right;

	ptrdiff_t diff = right - left;

	int *mid;

	if (diff > MEDIAN_OF_FIVE_OF_FIFTEEN_LIMIT) {
		mid = median_five_of_fifteen(left, right);
	} else if (diff > MEDIAN_OF_FIVE_OF_THREE_LIMIT) {
		mid = median_five_of_three(left, right);
	} else {
		mid = median_three(left, right);
	}

	const int piv = *mid;
	*mid = *l;
	*l = piv;
	SWAP(mid, right - 1);

	do {
		do {
			l++;
		} while (*l < piv);

		do {
			r--;
		} while (piv < *r);

		if (l >= r) {
			break;
		}

		SWAP(l, r);
	} while (true);

	*pl = l;

	if ((right - r) >= 1024) {
		int k = 0;
		int *pd = r + 1;
		while (k != 4 && pd != right) {
			if (piv == *pd) {
				k = 0;
				r++;
				SWAP(pd, r);
			}
			k++;
			pd++;
		}
	}

	*(left + 1) = *r;
	*r = piv;

	*pr = r;
}

void hoare(int *left, int *right, int **p)
{
	int *l = left + 1;
	int *r = right;

	ptrdiff_t diff = right - left;

	int *mid;

	if (diff > MEDIAN_OF_FIVE_OF_FIFTEEN_LIMIT) {
		mid = median_five_of_fifteen(left, right);
	} else if (diff > MEDIAN_OF_FIVE_OF_THREE_LIMIT) {
		mid = median_five_of_three(left, right);
	} else {
		mid = median_three(left, right);
	}

	const int piv = *mid;
	*mid = *l;
	*l = piv;
	SWAP(mid, right - 1);

	do {
		do {
			l++;
		} while (*l < piv);

		do {
			r--;
		} while (piv < *r);

		if (l >= r) {
			break;
		}

		SWAP(l, r);
	} while (true);

	*(left + 1) = *r;
	*r = piv;
	*p = r;
}

void lomuto(int *left, int *right, int **p)
{
	ptrdiff_t diff = right - left;

	int *piv;

	if (diff > MEDIAN_OF_FIVE_OF_FIFTEEN_LIMIT) {
		piv = median_five_of_fifteen_r(left, right);
	} else if (diff > MEDIAN_OF_FIVE_OF_THREE_LIMIT) {
		piv = median_five_of_three_r(left, right);
	} else {
		piv = median_three_r(left, right);
	}

	int pivot = *piv;
	int *i = left;

	for (int *j = left; j < right; j++) {
		if (*j < pivot) {
			SWAP(i, j);
			i++;
		}
	}

	SWAP(i, right);

	*p = i;
}

void yaroslavskiy(int *left, int *right, int div)
{
	const ptrdiff_t diff = right - left;

	if (diff < RUN_INSERTION) {
		insertion_sort(left, right);
	} else {
		int third = FIND_DIV(right, left, div);

		int *f_third = left + third;
		int *s_third = right - third;

		int *f_med;
		int *s_med;

		if (diff > MEDIAN_OF_FIVE_OF_FIFTEEN_LIMIT) {
			f_med = median_five_of_fifteen(left, s_third);
			s_med = median_five_of_fifteen(f_third, right);
		} else if (diff > MEDIAN_OF_FIVE_OF_THREE_LIMIT) {
			f_med = median_five_of_three(left, s_third);
			s_med = median_five_of_three(f_third, right);
		} else {
			f_med = median_three(left, s_third);
			s_med = median_three(f_third, right);
		}

		if (*f_med < *s_med) {
			SWAP(f_med, left);
			SWAP(s_med, right);
		} else {
			SWAP(f_med, right);
			SWAP(s_med, left);
		}

		int f_piv = *left;
		int s_piv = *right;

		int *l = left + 1;
		int *r = right - 1;

		for (int *i = l; i <= r; i++) {
			if (*i < f_piv) {
				SWAP(i, l);
				l++;
			} else if (*i > s_piv) {
				while (i<r && * r> s_piv) {
					r--;
				}

				if (*r < f_piv) {
					ROTATE(r, i, l);
					l++;
				} else {
					SWAP(i, r);
				}
				r--;
			}
		}

		const ptrdiff_t dist = r - l;

		div += dist < 13;

		SWAP(left, l - 1);
		SWAP(right, r + 1);

		yaroslavskiy(left, l - 2, div);
		yaroslavskiy(r + 2, right, div);

		if (f_piv != s_piv && dist > (diff - 13)) {
			for (int *i = l; i <= r; i++) {
				if (*i == f_piv) {
					SWAP(i, l);
					l++;
				} else if (*i == s_piv) {
					if (*r == f_piv) {
						ROTATE(r, i, l);
						l++;
					} else {
						SWAP(i, r);
					}
					r--;
				}
			}
		}

		if (f_piv < s_piv) {
			yaroslavskiy(l, r, div);
		}
	}
}

void hoare_dc_blocked(int *left, int *right, int **pl, int **pr)
{
	int *l;
	int *r;

	ptrdiff_t diff = right - left;

	int *mid;

	if (diff > MEDIAN_OF_FIVE_OF_FIFTEEN_LIMIT) {
		mid = median_five_of_fifteen(left, right);
	} else if (diff > MEDIAN_OF_FIVE_OF_THREE_LIMIT) {
		mid = median_five_of_three(left, right);
	} else {
		mid = median_three(left, right);
	}

	const int piv = *mid;
	*mid = *(left + 1);
	*(left + 1) = piv;
	SWAP(mid, right - 1);

	if (right - left > 2 * BLOCK_SIZE + 1) {
		l = left + 2;
		r = right - 1;

		int *offset_l[BLOCK_SIZE];
		int *offset_r[BLOCK_SIZE];

		int **num_left = offset_l;
		int **num_right = offset_r;

		do {
			int *l_lim = l + BLOCK_SIZE;
			if (num_left == offset_l) {
				int *pd = l;
				do {
					*num_left = pd;
					num_left += piv <= *pd;
					pd++;
				} while (pd != l_lim);
			}

			int *r_lim = r - BLOCK_SIZE;
			if (num_right == offset_r) {
				int *pd = r;
				do {
					*num_right = pd;
					num_right += piv >= *pd;
					pd--;
				} while (pd != r_lim);
			}

			const int min = MIN(num_left - offset_l, num_right - offset_r);
            if (min == 0)
                break;

			num_left -= min;
			num_right -= min;

			for (int i = 0; i < min; i++)
				SWAP(num_left[i], num_right[i]);

			l += (num_left == offset_l) * BLOCK_SIZE;
			r -= (num_right == offset_r) * BLOCK_SIZE;

		} while (r - l > 2 * BLOCK_SIZE + 1);

		l--;
		r++;
	} else {
		l = left + 1;
		r = right;
	}

	do {
		do {
			l++;
		} while (*l < piv);

		do {
			r--;
		} while (piv < *r);

		if (l >= r) {
			break;
		}

		SWAP(l, r);
	} while (true);

	*pl = l;

	if ((right - r) >= 1024) {
		int k = 0;
		int *pd = r + 1;
		while (k != 4 && pd != right) {
			if (piv == *pd) {
				k = 0;
				r++;
				SWAP(pd, r);
			}
			k++;
			pd++;
		}
	}

	*(left + 1) = *r;
	*r = piv;

	*pr = r;
}

void hoare_blocked(int *left, int *right, int **p)
{
	int *l;
	int *r;

	ptrdiff_t diff = right - left;

	int *mid;

	if (diff > MEDIAN_OF_FIVE_OF_FIFTEEN_LIMIT) {
		mid = median_five_of_fifteen(left, right);
	} else if (diff > MEDIAN_OF_FIVE_OF_THREE_LIMIT) {
		mid = median_five_of_three(left, right);
	} else {
		mid = median_three(left, right);
	}

	const int piv = *mid;
	*mid = *(left + 1);
	*(left + 1) = piv;
	SWAP(mid, right - 1);

	if (right - left > 2 * BLOCK_SIZE + 1) {
		l = left + 2;
		r = right;

		int *offset_l[BLOCK_SIZE];
		int *offset_r[BLOCK_SIZE];

		int **num_left = offset_l;
		int **num_right = offset_r;

		do {
			int *l_lim = l + BLOCK_SIZE;
			if (num_left == offset_l) {
				int *pd = l;
				do {
					*num_left = pd;
					num_left += piv <= *pd;
					pd++;
				} while (pd != l_lim);
			}

			int *r_lim = r - BLOCK_SIZE;
			if (num_right == offset_r) {
				int *pd = r;
				do {
					*num_right = pd;
					num_right += piv >= *pd;
					pd--;
				} while (pd != r_lim);
			}

			const int min = MIN(num_left - offset_l, num_right - offset_r);
            if (min == 0)
                break;

			num_left -= min;
			num_right -= min;

			for (int i = 0; i < min; i++)
				SWAP(num_left[i], num_right[i]);

			l += (num_left == offset_l) * BLOCK_SIZE;
			r -= (num_right == offset_r) * BLOCK_SIZE;

		} while (r - l > 2 * BLOCK_SIZE + 1);

		l--;
		r++;
	} else {
		l = left + 1;
		r = right;
	}

	do {
		do {
			l++;
		} while (*l < piv);

		do {
			r--;
		} while (piv < *r);

		if (l >= r) {
			break;
		}

		SWAP(l, r);
	} while (true);

	*(left + 1) = *r;
	*r = piv;
	*p = r;
}

void lomuto_blocked(int *left, int *right, int **p)
{
	ptrdiff_t diff = right - left;

	int *piv;

	if (diff > MEDIAN_OF_FIVE_OF_FIFTEEN_LIMIT) {
		piv = median_five_of_fifteen_r(left, right);
	} else if (diff > MEDIAN_OF_FIVE_OF_THREE_LIMIT) {
		piv = median_five_of_three_r(left, right);
	} else {
		piv = median_three_r(left, right);
	}

	int pivot = *piv;
	int *i = left;

	int *offset[BLOCK_SIZE];
	int *j = left;
	int **num = offset;

	while (j < right) {
		const int min = MIN(BLOCK_SIZE, right - j);
		int *lim = j + min;

		int *pd = j;
		do {
			*num = pd;
			num += (*pd < pivot);
			pd++;
		} while (pd < lim);

		int nums = num - offset;

		for (int k = 0; k < nums; k++) {
			SWAP(i, offset[k]);
			i++;
		}

		num = offset;
		j += min;
	}

	SWAP(i, right);

	*p = i;
}

void lomuto_dp_blocked(int *left, int *right, int **pl, int **pr)
{
	ptrdiff_t diff = right - left;

	int third = FIND_DIV(right, left, 3);

	int *f_third = left + third;
	int *s_third = right - third;

	int *f_med;
	int *s_med;

	if (diff > MEDIAN_OF_FIVE_OF_FIFTEEN_LIMIT) {
		f_med = median_five_of_fifteen(left, s_third);
		s_med = median_five_of_fifteen(f_third, right);
	} else if (diff > MEDIAN_OF_FIVE_OF_THREE_LIMIT) {
		f_med = median_five_of_three(left, s_third);
		s_med = median_five_of_three(f_third, right);
	} else {
		f_med = median_three(left, s_third);
		s_med = median_three(f_third, right);
	}

	if (*f_med < *s_med) {
        SWAP(f_med, left);
        SWAP(s_med, right);
    } else {
        SWAP(f_med, right);
        SWAP(s_med, left);
    }

	int f_piv = *left;
	int s_piv = *right;

	int *i = left + 1;
	int *j = left + 1;
	int *k = left + 1;

	int *offset[BLOCK_SIZE];
	int **num_left = offset;
	int **num_right = offset;

	while (k < right) {
		const int min = MIN(BLOCK_SIZE, right - k);

		int *k_lim = k + min;

		int *pd = k;
		do {
			*num_left = pd;
			num_left += (*pd <= s_piv);
			pd++;
		} while (pd < k_lim);

		int diff_k = num_left - offset;

		for (int c = 0; c < diff_k; c++) {
			SWAP(j + c, offset[c]);
		}

		k += min;

		int *j_lim = j + diff_k;

		pd = j;
		do {
			*num_right = pd;
			num_right += (*pd < f_piv);
			pd++;
		} while (pd < j_lim);

		int diff_j = num_right - offset;

		for (int c = 0; c < diff_j; c++) {
			SWAP(i, offset[c]);
			i++;
		}

		j += diff_k;

		num_left = offset;
		num_right = offset;
	}

	SWAP(i - 1, left);

	SWAP(j, right);

	*pl = i - 1;
	*pr = j;
}

void yaroslavskiy_blocked(int *left, int *right, int div)
{
	const ptrdiff_t diff = right - left;

	if (diff < RUN_INSERTION) {
		insertion_sort(left, right);
	} else {
		int third = FIND_DIV(right, left, div);

		int *f_third = left + third;
		int *s_third = right - third;

		int *f_med;
		int *s_med;

		if (diff > MEDIAN_OF_FIVE_OF_FIFTEEN_LIMIT) {
			f_med = median_five_of_fifteen(left, s_third);
			s_med = median_five_of_fifteen(f_third, right);
		} else if (diff > MEDIAN_OF_FIVE_OF_THREE_LIMIT) {
			f_med = median_five_of_three(left, s_third);
			s_med = median_five_of_three(f_third, right);
		} else {
			f_med = median_three(left, s_third);
			s_med = median_three(f_third, right);
		}

		if (*f_med < *s_med) {
			SWAP(f_med, left);
			SWAP(s_med, right);
		} else {
			SWAP(f_med, right);
			SWAP(s_med, left);
		}

		int f_piv = *left;
		int s_piv = *right;

		int *l = left + 1;
		int *r = right - 1;

		if (third >= BLOCK_SIZE && f_piv != s_piv) {
			int *tmp_r = r;

			int *offset_l[BLOCK_SIZE];
			int *offset_r[BLOCK_SIZE];

			int **num_left = offset_l;
			int **num_right = offset_r;

			do {
				int *l_lim = l + BLOCK_SIZE;
				if (num_left == offset_l) {
					int *pd = l;
					do {
						*num_left = pd;
						num_left += f_piv < *pd;
						pd++;
					} while (pd != l_lim);
				}

				int *r_lim = tmp_r - BLOCK_SIZE;
				if (num_right == offset_r) {
					int *pd = tmp_r;
					do {
						*num_right = pd;
						num_right += f_piv >= *pd;
						pd--;
					} while (pd != r_lim);
				}

				int min = MIN(num_left - offset_l, num_right - offset_r);

                if (min == 0)
                    break;

				num_left -= min;
				num_right -= min;

				for (int i = 0; i < min; i++) {
					SWAP(num_left[i], num_right[i]);
				}

				l += num_left == offset_l ? BLOCK_SIZE : 0;
				tmp_r -= num_right == offset_r ? BLOCK_SIZE : 0;

			} while (tmp_r - l + 1 > 2 * BLOCK_SIZE);

			int *tmp_l = l + 1;
			if (r - tmp_l + 1 > 2 * BLOCK_SIZE) {
				num_left = offset_l;
				num_right = offset_r;

				do {
					int *l_lim = tmp_l + BLOCK_SIZE;
					if (num_left == offset_l) {
						int *pd = tmp_l;
						do {
							*num_left = pd;
							num_left += s_piv < *pd;
							pd++;
						} while (pd != l_lim);
					}

					int *r_lim = r - BLOCK_SIZE;
					if (num_right == offset_r) {
						int *pd = r;
						do {
							*num_right = pd;
							num_right += s_piv >= *pd;
							pd--;
						} while (pd != r_lim);
					}

					int min = MIN(num_left - offset_l, num_right - offset_r);
                    if (min == 0)
                        break;

					num_left -= min;
					num_right -= min;

					for (int i = 0; i < min; i++) {
						SWAP(num_left[i], num_right[i]);
					}

					tmp_l += num_left == offset_l ? BLOCK_SIZE : 0;
					r -= num_right == offset_r ? BLOCK_SIZE : 0;

				} while (r - tmp_l + 1 > 2 * BLOCK_SIZE);
			}
		}

		for (int *i = l; i <= r; i++) {
			if (*i < f_piv) {
				SWAP(i, l);
				l++;
			} else if (*i > s_piv) {
				while (i<r && * r> s_piv) {
					r--;
				}
				if (*r < f_piv) {
					ROTATE(r, i, l);
					l++;
				} else {
					SWAP(i, r);
				}
				r--;
			}
		}

		const ptrdiff_t dist = r - l;

		div += dist < 13;

		SWAP(left, l - 1);
		SWAP(right, r + 1);

		yaroslavskiy_blocked(left, l - 2, div);
		yaroslavskiy_blocked(r + 2, right, div);

		if (f_piv != s_piv && dist > (diff - 13)) {
			for (int *i = l; i <= r; i++) {
				if (*i == f_piv) {
					SWAP(i, l);
					l++;
				} else if (*i == s_piv) {
					if (*r == f_piv) {
						ROTATE(r, i, l);
						l++;
					} else {
						SWAP(i, r);
					}
					r--;
				}
			}
		}

		if (f_piv != s_piv) {
			yaroslavskiy_blocked(l, r, div);
		}
	}
}