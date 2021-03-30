#ifndef LINKED_LIST
#define LINKED_LIST
typedef struct Node node_t;

node_t* initNode();

node_t* lastElement(node_t *node);

void appendLL(node_t *list, node_t *newNode);

void insertAfter(node_t **list, node_t *nodeBefore, node_t *newNode);

void removeNode(node_t **list , node_t *nodeRemove);

void freeList(node_t *list);

void printAll(node_t *list);
#endif
