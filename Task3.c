#include <stdio.h>
#include <stdlib.h>
//#include "./headers/list.h"
#include "./headers/cozi_stive.h"
#include <string.h>

void printRound(Queue**q, FILE*fout, Stiva**winners, Stiva**losers){
    Team aux1, aux2;
    while(!isEmptyQ(*q)){
        aux1=deQueue(*q);
        aux2=deQueue(*q);
        //*counter = *counter - 2;

        if(aux1.numeEchipa[strlen(aux1.numeEchipa)-1]==' ') aux1.numeEchipa[strlen(aux1.numeEchipa)-1] = '\0';
        if(aux2.numeEchipa[strlen(aux2.numeEchipa)-1]==' ') aux2.numeEchipa[strlen(aux2.numeEchipa)-1] = '\0';
        fprintf(fout, "%-33s-%33s\n", aux1.numeEchipa, aux2.numeEchipa);
        if(aux1.scorEchipa > aux2.scorEchipa){
            aux1.scorEchipa++;      //+1pct echipa
            for(int j=0; j<aux1.nrPlayeri; j++)     //+1pct fiecare jucator
                aux1.jucator[j].points++;
            push(winners, aux1);
            push(losers, aux2);
        }
        else{
            aux2.scorEchipa++;      //+1pct echipa
            for(int j=0; j<aux2.nrPlayeri; j++)     //+1pct fiecare jucator
                aux2.jucator[j].points++;
            push(winners, aux2);
            push(losers, aux1);
        }
    }
}


void Task3(FILE* fout, Node* head, Node**last8){
    Queue* q=createQueue();
    int counter=0, round=1;
    while(head){
        enQueue(q, head->echipa);
        head=head->next;
        counter++;
    }
    Team aux1, aux2;
    Stiva *winners=NULL, *losers=NULL;
    //Node*last8=NULL;

    while(counter != 1){
        //printf("counter: %d; round: %d\n", counter, round);
        fprintf(fout, "\n--- ROUND NO:%d\n", round);
        printRound(&q, fout, &winners, &losers);
        fprintf(fout,"\nWINNERS OF ROUND NO:%d\n", round);
        deleteQueue(q); q=NULL;
        if(counter == 16){
            Stiva*winnersA=winners;
            while(winnersA){
                //printf("%s %.2f\n", winnersA->echipa.numeEchipa, winnersA->echipa.scorEchipa); 
                
                Node *last8aux=(Node*)malloc(sizeof(Node));
                last8aux->echipa=winnersA->echipa;
                last8aux->next=*last8;
                *last8=last8aux;
                
                winnersA=winnersA->next;
            }
        }

        counter=0;
        
        deleteStack(&losers); losers=NULL;
        q=createQueue();
        while(!isEmptyS(winners)){
            aux1=pop(&winners);
            enQueue(q, aux1);
            fprintf(fout, "%-34s-  %.2f\n", aux1.numeEchipa, aux1.scorEchipa);
            counter++;
        }
        deleteStack(&winners); winners=NULL;
        round++;

        fflush(fout);
    }
    //while(q->front){printf("%s %.2f\n", (q->front)->echipa.numeEchipa, (q->front)->echipa.scorEchipa); q->front=(q->front)->next;}
    //while(winners){printf("%s\n", winners->echipa.numeEchipa); winners=winners->next;}
    //while(losers){printf("%s\n", losers->echipa.numeEchipa); losers=losers->next;}
    //printf("end\n");
}