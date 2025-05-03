#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to build the binary tree recursively
Node* buildTree() {
    int data;
    cout << "Enter data for current node (-1 for NULL): ";
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    Node* root = new Node(data);

    cout << "Enter left child of " << root->data << ":\n";
    root->left = buildTree();

    cout << "Enter right child of " << root->data << ":\n";
    root->right = buildTree();

    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal (Root, Left, Right)
void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (Left, Right, Root)
void postorder(Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Sample Input for quick testing: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
int main() {
    Node* root = buildTree();

    cout << "\n----------------------\n";
    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);
    cout << "\n----------------------\n";

    return 0;
}
