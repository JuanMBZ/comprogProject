#include <stdio.h>
#include <stdlib.h>
#include "dlinkedlist.h"

//add code/ops for reading and writing to file here
int main() {
	line *head;
	FILE *fiptr;
	fiptr=fopen("in.txt", "r");
	
	head=createList(fiptr);
	printf("Read Forwards: \n");
	display(head);
	printf("Read Backwards: \n");
	displayend(head);

	return 0;
}
