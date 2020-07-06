#include <stdbool.h>
#ifndef TREE_H
#define TREE_H

typedef struct Tree_elem {
  void *value;
  struct Tree_elem *left;
  struct Tree_elem *right;
} Node;

typedef struct {
  Node *base;
} Root;

Root *initialiseTree(void);

Node *createNewNode(void *i);

void freeTree(Root *root, void (*freeValue)(void *));

void freeNode(Node *node, void (*freeValue)(void *));

bool find(Root *root, void *val,int (*comparator)(void *, void *));

bool add(Root *root, void *val, int (*comparator)(void *, void *), void (*freeValue)(void *));

void applyToAll(Root *root, void (*func)(void *));

void printAll(Root *root, void (*func)(void *));
#endif
