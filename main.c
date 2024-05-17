#include <stdio.h>
#include <stdlib.h>
#include "./headers/list.h"
#include "./headers/main.h"
//#include "./headers/cozi_stive.h"

int main(int argc, char *argv[]){

    //actual
    FILE *c=fopen(argv[1], "r");
    FILE *d=fopen(argv[2], "r");
    FILE *r=fopen(argv[3], "w");

    int tasks[5];
    fscanf(c, "%d %d %d %d %d", &tasks[0], &tasks[1], &tasks[2], &tasks[3], &tasks[4]);
    fclose(c);

    Node* head=NULL;
    if(tasks[0] == 1) head=Task1(d, r);     //task1
    rewind(d);

    if(tasks[1] == 1){      
        fclose(r);  
        r = fopen(argv[3], "w");            //task2
        head = Task2(d, r, head);
    }
    //fclose(r);
    //r=fopen(argv[3], "a");
    Node*top8=NULL;
    if(tasks[2] == 1){                      //task3
            Task3(r, head, &top8);
    }
    Node*aux=NULL; while(head){aux=head; head=head->next; free(aux);} aux=NULL;

    Node*ranked8=NULL;
    if(tasks[3] == 1){
        Task4(top8, r, &ranked8);           //task4
    }
    //while(ranked8){printf("%s %.2f\n", ranked8->echipa.numeEchipa, ranked8->echipa.scorEchipa); ranked8=ranked8->next;}
    while(top8){aux=top8; top8=top8->next; free(aux);} aux=NULL;
    
    Node*rankedDesc=NULL;
    while(ranked8){
        Node* rankedNode=(Node*)malloc(sizeof(Node));
        rankedNode->echipa=ranked8->echipa;
        rankedNode->next=rankedDesc;
        rankedDesc=rankedNode;

        ranked8=ranked8->next;
    }

    if(tasks[4] == 1){
        Task5(rankedDesc, r);
    }

    fclose(d);
    fclose(r);

    return 0;
}
