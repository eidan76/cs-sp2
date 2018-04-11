/*
 * main_aux.c
 *
 *  Created on: Apr 6, 2018
 *      Author: RonyHirsch
 */
#include <stdio.h>
#define NUMOFHEAPS 32
#define HEAPSREQ "Enter the number of heaps:\n"
#define HEAPSERR "Error: the number of heaps must be between 1 and %d.\n"
#define HEAPSIZEREQ "Enter the heap sizes:\n"
#define HEAPSIZENEGERR "Error: the size of heap %d should be positive.\n"
#define YOUWIN "You win!\n"
#define COMPWIN "Computer wins!\n"
#define HEAPSTAT "In turn %d heap sizes are:"
#define YOURTURN "Your turn: please enter the heap index and the number of removed objects.\n"
#define YOURTURNERR "Error: invalid input.\nPlease enter again the heap index and the number of removed objects.\n"
/*
 * check if the number of heaps is between 1 and 32
 */
int check_heapNum(int heapNum){
	if (heapNum<1 || heapNum > NUMOFHEAPS){
		printf(HEAPSERR,NUMOFHEAPS);
		return 0;
	}
	else return 1;
}

/*
 * get input from user of num of heaps and how many obs in every heap before game starts
 * return num of heaps and num of objs in every heap
 */
int init_heap_num(){
	int heapNum;

	printf(HEAPSREQ);
	scanf("%d",&heapNum);
	if (!check_heapNum(heapNum)) return 0;
	return heapNum;
}

int* init_heap_sizes(int heapNum){
	static int heaps[NUMOFHEAPS];
	static int err[] = {-1};
	int i;

	printf(HEAPSIZEREQ);
	for (i=0;i<heapNum;++i){
		scanf("%d", &heaps[i]);
		if (heaps[i]<0){
			printf(HEAPSIZENEGERR,i);
			return err;}
	}
	return heaps;
}


/*
 * prints the situation of the board in every turn
 */
void print_board(int turnNum, int* heaps, int heapNum){
	int i=0;

	printf(HEAPSTAT,turnNum);
	for (i=0;i<heapNum;++i){
		printf(" h%d=%d",i+1,(int)heaps[i]);
	}
	printf(".\n");
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
	printf("%s takes %d objects from heap %d\n",player, removedObs,heapInd+1);
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
	else {printf(YOUWIN);}
	return;
}



