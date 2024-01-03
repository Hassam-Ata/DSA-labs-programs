#include <iostream>
using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

BSTNode* insertNode(BSTNode* rootPtr, int value) {
    if (rootPtr == nullptr) {
        return new BSTNode(value);
    }

    if (value <= rootPtr->data) {
        rootPtr->left = insertNode(rootPtr->left, value);
    } else {
        rootPtr->right = insertNode(rootPtr->right, value);
    }

    return rootPtr;
}

void inorderTraversal(BSTNode* rootPtr) {
    if (rootPtr != nullptr) {
        inorderTraversal(rootPtr->left);
        cout << rootPtr->data << " ";
        inorderTraversal(rootPtr->right);
    }
}

int main() {
    BSTNode* rootPtr = nullptr;

    // Inserting nodes: 15, 10, 20, 25, 8, 12
    rootPtr = insertNode(rootPtr, 15);
    rootPtr = insertNode(rootPtr, 10);
    rootPtr = insertNode(rootPtr, 20);
    rootPtr = insertNode(rootPtr, 25);
    rootPtr = insertNode(rootPtr, 8);
    rootPtr = insertNode(rootPtr, 12);

    // Printing the tree using inorder traversal to display sorted values
    cout << "Inorder Traversal of BST: ";
    inorderTraversal(rootPtr);
    cout << endl;

    return 0;
}
