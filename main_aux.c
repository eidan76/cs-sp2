/*
 * main_aux.c
 *
 *  Created on: Apr 6, 2018
 *      Author: RonyHirsch
 */
#include <stdio.h>
#define HEAPSREQ "Enter the number of heaps:\n"
#define HEAPSERR "Error: the number of heaps must be between 1 and 32.\n"
#define HEAPSIZEREQ "Enter the heap sizes:\n"
#define HEAPSIZENEGERR "Error: the size of heap %d should be positive.\n"
#define YOUWIN "You win!\n"
#define COMPWIN "Computer wins!\n"
#define HEAPSTAT "In turn %d heap sizes are: "
#define YOURTURN "Your turn: please enter the heap index and the number of removed objects.\n"
#define YOURTURNERR "Error: invalid input.\nPlease enter again the heap index and the number of removed objects.\n"



/*
 * get input from user of num of heaps and how many obs in every heap before game starts
 * return num of heaps and num of objs in every heap
 */
int* initialize(){
	int i=0;
	int* res[2];
	int heapNum;
	int* heapSizes;
	printf(HEAPSREQ);
	scanf("%d",heapNum);
	if (heapNum < 1 || heapNum > 32){
		printf(HEAPSERR);
		return res;
	}
	else {
		printf(HEAPSIZEREQ);
		scanf("%d*",heapSizes);
		for (i=0;i<sizeof(heapSizes);++i){
			if (heapSizes[i]<0){
				printf(HEAPSIZENEGERR,i);
				return res;
			}
		}
		res[0]=heapNum; res[1]=heapSizes;
		return res;
	}

}


void print_board(int turnNum, int* heaps){
	int i=0;
	printf(turnNum+"	");
	for (i=0;i<sizeof(heaps);++i){
		printf(heaps[i]);
		printf(" ");
	}
	printf("	");
	return;
}



/*
 * whoseTurn=0 : computer's turn
 * whoseTurn=1 : user's turn
 * removedObs : number of objects to remove
 * heapInd : heap from which to remove
 */
void print_move(int whoseTurn, int removedObs, int heapInd){
	char* player;
	if (whoseTurn==0) player = "Computer";
	else player = "User";
	printf("%s takes %d objects from heap %d",player, removedObs,heapInd);
	return;
}

/*
 * whoseTurn=0 : computer's turn
 * whoseTurn=1 : user's turn
 */
void print_winner(int whoseTurn) {
	if (whoseTurn==0){
		printf(COMPWIN);
	}
	else printf(YOUWIN);
	return;
}



