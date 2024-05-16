//#include "Player.h"
#include "list.h"

struct N{
    Team echipa;
    struct N *left, *right;
};
typedef struct N treeNode;

void initTree(treeNode **root, Team d);
int isEmpty (treeNode *root);
int isInterior(treeNode*n);
int isLeaf(treeNode*n);

treeNode* newNode(Team v);
treeNode* insert(treeNode* node, Team v);
