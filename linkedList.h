// Allow initialization of Node and LinkedList without specifying struct
typedef struct Node Node;
typedef struct LinkedList LinkedList;

// Definition of Node Struct
struct Node {
    int data;
    Node* next;
};
// Declaration of Node Creation Function
Node* createNode(int data);

// Declaration of LinkedList Struct 
struct LinkedList {
    int size;
    Node* head;
    Node* tail;
};

// Declaration of LinkedList Creation and Copy Functions
LinkedList* createLinkedList(int data);
LinkedList* copyLinkedList(LinkedList* list);

// Declaration of typical List functions
Node* selectNode(LinkedList* list, int index);
void append(LinkedList* list, int data);
void insertNode(LinkedList* list, int index, int data);
void deleteNode(LinkedList* list, int index);
void printList(LinkedList* list);