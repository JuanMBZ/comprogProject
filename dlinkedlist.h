#include <stdio.h>
#include <stdlib.h>

/* Contains code for node struct and creating/displaying heads/list
 * Code for other list ops is at dataops
 */

typedef struct dNode {
	char ch;
	struct dNode *prev;
	struct dNode *next;
} dNode;

typedef struct line{
	dNode *start;
	struct line *prev_line;
	struct line *next_line;
	unsigned int size;
} line;


line* createList(FILE *file_in) {
	dNode *curr;
	line *head, *curr_line;
	int n=0;
	char c;
	//Initialize line start
	head=(line*)malloc(sizeof(line));
	curr_line=head;
	curr_line->prev_line=NULL;

	while(fscanf(file_in, "%c", &c)!=EOF) {//Iterate until EOF
		if(n==0) {
			curr_line->start=(dNode*) malloc(sizeof(dNode));
			curr=curr_line->start;
			curr->prev=NULL;
			curr->ch=c;
		}
		else {
			curr->next=(dNode*) malloc(sizeof(dNode));
			(curr->next)->prev=curr;
			curr=curr->next;
			curr->ch=c;
		}
		n++;
		if(c=='\n') {//If current char is a newline character make a new line
			curr_line->size=n-1;//record line size
			curr_line->next_line=(line*)malloc(sizeof(line));
			(curr_line->next_line)->prev_line=curr_line;
			curr_line=curr_line->next_line;
			n=0; //restart count
			curr->next=NULL; //assigns null to last node
		}
	}
	curr_line=curr_line->prev_line;
	free(curr_line->next_line); //frees the last line cause, for some reason, text files in linux ends with a \n
	curr_line->next_line=NULL;
	curr->next=NULL;
	return head;
}

void displayLine(dNode* head) {
	dNode *curr=head;
	while(curr!=NULL) {
		putchar(curr->ch);
		fflush(stdout); // used so stdout is immediately shown to screen
		curr=curr->next;
	}
}

void display(line *head) {
	line *curr=head;
	int count=0;
	while(curr!=NULL) {
		displayLine(curr->start);
		count++;
		curr=curr->next_line;
	}
//	printf("Number of lines printed: %d\n", count);
}

void displayend(line *head) {
	line *curr=head;
	int count=0;
	while(curr->next_line!=NULL) curr=curr->next_line;
	while(curr!=NULL) {
		displayLine(curr->start);
		count++;
		curr=curr->prev_line;
	}
	printf("\nNumber of lines printed: %d\n", count);
}

void displaybackward(dNode *head) { 
	dNode *curr=head;
	int count=0;
	while(curr->next!=NULL) curr=curr->next;
	while(curr!=NULL) {
		printf("%c", curr->ch);
		count++;
		curr=curr->prev;
	}
	printf("\nNo. of chars printed: %d\n", count);
}
