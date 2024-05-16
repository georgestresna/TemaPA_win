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
            top8 = Task3(r, head);
    }
    Node*aux=NULL; while(head){aux=head; head=head->next; free(aux);} aux=NULL;
    //int i=1; while(top8){printf("%d. %s %.2f\n", i, top8->echipa.numeEchipa, top8->echipa.scorEchipa); top8=top8->next; i++;}

    /*if(tasks[3] == 1){
        Task4(top8, r);
    }*/

    fclose(d);
    fclose(r);

    return 0;
}
