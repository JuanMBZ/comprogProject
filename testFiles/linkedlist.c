#include <stdio.h>
#include <stdlib.h>

typedef struct sNode {
	char ch;
	struct sNode* next;
} sNode;

sNode* createList();
void display(sNode *head);
int main () {
	sNode *head;
	
	head=createList();
	display(head);

	return 0;
}

sNode* createList() {
	sNode *head, *curr;
	int n;
	printf("How many Characters: ");
	scanf("%d", &n);
	printf("Type String: ");

	for(int i=0; i<n; i++) {
		if(i==0) {
			head=(sNode*) malloc(sizeof(sNode));
			curr=head;
			scanf(" %c", &(head->ch));
		}
		else {
			curr->next=(sNode*) malloc(sizeof(sNode));
			curr=curr->next;
			scanf("%c", &(curr->ch));
		}
	}
	curr->next=NULL;
	return head;
}

void display(sNode* head) {
	sNode *curr=head;
	int count=0;
	while(curr!=NULL) {
		printf("%c", curr->ch);
		count++;
		curr=curr->next;
	}
	printf("\nNo. of chars: %d\n", count);
}
