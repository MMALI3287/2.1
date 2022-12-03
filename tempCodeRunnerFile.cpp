#include <bits/stdc++.h>
using namespace std;

struct Bnode
{
    int key;
    struct Bnode *left, *right;
    Bnode(int key)
    {
        this->key = key;
        left = right = NULL;
    }
};

Bnode *insert(Bnode *node, int key)
{
    if (node == NULL)
    {
        node = new Bnode(key);
        return node;
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    return node;
}

void inorder(Bnode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main()
{
    Bnode *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);
    return 0;
}