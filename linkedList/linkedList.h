#include <stdlib.h>
#include <stdbool.h>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H



typedef struct Node {

  void *value;
  struct Node *next;
  
} Node;

typedef struct List {

  Node *front;
  Node *back;
  
} List;

//creates a pointer to an empty linked list
List *initialiseList(void);

//creates a pointer to a linked list node with i in value parameter
//and NULL in the next parameter
Node *createNewNode(void *i);

//frees all memory allocated to nodes and list
void freeList(List *list);

//finds the first node with value > i and returns it as curr
//also finds the last node with value < i and returns it as prev
void findNode(Node **prev, Node **curr, void *i, int (* comparator)(void  *, void *));

//adds a new node with value i such that there are no duplicates in the list and it is put in the correct position
bool add(List *list, void *i, int (* comparator)(void  *, void *));

//applied func to each element of the list
void applyToAll(List *list, void (*func)(void *));

//applied func to each element of the list and writes the result to a file
void applyToAllFile(List *list, FILE *fp, void (*func)(void *, FILE *fp));

//adds element to the front of the list regardles of the other elements in the list
void addToFront(List *l, void *value);

//adds element to the back of the list regardles of the other elements in the list
void addToBack(List *l, void *value);

#endif
