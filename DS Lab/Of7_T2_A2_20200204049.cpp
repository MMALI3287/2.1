#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *root = NULL;

void create_tree()
{
    Node *two = new Node(2);
    Node *seven = new Node(7);
    Node *nine = new Node(9);
    Node *one = new Node(1);
    Node *six = new Node(6);
    Node *five = new Node(5);
    Node *ten = new Node(10);
    Node *eight = new Node(8);
    Node *three = new Node(3);
    Node *four = new Node(4);

    two->left = seven;
    two->right = nine;
    seven->left = one;
    seven->right = six;
    six->left = five;
    six->right = ten;
    nine->right = eight;
    eight->left = three;
    eight->right = four;

    root = two;
}

void push(int node)
{
    Node *temp = new Node(node);
    temp->left = root;
    root = temp;
}

int pop()
{
    root = root->left;
}

int top()
{
    return root->data;
}

bool empty()
{
    if (root == NULL)
        return true;
    return false;
}

void pre_order(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << "  -->  ";
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    in_order(root->left);
    cout << root->data << "  -->  ";
    in_order(root->right);
}

void post_order(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    cout << root->data << "  -->  ";
}

int main()
{
    create_tree();

    cout << "Pre order:  ";
    pre_order(root);
    cout << "END";
    cout << endl
         << endl;

    cout << "In order:  ";
    in_order(root);
    cout << "END";
    cout << endl
         << endl;

    cout << "Post order:  ";
    post_order(root);
    cout << "END";

    return 0;
}