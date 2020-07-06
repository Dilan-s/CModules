#include <stdlib.h>
#include <stdbool.h>

#ifndef HASHTABLE_H
#define HASHTABLE_H

#define TABLE_SIZE 20

typedef **List HashTable;

int hash(void *i);
//creates a pointer to an empty linked list
HashTable *initialiseHashTable(void);

//frees all memory allocated to nodes and list
void freeHashTable(HashTable *hashTable);

//adds a new node with value i such that there are no duplicates in the list and it is put in the correct position
bool addHash(HashTable *hashTable, void *i, int (* comparator)(void  *, void *));

//applied func to each element of the list
void applyToAllHash(HashTable *hashTable, void (*func)(void *));

//applied func to each element of the list and writes the result to a file
void applyToAllFileHash(HashTable *hashTable, FILE *fp, void (*func)(void *, FILE *fp));


#endif
