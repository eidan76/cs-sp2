/*
 * sp_nim.h
 *
 *  Created on: Apr 6, 2018
 *      Author: Eidan
 */

#ifndef SP_NIM_H_
#define SP_NIM_H_

int game(int heapNum, int *heaps);
int is_game_over(int heapNum, int *heaps);
int nim_sum(int heapNum, int *heaps);
int* computer_next_move(int heapNum, int *heaps);
int* user_next_move(int heapNum, int *heaps);


#endif /* SP_NIM_H_ */
