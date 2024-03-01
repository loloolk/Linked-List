#include "linkedList.c"
#include <string.h>

int main() {
    // Initiallize a linked list that starts with 1
    LinkedList* list = createLinkedList(1);

    // Create a buffer for the iser input
    int guess;

    // Append the user input to the linked list, until the input equals zero
    while (guess != 0) {
        printf("Enter a number: ");
        scanf("%d", &guess);
        append(list, guess);
    }

    // Display the list
    printList(list);
}