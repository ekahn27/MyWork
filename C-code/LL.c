//Doubly linked list
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

void appendLL(node_t *list, node_t *newNode){
/*
 * Append new node to end of linked list
 *
 *list= pointer to linked list
 *newNode= node to append
 * */
	node_t *lastElem= lastElement(list);
	lastElem->next= newNode;
}

void insertBetween(node_t **list, node_t *nodeBefore, node_t *newNode){
/*
Append a new node anywhere in the linked list, after <nodeBefore>
If <nodeBefore> is NULL, append to list of the list.
Assumes nodeBefore is a valid node in the same list as node list.

list= pointer to linked list
nodeBefore= node that we want to append our new node after
newNode= node to insert
*/
	//Insert at front of LL
	if(nodeBefore == NULL){
		newNode->next= *list;
		(*list)->prev= newNode;
		(*list)= newNode;
		return;
	}
	//insert anywhere else in LL
	node_t *nodeAfter= nodeBefore->next;
	nodeBefore->next= newNode;
	newNode->prev= nodeBefore;
	newNode->next= nodeAfter;
	nodeAfter->prev= newNode;
}

void removeNode(node_t *list , node_t *nodeRemove){
}

void freeAll(node_t *list){
/*
Given a pointer to a linked list, free all nodes in the list
   */
	node_t *temp;
	for(temp= list; temp != NULL; list= temp){
		temp= list->next;
		free(list);
	}
}

void printAll(node_t *list){
	node_t *temp;
	int index= 0;
	for(temp= list; temp != NULL; temp= temp->next){
		printf("Node %d: %f\n", index, temp->val);
		index++;
	}
}

int main(){
    node_t *LL= malloc(sizeof(node_t));
    LL->val= 1.0;
	node_t *node2= malloc(sizeof(node_t));
	node2->val=2.0;
	//appendLL(LL, node2);
	insertBetween(&LL, NULL, node2);
	//printf("First node value: %f\n", LL->val);
	//printf("Node 2 value: %f\n", (LL->next)->val);
	//printf("Node 1 value: %f\n", (node2->val));
	printAll(LL);
    
	freeAll(LL);
    return 0;
}

