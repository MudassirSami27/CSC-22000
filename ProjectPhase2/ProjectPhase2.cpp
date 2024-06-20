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
    newNode->Left = tail;  // left pointer of the newNode now points to tail node(newNode)
    
    if (tail != NULL) {
        tail->Right = newNode; // if current tail is not empty. Sets the right pointer of the current tail to the newNode
    }
    tail = newNode; // updates tail as the newNode
}

// Function to print elements from head to tail
void printElements(Node* n) {
    while (n != NULL) {
        cout << n->Data << " ";
        n = n->Right;
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
    Node* head = NULL;  // Start with an empty list
    Node* tail = NULL;  // Start with an empty list
   
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
