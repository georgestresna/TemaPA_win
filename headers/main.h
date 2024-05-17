#include <stdio.h>
#include <stdlib.h>
//#include "Player.h"

Node* Task1(FILE* fin, FILE* fout);
Node* Task2(FILE* fin, FILE* fout, Node* head);
void Task3(FILE* fout, Node* head, Node**last8);
void Task4(Node*last8, FILE* fout, Node**ranked8);
void Task5(Node* head, FILE* fout);