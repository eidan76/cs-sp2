/*
 * sp_nim.c
 *
 *  Created on: Apr 6, 2018
 *      Author: Eidan
 */
#include "main_aux.h"
#include <stdio.h>
#define YOURTURN "Your turn: please enter the heap index and the number of removed objects.\n"
#define YOURTURN_TRY2 "Error: Invalid input.\nPlease enter again the heap index and the number of removed objects.\n"

/*calculates the nim sum of the entire heap*/
int nim_sum(int heapNum, int *heaps) {
	int sum = 0;
	int i;

	for (i=0;i<heapNum;i++) {
		sum ^= heaps[i];
	}
	return sum;
}
/*calculates the computer's next move using nim sum*/
int* computer_next_move(int heapNum, int *heaps) {
	static int result_move[2];
	int ns = nim_sum(heapNum,heaps);
	int i=0;
	int min_val = -1; /*stores the current found minimum nim sum*/
	int min_index = 0; /*index of the heap with the current found minimum nim sum*/

	if (ns != 0){
		for (;i<heapNum;i++) {
			/* check if hti > hti XOR st. if so,
			 * ht1 is the minimum if min_val has not yet been initialized or ht1>min_val
			 */
			if (heaps[i] > (heaps[i]^ns) && (min_val<0 || min_val > heaps[i])) {
				min_val = heaps[i]^ns;
				min_index = i;
			}
		}
	result_move[1] = heaps[min_index]-min_val;
	}
	else {
		for (;i<heapNum;i++) {
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

/*checks if all heaps are empty*/
int is_game_over(int heapNum, int *heaps) {
	int i;

	for (i=0;i<heapNum;i++) {
		if (heaps[i] > 0)
			return 0;
	}
	return 1;
}

int* user_next_move(int heapNum, int *heaps) {
	int valid = 1, index, val;
	static int request[2]; /*user move request is {heap index, no of objects to remove}*/

	printf(YOURTURN);
	do {
		if (!valid)
			printf(YOURTURN_TRY2);
		scanf("%d", &index);
		scanf("%d", &val);
		if (1>index || index>heapNum || heaps[index-1] < val || val<1)
			valid = 0;
		else valid = 1;
	} while (!valid);
	request[0] = index-1;
	request[1] = val;
	return request;
}

int game(int heapNum, int *heaps) {
	int whose_turn = 0; /*1=user 0=computer*/
	int turn = 1; /*turn counter*/
	int *turn_request; /*each turn is summed up as {index of heap to remove from, no. of objects to remove}*/

	while (!is_game_over(heapNum,heaps)) {
		whose_turn = !whose_turn;
		print_board(turn,heaps,heapNum);

		if (whose_turn == 0)
			turn_request = computer_next_move(heapNum,heaps);
		else
			turn_request = user_next_move(heapNum,heaps);

		print_move(whose_turn, turn_request[1], turn_request[0]);
		heaps[turn_request[0]] -= turn_request[1]; /* remove X objects from heap Y*/

		turn++;
	}
	print_board(turn,heaps,heapNum);
	print_winner(whose_turn);
	return 0;
}

