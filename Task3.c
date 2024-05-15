#include <stdio.h>
#include <stdlib.h>
//#include "./headers/list.h"
#include "./headers/cozi_stive.h"
#include <string.h>
/*
void creareLista(Node**last8, Stiva*winners){
    //winners e doar o copie
    while(!isEmptyS(winners)){
        Team* aux=winners->echipa;
        winners=winners->next;
        addAtBeginning(last8, aux);
    }
}
*/

int prelucrarePodium(Stiva**winners, Stiva**losers, Queue**q, FILE*fout, int nrPlayeriEchipa){
    
    //aici am de lucrat, deci imi pune winner si losers bine, dar cand imi umple queue ul inapoi e bucla infinita
    
    //eliminare losers
    Team aux;
    //while(!isEmptyS(*losers)) aux=pop(losers);
    deleteStack(losers);
    //mutare winner in q
    int counter=0;
    while(!isEmptyS(*winners)){
        aux=pop(winners);
        //printf("%s\n", aux.jucator[0].firstName);

        //printare castigator si scor
        fprintf(fout, "%-34s- %.2f\n", aux.numeEchipa, aux.scorEchipa);
        enQueue(*q, aux);
        counter++;
    }
    deleteStack(winners);
    return counter/2;              //noul counter
}

void prelucrareMeciuri(Queue** q, int counter, FILE* fout, Stiva **winners, Stiva**losers){
    
    //pentru fiecare meci
    for(int i=0; i<counter; i++){
        //scot meci din queue
        Team firstTeam, secondTeam;

        firstTeam=deQueue(*q);
        secondTeam=deQueue(*q);
        
        //reglare nume echipa
        if(firstTeam.numeEchipa[strlen(firstTeam.numeEchipa)-1]==' ') firstTeam.numeEchipa[strlen(firstTeam.numeEchipa)-1] = '\0';
        if(secondTeam.numeEchipa[strlen(secondTeam.numeEchipa)-1]==' ') secondTeam.numeEchipa[strlen(secondTeam.numeEchipa)-1] = '\0';
        //scriere tabela de meciuri cu spatii
        fprintf(fout, "%-33s-%33s\n", firstTeam.numeEchipa, secondTeam.numeEchipa);
            //declarare castigatori si pierzatori
            if(firstTeam.scorEchipa > secondTeam.scorEchipa){
                firstTeam.scorEchipa++;      //+1pct echipa
                for(int j=0; j<firstTeam.nrPlayeri; j++)     //+1pct fiecare jucator
                    firstTeam.jucator[j].points++;
                //Echipa1 in winners Echipa2 in  losers
                push(winners, firstTeam);
                //printf("%s\n", meciCurent->Echipa1->numeEchipa);
                push(losers, secondTeam);
            }
            else{
                secondTeam.scorEchipa++;      //+1pct echipa
                for(int j=0; j<secondTeam.nrPlayeri; j++)     //+1pct fiecare jucator
                    secondTeam.jucator[j].points++;
                //Echipa1 in winners Echipa2 in  losers
                push(winners, secondTeam);
                //printf("%s\n", meciCurent->Echipa1->numeEchipa);
                push(losers, firstTeam);
            }
    }
    deleteQueue(*q);
}

Node* Task3(FILE* fout, Node* head){

    //creez queue, stive si lista de theLast8
    Queue* q=createQueue();
    Node* headCopy=head;
    Node *last8=NULL;

    int counter=0;
    int round = 1;

    //populare Q din lista, counter = cate meciuri sunt in lista
    int nrPlayeriEchipa=headCopy->echipa.nrPlayeri;
    while(headCopy){
        enQueue(q, headCopy->echipa);
        headCopy=headCopy->next;
        counter++;
    }
    counter=counter/2;

    fprintf(fout, "\n");

    //in loop se intra cu q plin si cu winner si loser goale

    //while(counter != 2){
    //for(int i=0; i<2; i++){
    //if(1){
        Stiva* winners=NULL;
        Stiva* losers=NULL;
        fprintf(fout, "--- ROUND NO:%d\n", round);
        prelucrareMeciuri(&q, counter, fout, &winners, &losers);
        fprintf(fout, "\n"); fprintf(fout,"WINNERS OF ROUND NO:%d\n", round);
        deleteStack(&losers);
        Stiva*winnersAux = winners;
        while(winnersAux){
            enQueue(q, winnersAux->echipa);
            winnersAux=winnersAux->next;
        }
        deleteStack(&winners);

        
        //este peste tot
        //if(isEmptyQ(q))printf("empty!!\n");
        //daca am 8 castigatori in winners
        //if(counter == 8) creareLista(&last8, winners);
        //am eliberat stivele, am umplut queue ul
        /*counter = prelucrarePodium(&winners, &losers, &q, fout, nrPlayeriEchipa); 
        fprintf(fout, "\n");
        printf("\n--%d--\n", counter);
        round++;*/

        //fflush(fout);
        //winners=NULL;
        //losers=NULL;

        //queue 
        while(q->front){printf("%s\n", (q->front)->echipa.numeEchipa); q->front=(q->front)->next;}
        
        //printf("winners:\n");
        //while(winners){printf("%s\n", winners->echipa.numeEchipa); winners=winners->next;}
        
        //printf("losers:\n");
        //while(losers){printf("%s\n", losers->echipa.numeEchipa); losers=losers->next;}

    //}
    //while(q->front){printf("%s vs %s\n", (q->front)->echipa.numeEchipa, (q->front)->next->echipa.numeEchipa); q->front=(q->front)->next; q->front=(q->front)->next;}
}