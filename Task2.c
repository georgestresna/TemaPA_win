#include <stdio.h>
#include <stdlib.h>
#include "./headers/list.h"

void creareTabela(scor** tabela, FILE* fin, int nrEchipe){

    for(int i=0; i<nrEchipe; i++){
        int nrPlayeri;
        fscanf(fin, "%d", &nrPlayeri);
        getc(fin);//scot spatiu

        //scot numele echipei
        char buffer[100];
        fgets(buffer, sizeof(buffer), fin);

        //punctaj echipa
        int punctajAux=0;
        int punctajTotal=0;
        for(int j=0; j<nrPlayeri; j++){
            fscanf(fin, "%*s %*s %d", &punctajAux);
            punctajTotal+=punctajAux;
        }
        addAtBeginningScore(tabela, punctajTotal);
        //getc(fin);// scot \n dintre echipe 
    }
}

void eliminareEchipa(scor** scoreCopy, Node** headCopy){
    //scor
    scor* scoreAux = (*scoreCopy)->next;
    Node* headAux = (*headCopy) ->next;

    (*scoreCopy)->next = scoreAux->next;
    (*headCopy)->next = headAux->next;

    //printf(" scor %d, nume: %s", scoreAux->points, headAux->val);

    free(scoreAux);
    free(headAux);
}

void Task2(FILE* fin, FILE* fout, Node* head){

    //nr echipe
    int nrEchipe;
    fscanf(fin, "%d", &nrEchipe);
    getc(fin);//skip linia cu nrEchipe

    //declarare tabela
    scor *tabela;
    tabela=NULL;

    creareTabela(&tabela, fin, nrEchipe);

    //am in ordine, lista cu echipe si cu scorul fiecareia pe aceeasi pozitie
    //calulez numarul de echipe ce trebuiesc eliminate

    int echipeRamase=1;
    if(nrEchipe <= 2) echipeRamase=nrEchipe;
    else while(echipeRamase*2 <= nrEchipe) echipeRamase*=2;

    int echipeEliminate = nrEchipe - echipeRamase;
    printf("%d ", echipeEliminate);
    /*while(head){
        printf("%d %s", tabela->points, head->val);
        head=head->next;
        tabela=tabela->next;
    }*/
    scor* scoreCopy = tabela;
    Node* headCopy= head;
    int scorMinim;
    for(int i=0; i<echipeEliminate; i++){
        
        scoreCopy = tabela;
        headCopy= head;

        scorMinim=9999;
        while(scoreCopy){
            if(scoreCopy->points < scorMinim) scorMinim=scoreCopy->points;
            scoreCopy=scoreCopy->next;
        }
        //am gasit scorul cel mai mic
        printf("%d \n", scorMinim);

        scoreCopy = tabela; 
        if(scoreCopy->points != scorMinim){     //iau in considerare si primul din lista sa fie cel mai mic scor.... testul 11
            while((scoreCopy->next)->points != scorMinim){
                scoreCopy = scoreCopy->next;
                headCopy = headCopy->next;
            }
        }
        //printf("este eliminata %d %s", headCopy->val, scoreCopy->points);

        //elementul urmator trebuie eliminat
        eliminareEchipa(&scoreCopy, &headCopy);
    }
    //while(head){printf("%s ", head->val); head=head->next;}
    //fileWrite(fout, head);
}