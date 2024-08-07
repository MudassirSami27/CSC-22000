#include <iostream>
using namespace std;

// Creating a simple double linked list and testing functions
struct Node {
    public:
        int Data;
        Node* Right;  // Next node is right node
        Node* Left;   // Previous node is left node
};

// Function to add a new node with value `data` to the tail of the list
void AddToTail(Node*& tail, int data) {
    Node* newNode = new Node;
    newNode->Data = data;
    newNode->Right = NULL; // newNode is the tail so there should be nothing after
    newNode->Left = tail;  // left pointer of the newNode points to current tail
    
    if (tail != NULL) {
        tail->Right = newNode; // if current tail is not empty. Sets the right pointer of the current tail to the newNode which is new tail
    }
    tail = newNode; // updates tail as the newNode
}

// Function to print elements from head to tail
void printElements(Node* n) {
    while (n != NULL) { // while there exist a node
        cout << n->Data << " "; // print the value
        n = n->Right; // go to the right node
    }
    cout << endl;
}

// Function to print elements from tail to head
void printReverse(Node* x) {
    while (x != NULL) { 
        cout << x->Data << " "; 
        x = x->Left;
    }
    cout << endl;
}

int main() {
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
    int num;
    do {
        cout << "Double Linked List Menu" << endl;
        cout << "Option 1: Add new element." << endl;
        cout << "Option 2: Print List elements." << endl;
        cout << "Option 3: Print List elements in reverse order." << endl;
        cout << "Option 4: Exit." << endl;
        cout << "Enter a number 1-4:" << endl;
        cin >> num;

        switch(num) {
            case 1:
                cout << "Enter value for new element..." << endl;
                int n;
                cin >> n;
                cout << "Adding new element..." << endl;
                if (head == NULL) {
                    // If the list is empty, initialize both head and tail
                    head = new Node;
                    head->Data = n;
                    head->Right = NULL;
                    head->Left = NULL;
                    tail = head;
                } else {
                    AddToTail(tail, n);
                }
                break;
            case 2:
                cout << "Printing List elements..." << endl;
                printElements(head);
                break;
            case 3:
                cout << "Printing List elements in reverse order..." << endl;
                printReverse(tail);
                break;
            case 4:
                cout << "Exiting..." << endl;
                status = false;
                break;
            default:
                cout << "Invalid option. Please enter a number 1-4:" << endl;
                break;
        }
    } while(status);

    // Clean up memory
    Node* current = head;
    while (current != NULL) {
        Node* next = current->Right;
        delete current;
        current = next;
    }

    return 0;
}
