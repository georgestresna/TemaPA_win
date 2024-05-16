#include "./headers/cozi_stive.h"
#include <stdlib.h>
#include <stdio.h>

Queue* createQueue(){
	Queue *q;
	q=(Queue *)malloc(sizeof(Queue));
	if (q==NULL) return NULL;	
	q->front=q->rear=NULL;
	return q;	
}

void enQueue(Queue* q, Team v){
	Stiva* newNode=(Stiva*)malloc(sizeof(Stiva));

	newNode->echipa = v;
	newNode->next=NULL;
	if (q->rear==NULL) q->rear=newNode; 
	else{
		(q->rear)->next=newNode;
		(q->rear)=newNode;
	}
	if (q->front==NULL) q->front=q->rear; 
}

int isEmptyQ(Queue*q){
	return (q->front==NULL);
}

Team deQueue(Queue*q) {  
	Stiva* aux; Team d;
	if (isEmptyQ(q)) exit(1);
	
	aux=q->front;
	d=aux->echipa;
	q->front=(q->front)->next;
	free(aux);
	return d;  	
} 

void deleteQueue(Queue*q){
	Stiva* aux;
	while (!isEmptyQ(q)){
		aux=q->front;
		q->front=(q->front)->next;
		free(aux);
	}
	free(q);
}	