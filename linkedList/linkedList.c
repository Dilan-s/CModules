#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "linkedList.h"

List *initialiseList(void) {
  
  List *result = (List *) (malloc(sizeof(List)));
  
  if (!result) {
    perror("Failed to allocate list memory");
    exit(EXIT_FAILURE);
  }
  result->front = result->back = NULL;
  
  return result;
  
}

Node *createNewNode(void *i) {

  Node *newNode = (Node *) (malloc(sizeof(Node)));

  if (!newNode) {
    perror("Failed to allocate list memory");
    exit(EXIT_FAILURE);
  }

  newNode->next = NULL;
  newNode->value = i;

  return newNode;
}

void freeList(List *list) {

  Node *curr = list->front;
  Node *prev = NULL;

  while (curr) {
    prev = curr;
    curr = curr->next;
    free(prev);
    prev = NULL;
  }

  free(list);
  list = NULL;

}

void findNode(Node **prev, Node **curr,  void *i, int (* comparator)(void  *, void *)) {
  while (*curr && (comparator((*curr)->value, i) != 0)){
    *prev = *curr;
    *curr = (*curr)->next;
  }
}

void applyToAll(List *list, void (*func)(void *)) {
  for (Node *curr = list->front; curr; curr = curr->next) {
    func(curr->value);
  }
}

void applyToAllFile(List *list, FILE *fp, void (*func)(void *, FILE *fp)) {
  for (Node *curr = list->front; curr; curr = curr->next) {
    func(curr->value, fp);
  }
}

bool add(List *list,  void *i, int (* comparator)(void  *, void *)) {

  if (!list) {
    return true;
  }

  Node *newNode = createNewNode(i);

  if (!(list->front)) {
    list->front = list->back = newNode; 
    return true;
  }

  Node *curr = list->front;
  Node *prev = NULL;

  findNode(&prev, &curr, i, comparator);

  if (curr) {
    return false;
    free(newNode);
  } else {
    prev->next = list->back = newNode;
    return true;
  }
}

void addToFront(List *l, void *value) {
  Node *item = createNewNode(value);
  
  // empty list case
  if (!l->front) {
    l->front = l->back = item;
    return;
  }

  // default case
  item->next = l->front;
  l->front = item;
}

void addToBack(List *l, void *value) {
  Node *item = createNewNode(value);
  
  // empty list case
  if (!l->front) {
    l->front = l->back = item;
    return;
  }

  // default case
  (l->back)->next = item;
  l->back = item;
}
