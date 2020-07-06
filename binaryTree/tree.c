#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


Root *initialiseTree(void) {
  Root *tree = calloc(sizeof(Root *), 1);
  return tree;
}

Node *createNewNode(void *i) {
  Node *newNode = calloc(sizeof(Node *), 1);
  newNode->value = i;
  return newNode;
}

void freeNode(Node *node, void (*freeValue)(void *)){
  if (!node){
	return;
  }
  freeValue(node->value);
  freeNode(node->left, freeValue);
  freeNode(node->right, freeValue);
  free(node);
}

void freeTree(Root *root, void (*freeValue)(void *)){
  freeNode(root->base, freeValue);
  free(root);
}

static bool findNode(Node *node, void *val, int (*comparator)(void *, void *)){
  Node *pos = node;
  int comparison;
  while (pos && !(comparison = comparator(val, pos->value))){
	if (comparison < 0) {
	  pos = node->left;
	} else {
	  pos = node->right;
	}
  }
  return pos;
}

bool find(Root *root, void *val,int (*comparator)(void *, void *)){
  return findNode(root->base, val, comparator);
}

static Node *addNode(Node *node, void *val, int (*comparator)(void *, void *)){
  Node *curr, *prev;
  curr = prev = node;
  int comparison;
  do {
	comparison = comparator(val, curr->value);
	prev = curr;
	if (comparison < 0) {
	  curr = prev->left;
	} else {
	  curr = prev->right;
	}
  } while(curr && 0 != comparison);
  return prev;
}

static void rebalance(Node *node){

}

bool add(Root *root, void *val, int (*comparator)(void *, void *), void (*freeValue)(void *)){
  Node *newNode = createNewNode(val);
  if (!root->base) {
	root->base = newNode;
	return true;
  }
  Node *pos = addNode(root->base, newNode->value, comparator);
  int comparison = comparator(newNode->value, pos->value);
  if (!comparison) {
	free(newNode);
	return false; //MUST FREE VAL!!!
  }
  if (comparison < 0) {
	pos->left = newNode;
  } else {
	pos->right = newNode;
  }
  rebalance(pos);
  return true;
}

static void printIndent(int indent) {
  for (int i = 0; i < indent; i++) {
	printf("\t");
  }
}

static void printNode(Node *node, void (*func)(void *), int indent) {
  if (!node) {
	return;
  }
  printIndent(indent);
  func(node->value);
  printIndent(indent);
  printf("left\n");
  printNode(node->left, func, indent + 1);
  printIndent(indent);
  printf("right\n");
  printNode(node->right, func, indent + 1);  
}

void printAll(Root *root, void (*func)(void *)){
  printNode(root->base, func, 0);
}

static void applyToAllNode(Node *node, void (*func)(void *)) {
  if (!node) {
	return;
  }
  func(node->value);
  applyToAllNode(node->left, func);
  applyToAllNode(node->right, func);  
}


void applyToAll(Root *root, void (*func)(void *)){
  applyToAllNode(root->base, func);
}



