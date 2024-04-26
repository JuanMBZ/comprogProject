//Should include insertion and deletion, also maybe search and replace and others.

#define ESCAPE '\e'
#define BACKSPACE '\b'
#define NEWLINE '\n'

void display_insert(dNode *curr, char input);
void insert_to_list(dNode **curr, line **curr_line, char input);//insert char other than \n or \t (tab)
void newline(dNode *curr);//insert newline
void backspace(dNode *curr);
void insert_mode(int *x,int *y, dNode **curr, line **curr_line);

void display_insert(dNode *curr, char input) {
	putchar(input);
	while(curr->next!=NULL) {
		putchar(curr->ch);
		fflush(stdout);
		curr=curr->next;
	}
}
void insert_to_list(dNode **curr, line **curr_line, char input) {
	dNode *newN=malloc(sizeof(dNode));
	newN->next=*curr;
	newN->ch=input;
	if((*curr)->prev==NULL) {//If current's at beginning
		newN->prev=NULL;
		(*curr_line)->start=newN;
	}
	else { //else if curr's at middle or end
		newN->prev=(*curr)->prev;
		((*curr)->prev)->next=newN; // Update previous node's next to be new Node
	}
	(*curr)->prev=newN;
}

void insert_mode(int *x,int *y, dNode **curr, line **curr_line) {
	char key_press;
	while((key_press=getchar())!=ESCAPE) {
		switch(key_press) {
			case BACKSPACE:

				break;
			case NEWLINE:

				break;
			default:
				insert_to_list(curr, curr_line, key_press);
				display_insert(*curr, key_press);
				*x+=1;
				cursorto(*x, *y);
		}
	}
}
