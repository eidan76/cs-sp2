/*
 * sp_nim.c
 *
 *  Created on: Apr 6, 2018
 *      Author: Eidan
 */
#include "main_aux.h"
#define YOURTURN "Your turn: please enter the heap index and the number of removed objects.\n"
#define YOURTURN_TRY2 "Error: Invalid input.\nPlease enter again the heap index and the number of removed objects.\n"

/*calculates the computer's next move using nim sum*/
int* computer_next_move(int *heaps) {
	int nim_sum = nim_sum(heaps);
	int i=0;
	int min_val = -1; /*stores the current found minimum nim sum*/
	int min_index = 0; /*index of the heap with the current found minimum nim sum*/
	int result_move[2];
	if (nim_sum != 0){
		for (;i<32;i++) {
			/* check if hti > hti XOR st. if so,
			 * ht1 is the minimum if min_val has not yet been initialized or ht1>min_val
			 */
			if (heaps[i] > (heaps[i]^nim_sum) && (min_val<0 || min_val > heaps[i])) {
				min_val = heaps[i]^nim_sum;
				min_index = i;
			}
		}
	result_move[1] = heaps[i]-min_val;
	}
	else {
		for (;i<32;i++) {
			/* check if hti > 0. if so,
			 * ht1 is the minimum if min_val has not yet been initialized or ht1>min_val
			 */
			if (heaps[i] > 0 && (min_val<0 || min_val > heaps[i])) {
				min_val = heaps[i];
				min_index = i;
			}
		}
		result_move[1] = 1;
	}
	result_move[0] = min_index;
	return result_move;
}
/*calculates the nim sum of the entire heap*/
int nim_sum(int *heaps) {
	int sum = 0;
	for (int i=0;i<32;i++) {
		sum ^= heaps[i];
	}
	return sum;
}
/*checks if all heaps are empty*/
int is_game_over(int *heaps) {
	for (int i=0;i<32;i++) {
		if (heaps[i] > 0)
			return 0;
	}
	return 1;
}

int* user_next_move(int *heaps) {
	printf(YOURTURN);
	int valid = 1, index, val;
	int request[2];
	do {
		if (!valid)
			printf(YOURTURN_TRY2);
		scanf("%d%d", index, val);
		if (0>index || index>32 || heaps[index] < val)
			valid = 0;
	} while (!valid);
	request[0] = index;
	request[1] = val;
	return request;
}

int game(int *heaps) {
	int whos_turn = 0; /*1=user 0=computer*/
	int turn = 1; /*turn counter*/
	int turn_request[2]; /*each turn is summed up as {index of heap to remove from, no. of objects to remove}*/
	while (!is_game_over(heaps)) {
		whos_turn = !whos_turn;
		print_board(turn,heaps);

		if (whos_turn == 0)
			turn_request = computer_next_move(heaps);
		else
			turn_request = user_next_move(heaps);

		print_move(whos_turn, turn_request[1], turn_request[0]);
		heaps[turn_request[0]] -= turn_request[1]; /* remove X objects from heap Y*/

		turn++;
	}
	print_board(turn,heaps);
	print_winner(whos_turn);
}

