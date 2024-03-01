#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

// Create an individual Linked List Node that stores `data`
Node* createNode(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Create a Linked List, where list[0] = `data`
LinkedList* createLinkedList(int data) {
    LinkedList* list = malloc(sizeof(LinkedList));
    list->head = createNode(data);
    list->tail = list->head;
    list->size = 1;
    return list;
}
// Create a copy of a pre-made Linked List
LinkedList* copyLinkedList(LinkedList* list) {
    Node* indexNode = list->head;

    LinkedList* newList = createLinkedList(indexNode->data);

    indexNode = indexNode->next;

    for (int i = 1; i < list->size; i++) {
        append(newList, indexNode->data);
        indexNode = indexNode->next;
    }

    return newList;
}
// Deallocate the used memory of a Linked List
void deleteLinkedList(LinkedList* list) {
    Node* indexNode = list->head;

    for (int i = 0; i < list->size; i++) {
        Node* deleted = indexNode;
        indexNode = indexNode->next;
        free(deleted);
    }

    free(list);
}

// Get the Linked List Node from `list` at index `index`
Node* selectNode(LinkedList* list, int index) {
    // makes sure the index is not out of range
    if (index > list->size && index >= 0) {
        return NULL;
    }

    // Gets the Node at that index
    Node* indexNode = list->head;
    for (int i = 0; i < index; i++) {
        indexNode = indexNode->next;
    }

    return indexNode;
}
// Append the number `data` to the end of Linked List `list`
void append(LinkedList* list, int data) {
    // get the last Node of the list
    Node* indexNode = list->head;
    for (int i = 0; i < list->size - 1; i++) {
        indexNode = indexNode->next;
    }
    // create new Node based on the data
    Node* newNode = createNode(data);
    indexNode->next = newNode;

    // updates the list size
    list->size++;
}
// Insert a Linked List Node with data `data` at index `index` (becomes the index) in Linked List `list`
void insertNode(LinkedList* list, int index, int data) {
    // Makes sure the index is not out of range
    if (index > list->size && index >= 0) {
        return;
    }

    // gets the Node at that index
    Node* indexNode = list->head;
    for (int i = 0; i < index; i++) {
        indexNode = indexNode->next;
    }

    // creates a new Node nad inserts it t that location (index -> new -> next)
    Node* newNode = createNode(data);
    newNode->next = indexNode->next;
    indexNode->next = newNode;

    // updates the size of the list
    list->size++;
}
// Deletes the Linked List Node at index `index`, and makes the new tail point to `index` + 1 in Linked List `list`
void deleteNode(LinkedList* list, int index) {
    // makes sure the index in not out of range
    if (index > list->size && index >= 0) {
        return;
    }

    // gets the Node at one under that index
    Node* indexNode = list->head;
    for (int i = 0; i < index - 1; i++) {
        indexNode = indexNode->next;
    }

    // saves the deleted node and resets the previous index's address to the proper address;
    Node* deleted = indexNode->next;
    indexNode->next = indexNode->next->next;

    // frees the deleted node
    free(deleted);

    // updates the size of the list
    list->size--;
}
// Print out the contents of Linked List `list`
void printList(LinkedList* list) {
    // gets the first Node
    Node* indexNode = list->head;

    // prints the data of each Node
    for (int i = 0; i < list->size; i++) {
        printf("%d->", indexNode->data);
        indexNode = indexNode->next;
    }
    printf("NULL\n");
}
