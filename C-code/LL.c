//Doubly linked list of floats
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node *next;
    float val;
    struct Node *prev;

}node_t;

node_t* initNode(){
/*
Initialize a new Node and return a pointer to it.
Node is initialized with malloc.
   */
	node_t *LL= malloc(sizeof(node_t));
	return LL;
}

node_t* lastElement(node_t *node){
/*
Return a pointer to the last node in the linked list
   */
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

void insertAfter(node_t **list, node_t *nodeBefore, node_t *newNode){
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

void removeNode(node_t **list , node_t *nodeRemove){
/*
Remove node <nodeRemove> from linked list <list>. The node is then freed.
*/
	//if removing first node, pointer to LL must be shifted to next node
	if(nodeRemove == *list){
		*list= (*list)->next;
		(*list)->prev= NULL;
		free(nodeRemove);
		return;
	}
	(nodeRemove->prev)->next= nodeRemove->next;
	if(nodeRemove->next != NULL){
		(nodeRemove->next)->prev= nodeRemove->prev;
	}
	free(nodeRemove);
}

void freeList(node_t *list){
/*
Given a pointer to a linked list, free all nodes in the list
   */
	node_t *temp;
	for(temp= list; temp != NULL; list= temp){
		temp= list->next;
		printf("freeing: %f\n", list->val);
		free(list);
	}
}

void printAll(node_t *list){
/*
Print all the values of nodes in a given linked list for testing purposes.
*/
	node_t *temp;
	int index= 0;
	for(temp= list; temp != NULL; temp= temp->next){
		printf("Node %d: %f\n", index, temp->val);
		index++;
	}
}

int main(){
	//1
    node_t *LL= malloc(sizeof(node_t));
    LL->val= 1.0;

	//1->2
	node_t *node2= malloc(sizeof(node_t));
	node2->val=2.0;
	appendLL(LL, node2);

	//3->1->2
	node_t *node3= malloc(sizeof(node_t));
	node3->val= 3.0;
	insertAfter(&LL, NULL, node3);

	//3->1->4->2
	node_t *node4= malloc(sizeof(node_t));
	node4->val= 4.0;
	insertAfter(&LL, LL->next, node4);
	
	//after removing, 1->4->2
	removeNode(&LL, LL);

	printAll(LL);
	freeList(LL);

    return 0;
}

