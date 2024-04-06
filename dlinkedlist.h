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
	struct line *prevline;
	struct line *nextline;
	unsigned int size;
} line;


line* createList(FILE *file_in) {
	dNode *curr;
	line *head, *currline;
	int n=0;
	char c;
	//Initialize line start
	head=(line*)malloc(sizeof(line));
	currline=head;
	currline->prevline=NULL;

	while(fscanf(file_in, "%c", &c)!=EOF) {//Iterate until EOF
		if(n==0) {
			currline->start=(dNode*) malloc(sizeof(dNode));
			curr=currline->start;
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
			currline->size=n-1;//record line size
			currline->nextline=(line*)malloc(sizeof(line));
			(currline->nextline)->prevline=currline;
			currline=currline->nextline;
			n=0;
			curr->next=NULL; //assigns null to last node
		}
	}
	currline=currline->prevline;
	free(currline->nextline); //frees the last line cause, for some reason, text files in linux ends with a \n
	currline->nextline=NULL;
	curr->next=NULL;
	return head;
}

void displayLine(dNode* head) {
	dNode *curr=head;
	int count=0;
	while(curr!=NULL) {
		printf("%c", curr->ch);
		count++;
		curr=curr->next;
	}
}

void display(line *head) {
	line *curr=head;
	int count=0;
	while(curr!=NULL) {
		displayLine(curr->start);
		count++;
		curr=curr->nextline;
	}
	printf("\nNumber of lines printed: %d\n", count);
}

void displayend(line *head) {
	line *curr=head;
	int count=0;
	while(curr->nextline!=NULL) curr=curr->nextline;
	while(curr!=NULL) {
		displayLine(curr->start);
		count++;
		curr=curr->prevline;
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
