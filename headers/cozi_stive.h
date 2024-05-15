#include "list.h"

//stiva
struct Stiva{
    Team echipa;
    struct Stiva *next;
};
typedef struct Stiva Stiva;

//queue
struct Q{
    Stiva *front, *rear;
};
typedef struct Q Queue;


//stiva
void deleteStack(Stiva**top);
Team pop(Stiva**top);
void push(Stiva**top, Team v);
int isEmptyS(Stiva*top);
//cozi

Queue* createQueue();
void enQueue(Queue*q, Team v);
Team deQueue(Queue*q);
int isEmptyQ(Queue*q);
void deleteQueue(Queue*q);