#include <stdio.h>
#include <stdlib.h>

typedef struct dNode {
	char ch;
	struct dNode *prev;
	struct dNode *next;
} dNode;

dNode* createList();
void displayforward(dNode *head);
void displaybackward(dNode *head);

int main () {
	dNode *head;
	
	head=createList();
	displayforward(head);
	displaybackward(head);

	return 0;
}

dNode* createList() {
	dNode *head, *curr;
	int n;
	printf("How many Characters: ");
	scanf("%d", &n);
	printf("Type String: ");

	for(int i=0; i<n; i++) {
		if(i==0) {
			head=(dNode*) malloc(sizeof(dNode));
			curr=head;
			head->prev=NULL;
			scanf(" %c", &(head->ch));
		}
		else {
			curr->next=(dNode*) malloc(sizeof(dNode));
			(curr->next)->prev=curr;
			curr=curr->next;
			scanf("%c", &(curr->ch));
		}
	}
	curr->next=NULL;
	return head;
}

void displayforward(dNode* head) {
	dNode *curr=head;
	int count=0;
	while(curr!=NULL) {
		printf("%c", curr->ch);
		count++;
		curr=curr->next;
	}
	printf("\nNo. of chars printed: %d\n", count);
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
