#include "linkedList.h"
#include "hashTable.h"

int hash(void *i){
  return 1;
}

HashTable *initialiseHashTable(){
  HashTable *hashTable = calloc(TABLE_SIZE, sizeof(List *));
  for (int i = 0; i < TABLE_SIZE; i++) {
    hashTable[i] = initialiseList();
  }
}

void freeHashTable(HashTable *hashTable) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    freeList(hashTable[i]);
  }
  free(hashTable[i]);
}

bool addHash(HashTable *hashTable, void *i, int (* comparator)(void  *, void *)) {
  int index = hash(i);
  return add(hashTable[index], i, comparator);
}

void applyToAllHash(HashTable *hashTable, void (*func)(void *)) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    applyToAll(hashTable[i], func);
  }
}

void applyToAllFileHash(HashTable *hashTable, FILE *fp, void (*func)(void *, FILE *fp)){
  for (int i = 0; i < TABLE_SIZE; i++) {
    applyToAllFile(hashTable[i], fp, func);
  }
}
