/*
 * sp_nim.c
 *
 *  Created on: Apr 6, 2018
 *      Author: Eidan
 */

int* computer_next_move(int *heaps) {
	int nim_sum = nim_sum(heaps);
	int i=0;
	int min_val = -1;
	int min_index = 0;
	int result_move[2];
	if (nim_sum != 0){
		for (;i<32;i++) {
			if (min_val<0 || (min_val > heaps[i] && heaps[i] > heaps[i]^nim_sum)) {
				min_val = heaps[i]^nim_sum;
				min_index = i;
			}
		}
	result_move[1] = heaps[i]-min_val;
	}
	else {
		for (;i<32;i++) {
			if (min_val<0 || (min_val > heaps[i] && heaps[i] > 0)) {
				min_val = heaps[i];
				min_index = i;
			}
		}
		result_move[1] = 1;
	}
	result_move[0] = min_index;
	return result_move;
}

int nim_sum(int *heaps) {
	int sum = 0;
	for (int i=0;i<32;i++) {
		sum ^= heaps[i];
	}
	return sum;
}

int is_game_over(int *heaps) {
	for (int i=0;i<32;i++) {
		if (heaps[i] > 0)
			return 0;
	}
	return 1;
}

