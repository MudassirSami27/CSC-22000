#include <iostream>
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
        } else if (val < node->data) { 
            insert(node->left, val);
        } else { //if value is greater than the previous node set it as right child
            insert(node->right, val);
        }
    }
    void inorder(Node* node){ //will print the elements of the tree in chronological order (only for binary trees)
        if(node != NULL){
            inorder(node->left);
            cout << node->data << " " << endl;
            inorder(node->right);
        }
    }
    void postorder(Node* node){
        if(node != NULL){
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " " << endl;
        }
    }
    void preorder (Node* node){
        if(node != NULL){
            cout << node->data << " " << endl;
            preorder(node->left);
            preorder(node->right);
        }
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
};

int main(){
    BinaryTree tree;
    tree.insert(4);
    tree.insert(11);
    tree.insert(21);
    tree.insert(32);
    tree.insert(30);
    tree.insert(18);
    tree.insert(7);
    tree.insert(3);
    tree.insert(10);
    tree.insert(6);
    tree.insert(25);
    tree.insert(12);
    tree.insert(2);
    tree.insert(29);
    tree.insert(27);

    cout << "Inorder Traversal" << endl;
    tree.inorder();
    cout << "Postorder Traversal" << endl;
    tree.postorder();
    cout << "Preorder Traversal" << endl;
    tree.preorder();
}