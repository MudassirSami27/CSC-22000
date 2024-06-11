#include <iostream>
using namespace std;

//Creating a simple double linked list and testing functions
struct Node{
    public:
        int Data;
        Node* Right;
        Node* Left;
};
void printElements(Node* n){
    while (n != NULL)
    {
        cout << n->Data << endl;
        n = n->Right;
    }
}
void printReverse(Node* x){
    while (x != NULL){
        cout << x->Data << endl;
        x = x->Left;
    }
}

int main(){
    //initializing nodes
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

    printElements(head);
    printReverse(tail);
    return 0;
}