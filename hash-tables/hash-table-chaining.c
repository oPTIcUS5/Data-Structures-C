#include <stdio.h>
#include <stdlib.h>
#include "t_colors.h"

#define SIZE 7

typedef struct Node
{
    int key;
    int value;
    struct Node * nextNode;
}Node;

typedef struct HashTable
{
    Node *array[SIZE];
}HashTable;


//functions
void initializeHashTable(HashTable *table);
int hashFunction(int key);
void insert(HashTable *table, int key, int value);
void displayHashTable(HashTable *table);

void initializeHashTable(HashTable *table)
{
    //code
    for (int i = 0; i < SIZE; i++)
    {
        table->array[i] = NULL;
    }
    printf(YELLOW"--<<<Hash table initialized>>>--\n"NORMAL);
}

int hashFunction(int key)
{
    return key % SIZE;
}


void insert(HashTable *table, int key, int value)
{
    int index = hashFunction(key);

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;

    newNode->nextNode = table->array[index];
    table->array[index] = newNode;

    printf(GREEN"inserted key: %d, value: %d, in index: %d\n"NORMAL, key, value, index);
}


void displayHashTable(HashTable *table)
{
    //code
    printf(GREEN"\n>>>>TABLE<<<<\n"NORMAL);
    for (int i = 0; i < SIZE; i++)
    {
        printf(CYAN "Box: %d\n" NORMAL, i);

        Node *auxiliar = table->array[i];
        while (auxiliar != NULL)
        {
            printf(YELLOW "[%d, %d] -> " NORMAL, auxiliar->key, auxiliar->value);
            auxiliar = auxiliar->nextNode;
        }
        printf(WHITE "[NULL]\n" NORMAL);
    }
}

int main(void)
{

    HashTable table;
    initializeHashTable(&table);

    insert(&table, 1, 2);
    insert(&table, 2, 90);
    insert(&table, 3, 100);

    displayHashTable(&table);

    return 0;
}
