#include "./headers/list.h"
#include <string.h>
#include <stdlib.h>

void addAtBeginning(Node **head, Team v){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->echipa = v;
	newNode->next = *head;
	*head = newNode;
}

void deleteNode(Node **head, float scorMinim){
	if (*head==NULL) return;
	Node *headCopy = *head;
	if (headCopy->echipa.scorEchipa == scorMinim){
		*head = (*head)->next;
		free(headCopy);
		return;
	}
	Node *prev = *head;
	while (headCopy!=NULL){
		if(headCopy->echipa.scorEchipa != scorMinim){
			prev = headCopy;
			headCopy = headCopy->next;
		}else{
			prev->next = headCopy->next;
			free(headCopy);
			return;
		}
	}
}