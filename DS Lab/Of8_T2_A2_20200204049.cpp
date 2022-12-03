#include <bits/stdc++.h>
using namespace std;

struct BstNode
{
    int key;
    BstNode *left;
    BstNode *right;

    BstNode(int value)
    {
        key = value;
        this->left = NULL;
        this->right = NULL;
    }
};

bool search(BstNode *root, int key)
{
    if (root->key == key)
        return true;

    if (key < root->key && root->left != NULL)
        return search(root->left, key);
    else if (key > root->key && root->right != NULL)
        return search(root->right, key);
}

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

    cout << "Enter the key to be searched: ";
    cin >> n;
    if (search(root, n))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    return 0;
}