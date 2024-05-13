#include "Player.h"

struct Node{
    Team *echipa;
    struct Node *next;
};
typedef struct Node Node;

void addAtBeginning(Node **head, Team *v);
void deleteNode(Node **head, float scorMinim);
