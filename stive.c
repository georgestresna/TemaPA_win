#include "./headers/cozi_stive.h"
#include <stdlib.h>

int isEmptyS(Stiva*top){
	return top==NULL;
}
	
void deleteStack(Stiva**top){
	Stiva  *temp;
	while ((*top)!=NULL){ // !isEmpty(*top)
		temp=*top;
		*top=(*top)->next;
		free(temp);
	}
}	

Team pop(Stiva**top){
    if (isEmptyS(*top)) exit(1);

	Stiva* temp = *top;
	Team poppedData;
	poppedData = temp->echipa;

	*top = (*top)->next;
    free(temp);
    return poppedData;
}

void push(Stiva**top, Team v) {
	Stiva* newNode=(Stiva*)malloc(sizeof(Stiva));
	newNode->echipa = v;
	newNode->next=*top;
	*top=newNode;
}
/*
int top(Node *top){
	if (isEmpty(top)) return INT_MIN;
	return top->val;
} */
/*
void printStack(Node* stack){
	while (!isEmpty(stack))
		printf("%d ", pop(&stack));
}*/