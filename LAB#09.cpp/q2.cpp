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

BSTNode* minValueNode(BSTNode* node) {
    BSTNode* current = node;

    while (current->left != nullptr) {
        current = current->left;
    }

    return current;
}

BSTNode* deleteNode(BSTNode* rootPtr, int value) {
    if (rootPtr == nullptr) {
        return rootPtr;
    }

    if (value < rootPtr->data) {
        rootPtr->left = deleteNode(rootPtr->left, value);
    } else if (value > rootPtr->data) {
        rootPtr->right = deleteNode(rootPtr->right, value);
    } else {
        if (rootPtr->left == nullptr) {
            BSTNode* temp = rootPtr->right;
            delete rootPtr;
            return temp;
        } else if (rootPtr->right == nullptr) {
            BSTNode* temp = rootPtr->left;
            delete rootPtr;
            return temp;
        }

        BSTNode* temp = minValueNode(rootPtr->right);
        rootPtr->data = temp->data;
        rootPtr->right = deleteNode(rootPtr->right, temp->data);
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

    // Printing the original BST
    cout << "Original BST: ";
    inorderTraversal(rootPtr);
    cout << endl;

    // Deleting nodes: 10, 20
    rootPtr = deleteNode(rootPtr, 10);
    rootPtr = deleteNode(rootPtr, 20);

    // Printing the BST after deletion
    cout << "BST after deletion: ";
    inorderTraversal(rootPtr);
    cout << endl;

    return 0;
}
