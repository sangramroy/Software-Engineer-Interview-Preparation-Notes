#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to insert a node into the BST
Node* buildBSTTree(Node* root, int target) {
    if (root == NULL) {
        return new Node(target);
    }

    if (target < root->data) {
        root->left = buildBSTTree(root->left, target);
    } else {
        root->right = buildBSTTree(root->right, target);
    }

    return root;
}

// Inorder Traversal: Left, Root, Right
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal: Root, Left, Right
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal: Left, Right, Root
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;

    vector<int> v = {19, 67, 39, 98, 7, 94, 12, 78, 32, 1, 5, 888};
    for (int val : v) {
        root = buildBSTTree(root, val);
    }

    cout << "Inorder Traversal (Sorted BST):\n";
    inorder(root);

    cout << "\n\nPreorder Traversal:\n";
    preorder(root);

    cout << "\n\nPostorder Traversal:\n";
    postorder(root);

    cout << "\n";
    return 0;
}
