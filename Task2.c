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

void writeTask2(FILE* fout, Node* head){
    while(head){
        fputs(head->val, fout);
        head=head->next;
    }
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

    int echipeRamase=1;
    if(nrEchipe <= 2) echipeRamase=nrEchipe;
    else while(echipeRamase*2 <= nrEchipe) echipeRamase*=2;

    while(nrEchipe > echipeRamase){
        //printf("iter- ");
        scor* scoreCopy = tabela;
        Node* headCopy= head;

        int scorMinim=9999;
        while(scoreCopy){
            if(scoreCopy->points < scorMinim) scorMinim=scoreCopy->points;
            scoreCopy=scoreCopy->next;
        }
        deleteScore(&tabela, &head, scorMinim);
        nrEchipe--;
    }
    writeTask2(fout, head);
    /*while(head){
        printf("%s", head->val);
        head=head->next;
    }*/
}