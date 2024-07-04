#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    //acts similar to a constructor
    Node(int value){
        data = value;
        left = right = NULL;
    }
};

class BinaryTree{
    private:
    Node* root;

    void insert(Node*& node, int val) {
        if (node == NULL) {
            node = new Node(val); //if tree is empty add a new node that holds the value user selected
            count++;
        } else if (val < node->data) { 
            insert(node->left, val);
        } else { //if value is greater than the previous node set it as right child
            insert(node->right, val);
        }
    }
    void inorder(Node* node){ //will print the elements of the tree in chronological order (only for binary trees)
        if(node != NULL){
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
    void postorder(Node* node){
        if(node != NULL){
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }
    void preorder (Node* node){
        if(node != NULL){
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }
    public:
    int count = 0;
    BinaryTree(){
        root = NULL; //initializes an empty tree
    }
    //simplifying functions so the parameters are appropriate for the user without worrying about implementation
    void insert(int val){
        insert(root, val);
    }
    void inorder(){
        inorder(root);
    }
    void postorder(){
        postorder(root);
    }
    void preorder(){
        preorder(root);
    }
    int nodeCount(){
        return count;
    }
};

int main(){
    srand( time(NULL) );
    BinaryTree tree;
    int nodes = (rand() % 20) + 1;
    for(int i  = 1; i <= nodes; i++){
        tree.insert((rand() % 40) + 1);
    }

    int num;
    bool status = true;
    
    while(status){
        cout << "Tree List Menu" << endl;
        cout << "Option 1: Insert new number." << endl;
        cout << "Option 2: Print Tree." << endl;
        cout << "Option 3: Get Node count of the Tree." << endl;
        cout << "Option 4: Get Leaf count of Tree." << endl;
        cout << "Option 5: Generate new Tree." << endl;
        cout << "Option 6: Exit Program." << endl;        
        cout << "Enter a number 1-6:" << endl;
        cin >> num;

        switch(num){
            case 1:
                cout << "Enter value for new element..." << endl;
                int n;
                cin >> n;
                cout << "Adding new element..." << endl;
                tree.insert(n);
                break;
            case 2:
                cout << "Printing Tree in Preorder, Inorder, and Postorder..." << endl;
                cout << "Preorder Traversal: ";
                tree.preorder();
                cout << endl;
                cout << "Inorder Traversal: "; 
                tree.inorder();
                cout << endl;
                cout << "Postorder Traversal: ";
                tree.postorder();
                cout << endl;
                break;
            case 3: 
                cout << "Node count of Tree is: " << tree.nodeCount() << endl;
                break;
            case 4:
                cout << "Needs to be worked." << endl;
                break;
            case 5:
                cout << "Needs to be worked." << endl;
                break;
            case 6:
                cout << "Exiting...";
                status = false;
                break;
        }
    }
}