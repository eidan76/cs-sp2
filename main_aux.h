/*
 * main_aux.h
 *
 *  Created on: Apr 6, 2018
 *      Author: Eidan
 */

#ifndef MAIN_AUX_H_
#define MAIN_AUX_H_

void print_winner(int whoseTurn);
void print_move(int whoseTurn, int removedObs, int heapInd);
void print_board(int turnNum, int* heaps);
int* initialize();



#endif /* MAIN_AUX_H_ */
