/*
 * main.c
 *
 *  Created on: Apr 6, 2018
 *      Author: Eidan
 */
#include "sp_nim.h"
#include "main_aux.h"

int main(){
	int* heaps;
	int heapNum = init_heap_num();
	if (!heapNum) return 0;
	heaps = init_heap_sizes(heapNum);
	if (heaps[0]==-1) return 0;

	game(heapNum,heaps);
	return 1;
}
