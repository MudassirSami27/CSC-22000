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
    Node* head = new Node;
    Node* tail = new Node;
    
    head->Data = 1;
    head->Right = tail;
    head->Left = NULL;

    tail->Data = 5;
    tail->Left = head;
    tail->Right = NULL;

    AddToTail(tail, 2);
    AddToTail(tail, 8);
    AddToTail(tail, 20);
    AddToTail(tail, 16);
    AddToTail(tail, 9);
    AddToTail(tail, 25);
    AddToTail(tail, 3);
    AddToTail(tail, 31);
    AddToTail(tail, 45);
    AddToTail(tail, 39);
    AddToTail(tail, 50);
    AddToTail(tail, 27);
    AddToTail(tail, 15);
 
    bool status = true;
    int num = 0;

    while(status){
        switch(num){
            case 0:
                cout << "Double Linked List Menu" << endl;
                cout << "Option 1: Add new element." << endl;
                cout << "Option 2: Print List elements." << endl;
                cout << "Option 3: Print List elements in reverse order." << endl;
                cout << "Option 4: Exit." << endl;
                cout << "Enter a number 1-4:" << endl;
                cin >> num;
                break;
            case 1:
                cout << "Enter value for new element..." << endl;
                int n;
                cin >> n;    
                cout << "Adding new element..." << endl;        
                AddToTail(tail, n);
                num = 0;
                break;
            case 2:
                cout << "Printing List elements..." << endl;
                printElements(head);
                num = 0;
                break;
            case 3:
                cout << "Printing List elements in reverse order..." << endl;
                printReverse(tail);
                num = 0;
                break;
            case 4:
                cout << "Exiting..." << endl;
                status = false;
                break;
        }
    }
    return 0;
}
