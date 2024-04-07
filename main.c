#include <stdio.h>
#include <stdlib.h>
#include "dlinkedlist.h"

#define clear() printf("\033[2J");
#define cursor_start() printf("\033[H");
//add code/ops for reading and writing to file here

int main(int argc, char**argv) {
	unsigned int x=1, y=1; // curosor position 
	line *head;
	FILE *fiptr;
	if(argc!=2) {
		printf("Too many/few arguments.\n");
		return -1;
	}
	fiptr=fopen(argv[1], "r");

	clear();
	cursor_start();
	head=createList(fiptr);
	display(head);

	return 0;
}
