/*
Single linked list
_____________    ____________     _____________
| Value | * |--> | Value| * | --> | Value | * |--> Null
-------------    ------------     -------------
    |                                    |
   HEAD                                 TAIL
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *nextNode;
}Node;

typedef struct LinkedList
{
    int size;
    Node *HEAD;
    Node *TAIL;
}LinkedList;

/* Create the linked list */
LinkedList *createList()
{
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));

    list->HEAD = NULL;
    list->TAIL = NULL;
    list ->size = 0;

    return list;
}

/* Create the Node */
Node *createNode(int value)
{
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->data = value;
    newNode->nextNode = NULL;

    return newNode;
}

/* Insert HEAD */
void pushFront(LinkedList *list, int value){

    Node *node = createNode(value);

    if (list->size == 0 && list->HEAD == NULL){
        list->HEAD = node;
        list->TAIL = node;
    } else{
        node->nextNode = list->HEAD;
        list->HEAD = node;
    }

    list->size++;
    printf("pushed %d at the HEAD of the list\n", value);
}

/* display LIST */
void displayList(LinkedList list){

    Node *auxiliar = NULL;

    if (list.size == NULL) 
        printf("NULL\n");
    else if (list.size == 1)
        printf("%d --> NULL\n", list.HEAD->data);
    else{
        auxiliar = list.HEAD;

        while (auxiliar != NULL) {
            printf("%d --> ", auxiliar->data);
            auxiliar = auxiliar->nextNode;
        }
        printf("Null\n");
    }
}

int main(void){

    LinkedList *list = createList();
    printf("Memory position of the list: %p\n", list);

    pushFront(list, 1);
    pushFront(list, 2);
    pushFront(list, 3);
    displayList(*list);

    return 0;
}
