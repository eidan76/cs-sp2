/*
 * main.c
 *
 *  Created on: Apr 6, 2018
 *      Author: Eidan
 */
#include "sp_nim.h"
#include "main_aux.h"

int main(){
	int *heaps;
	heaps = initialize();
	game(heaps);
	return 0;
}
