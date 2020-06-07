#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node *next;
    float val;
    struct Node *prev;

}node_t;

node_t* lastElement(node_t *node){
	node_t *temp;
	for(temp= node; temp->next != NULL; temp= temp->next){}
	return temp;
}

void appendLL(node_t *start, node_t *newNode){
/*
 * Append new node to end of linked list
 *Return 1 on sucess and 0 if failure
 *
 *start= first node in linked list
 *newNode= node to append
 * */
	node_t *lastElem= lastElement(start);
	lastElem->next= newNode;
}


int main(){
    node_t *LL= malloc(sizeof(node_t));
    LL->val= 5.5;
	node_t *node1= malloc(sizeof(node_t));
	node1->val=10;
	appendLL(LL, node1);
	printf("%f\n", (node1>val));

//	printf("%f\n", (LL->next)->val);
    
	free(LL);
	free(node1);
    return 0;
}

