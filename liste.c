#include "./headers/list.h"
#include <string.h>
#include <stdlib.h>

void addAtBeginning(Node **head, Team *v){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->echipa = (Node*)malloc(sizeof(Node));
	newNode->echipa = v;
	newNode->next = *head;
	*head = newNode;
}
/*
void addAtEnd(Node** head, char v[]){
	Node *aux = *head;
	Node *newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->val, v);
	if (*head == NULL) addAtBeginning(head, v);
	else{
		while (aux->next!=NULL)
			aux = aux->next;
		aux->next = newNode;
		newNode->next = NULL;
	}
}*/

void deleteNode(Node **head, float scorMinim){
	if (*head==NULL) return;
	Node *headCopy = *head;
	if (headCopy->echipa->scorEchipa == scorMinim){
		*head = (*head)->next;
		//for(int i=0; i<headCopy->echipa->nrPlayeri; i++)
		free(headCopy->echipa->jucator);
		free(headCopy);
		return;
	}
	Node *prev = *head;
	while (headCopy!=NULL){
		if(headCopy->echipa->scorEchipa != scorMinim){
			prev = headCopy;
			headCopy = headCopy->next;
		}else{
			prev->next = headCopy->next;
			//for(int i=0; i<headCopy->echipa->nrPlayeri; i++) 
			free(headCopy->echipa->jucator);
			free(headCopy);
			return;
		}
	}
}
