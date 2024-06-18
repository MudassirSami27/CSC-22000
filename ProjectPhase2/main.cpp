#include <iostream>
using namespace std;

// Creating a simple double linked list and testing functions
struct Node{
    public:
        int Data;
        Node* Right;  // Next node is right node
        Node* Left;    // Previous node is left node
};

// Function to add a new node with value `data` to the tail of the list
void AddToTail(Node*& tail, int data) {
    Node* newNode = new Node;
    newNode->Data = data;  
    newNode->Right = NULL; // newNode is the tail so there should be nothing after
    newNode->Left = tail; // left pointer of the newNode now points to tail node(newNode)
    
    if (tail != NULL) {
        tail->Right = newNode; // if current tail is not empty. Sets the right pointer of the current tail to the newNode
    }
    tail = newNode; // updates tail as the newNode
}

// Function to print elements from head to tail
void printElements(Node* n){
    while (n != NULL) {
        cout << n->Data << endl;
        n = n->Right;
    }
}

// Function to print elements from tail to head
void printReverse(Node* x){
    while (x != NULL){
        cout << x->Data << endl;
        x = x->Left;
    }
}

int main(){
    // Initializing nodes
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* tail = new Node;

    head->Data = 1;
    head->Right = second;
    head->Left = NULL;

    second->Data = 2;
    second->Left = head;
    second->Right = third;

    third->Data = 3;
    third->Left = second;
    third->Right = tail;

    tail->Data = 5;
    tail->Left = third;
    tail->Right = NULL;

    cout << "BEFOR ADDING TO TAIL: " << endl;
    cout << "Print elements: " << endl;
    printElements(head);

    cout << "Print Reverse: " << endl;
    printReverse(tail);

    // Adding elements to the tail
    
    AddToTail(tail, 15);

    cout << "AFTER ADDING TO TAIL: " << endl;

    cout << "Print elements: " << endl;
    // Printing elements
    printElements(head);

    cout << "Print Reverse: " << endl;
    printReverse(tail);

    return 0;
}
