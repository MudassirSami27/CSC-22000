#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    //acts similar to a constructor
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree{
    private:
    Node* root;

    // Recursive function to insert a new value into the tree
    void insert(Node*& node, int val) {
        if (val < 1 || val > 40){
            cout << "Value is not within range please input value within the range 1 to 40" << endl;
            return;
        }
        // Base case: if the current node is null, create a new node with the value
        if (node == NULL) {
            node = new Node(val); //if tree is empty add a new node that holds the value user selected
        } 
        // Recursive case: if the value is less than the current node's data, insert into the left subtree
        else if (val < node->data) { 
            insert(node->left, val);
        } 
        // Recursive case: if the value is greater than or equal to the current node's data, insert into the right subtree
        else { //if value is greater than the previous node set it as right child
            insert(node->right, val);
        }
    }

    // Recursive function for inorder traversal
    void inorder(Node* node){ //will print the elements of the tree in chronological order (only for binary trees)
        if(node != NULL){
            inorder(node->left);    // Recursively traverse left subtree
            cout << node->data << " ";  // Process current node
            inorder(node->right);   // Recursively traverse right subtree
        }
    }

    // Recursive function for postorder traversal
    void postorder(Node* node){
        if(node != NULL){
            postorder(node->left);   // Recursively traverse left subtree
            postorder(node->right);  // Recursively traverse right subtree
            cout << node->data << " ";  // Process current node
        }
    }

    // Recursive function for preorder traversal
    void preorder (Node* node){
        if(node != NULL){
            cout << node->data << " ";  // Process current node
            preorder(node->left);   // Recursively traverse left subtree
            preorder(node->right);  // Recursively traverse right subtree
        }
    }

    // Recursive function to count the number of leaves in the tree
    int countLeaves(Node* node) {
        // Base case: if node is null, return 0
        if (node == NULL) return 0;
        // Base case: if node is a leaf (no children), return 1
        if (node->left == NULL && node->right == NULL) return 1;
        // Recursive case: sum of leaves in left and right subtrees
        return countLeaves(node->left) + countLeaves(node->right);
    }

    // Recursive function to create a new tree with doubled values
    Node* doubleTree(Node* node) {
        // Base case: if node is null, return null
        if (node == NULL) return NULL;
        // Create a new node with doubled value
        Node* newNode = new Node(node->data * 2);
        // Recursively create left and right subtrees
        newNode->left = doubleTree(node->left);
        newNode->right = doubleTree(node->right);
        return newNode;
    }

  

    public:
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
        return countNodes(root);
    }
    void TreeTraversal(){
        cout << "Inorder Traversal: " << endl;
        inorder();
        cout << "\nPostorder Traversal: " << endl;
        postorder();
        cout << "\nPreorder Traversal: " << endl;
        preorder();
    }

    // Recursive function to count the total number of nodes in the tree
    int countNodes(Node* node) {
        // Base case: if node is null, return 0
        if (node == NULL) return 0;
        // Recursive case: 1 (current node) + nodes in left subtree + nodes in right subtree
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int leafCount() {
        return countLeaves(root);
    }

    BinaryTree generateDoubledTree() {
        BinaryTree newTree;
        newTree.root = doubleTree(root);
        return newTree;
    }
};

int main(){
    srand(time(NULL));
    BinaryTree tree;
    int nodes = (rand() % 20) + 1;
    for(int i = 1; i <= nodes; i++){
        tree.insert((rand() % 40) + 1);
    }

    int num;
    bool status = true;
    
    while(status){
        cout << "\nTree List Menu" << endl;
        cout << "Option 1: Insert new number." << endl;
        cout << "Option 2: Print Tree." << endl;
        cout << "Option 3: Get Node count of the Tree." << endl;
        cout << "Option 4: Get Leaf count of Tree." << endl;
        cout << "Option 5: Generate new Tree." << endl;
        cout << "Option 6: Exit Program." << endl;        
        cout << "Enter a number 1-6: ";
        cin >> num;

        switch(num){
            case 1:
                cout << "Enter value for new element: ";
                int n;
                cin >> n;
                cout << "Adding new element..." << endl;
                tree.insert(n);
                break;
            case 2:
                cout << "Printing Tree in Preorder, Inorder, and Postorder..." << endl;
                tree.TreeTraversal();
                cout << endl;
                break;
            case 3: 
                cout << "Node count of Tree is: " << tree.nodeCount() << endl;
                break;
            case 4:
                cout << "Leaf count of Tree is: " << tree.leafCount() << endl;
                break;
            case 5: {
                cout << "Generating new tree with doubled values..." << endl;
                BinaryTree doubledTree = tree.generateDoubledTree();
                cout << "New tree in Preorder: ";
                doubledTree.preorder();
                cout << "\nNew tree in Inorder: ";
                doubledTree.inorder();
                cout << "\nNew tree in Postorder: ";
                doubledTree.postorder();
                cout << endl;
                break;
            }
            case 6:
                cout << "Exiting...";
                status = false;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
    return 0;
}