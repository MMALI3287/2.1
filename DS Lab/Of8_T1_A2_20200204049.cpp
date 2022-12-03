#include <bits/stdc++.h>
using namespace std;

struct BstNode
{
    int key;
    BstNode *left, *right;

    BstNode(int value)
    {
        key = value;
        this->left = NULL;
        this->right = NULL;
    }
};

BstNode *insert(BstNode *node, int key)
{
    if (node == NULL)
        return new BstNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

void Print(BstNode *root)
{
    if (root != NULL)
    {
        Print(root->left);
        cout << root->key << " --> ";
        Print(root->right);
    }
}

int main()
{
    BstNode *root = NULL;
    int n;

    cout << "Enter the elements to be inserted in the tree: ";
    cin >> n;

    root = insert(root, n);
    do
    {
        cout << "Enter the elements to be inserted in the tree: ";
        cin >> n;
        insert(root, n);
    } while (sizeof(n) == sizeof(int));

    cout << "\nInorder traversal of the created binary search tree \n";
    Print(root);
    cout << "END" << endl;

    return 0;
}
