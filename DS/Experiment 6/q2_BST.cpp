/*
2. Write a program to create a Binary search tree and perform traversal ( pre-order, post-order, In-order)
*/
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* createNode(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node *root, int data) {
    if (root == NULL)   root = createNode(data);
    else if (data <= root->data)    root->left = insert(root->left, data);
    else    root->right = insert(root->right, data);
    return root;
}

void preOrderTraversal(Node *root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root) {
    if (root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);
/*
      5
     / \
    3   7
   / \ / \
  2  4 6  8

*/
    cout << "Pre-order traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;

    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}
