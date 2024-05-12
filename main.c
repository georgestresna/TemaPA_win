#include <stdio.h>
#include <stdlib.h>
#include "./headers/list.h"
#include "./headers/main.h"
#include "./headers/Player.h"


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
    rewind(r);
    //if(tasks[1] == 1) Task2(d, r, head);   //task2


    //de test
    /*
    FILE* fin=fopen("./date/t1/d.in", "r");
    FILE* fout=fopen("r.out", "w");
    Task1(fin, fout);

    fclose(fin);
    fclose(fout);*/
    fclose(c);
    fclose(d);
    fclose(r);

    return 0;
}
