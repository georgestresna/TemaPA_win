struct Node{
    char val[100];
    struct Node *next;
};
typedef struct Node Node;

struct scor{
    int points;
    struct scor* next;
};
typedef struct scor scor;

void addAtBeginning(Node **head, char v[]);
void addAtEnd(Node** head, char v[]);
void deleteNode(Node **head, char v[]);
void addAtBeginningScore(scor **head, int value);

