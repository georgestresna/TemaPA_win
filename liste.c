#include "./headers/list.h"
#include <string.h>
#include <stdlib.h>

void addAtBeginning(Node **head, char v[]){
	Node* newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->val, v);
	newNode->next = *head;
	*head = newNode;
}

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
}

void deleteNode(Node **head, char v[]){
	if (*head==NULL) return;
	Node *headcopy = *head;
	if (headcopy->val==v){
		*head = (*head)->next;
		free(headcopy);
		return;
	}
	Node *prev = *head;
	while (headcopy!=NULL){
		if(headcopy->val!=v){
			prev = headcopy;
			headcopy = headcopy->next;
		}else{
			prev->next = headcopy->next;
			free(headcopy);
			return;
		}
	}
}

void addAtBeginningScore(scor **head, int value){
	scor* newNode = (scor*)malloc(sizeof(scor));
	newNode->points = value;
	newNode->next = *head;
	*head = newNode;
}

void deleteScore(scor **headS, Node **head, int p){
	if (*headS==NULL) return;
	scor *headScopy = *headS;
	Node *headcopy = *head;
	if (headScopy->points == p){
		*headS = (*headS)->next;
		*head = (*head)->next;
		free(headScopy);
		free(headcopy);
		return;
	}
	scor *prevS = *headS;
	Node *prev = *head;
	while (headScopy!=NULL){
		if(headScopy->points != p){
			prevS = headScopy;
			prev = headcopy;
			headScopy = headScopy->next;
			headcopy = headcopy->next;
		}else{
			prevS->next = headScopy->next;
			prev->next = headcopy->next;
			free(headScopy);
			free(headcopy);
			return;
		}
	}
}