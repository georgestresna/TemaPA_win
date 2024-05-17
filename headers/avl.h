#include "list.h"

struct M{
    int height;
    Team echipa;
    struct M *left,*right;
};
typedef struct M avlNode; 


int nodeHeight(avlNode* root);
avlNode *RightRotation (avlNode *z);
avlNode *LeftRotation (avlNode *z);
avlNode* LRRotation(avlNode*Z);
avlNode* RLRotation(avlNode*Z);
avlNode* insertAVL(avlNode* node, Team key);
int max(int a, int b);