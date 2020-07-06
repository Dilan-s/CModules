#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int intComparator(void *first, void *second) {
  int fir = *((int *) first);
  int sec = *((int *) second);
  return fir - sec;
}

void freeInt(void *s) {
}

void printNumber(void *val) {
  printf("%d\n", *((int *) val));
}

int main() {
  Root *root = initialiseTree();
  int n1 = 8;
  int n2 = 5;
  int n3 = 15;
  int n4 = 3;
  int n5 = 6;
  int n6 = 12;
  int n7 = 17;
  add(root, &n1, intComparator, freeInt);
  add(root, &n2, intComparator, freeInt);
  add(root, &n3, intComparator, freeInt);
  add(root, &n4, intComparator, freeInt);
  add(root, &n5, intComparator, freeInt);
  add(root, &n6, intComparator, freeInt);
  add(root, &n7, intComparator, freeInt);
  printAll(root, printNumber);
  freeTree(root, freeInt);
  printf("success\n");
  return 0;

}
