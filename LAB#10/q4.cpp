#include <iostream>
#include <queue>
using namespace std;
// Define the structure for a tree node
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    // Constructor to initialize a new node
    TreeNode(int value) : data(value), left(nullptr), right(nullptr)
    {
    }
};
// Function to build a sample binary tree
TreeNode *buildTree()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}
void levelOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        if (temp == nullptr)
        {
            cout << endl; // previous level completely traversed
            if (!q.empty())
            {
                // queue still has some child nodes
                q.push(nullptr);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void mirrorTree(TreeNode *root)
{
    if (root == nullptr)
        return;
    swap(root->left, root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);
}
int main()
{
    TreeNode *root = buildTree();
    cout << "Original Tree:" << endl;
    levelOrderTraversal(root);
    cout << "\nMirror Image:" << endl;
    mirrorTree(root);
    levelOrderTraversal(root);
    return 0;
}