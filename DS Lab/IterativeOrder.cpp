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
    stack<Node *> Stack;
    Stack.push(root);
    while (!Stack.empty())
    {
        Node *temp = Stack.top();
        Stack.pop();
        cout << temp->data << ", ";
        if (temp->right)
        {
            Stack.push(temp->right);
        }
        if (temp->left)
        {
            Stack.push(temp->left);
        }
    }
}

void in_order(Node *root)
{
    stack<Node *> Stack;
    Node *temp = root;
    while (temp || !Stack.empty())
    {
        while (temp)
        {
            Stack.push(temp);
            temp = temp->left;
        }
        temp = Stack.top();
        Stack.pop();
        cout << temp->data << ", ";
        temp = temp->right;
    }
}

void post_order(Node *root)
{
    stack<Node *> Stack;
    Node *temp = root;
    Node *pre = NULL;
    while (temp || !Stack.empty())
    {
        while (temp)
        {
            Stack.push(temp);
            temp = temp->left;
        }
        temp = Stack.top();
        if (temp->right == NULL || temp->right == pre)
        {
            cout << temp->data << ", ";
            Stack.pop();
            pre = temp;
            temp = NULL;
        }
        else
        {
            temp = temp->right;
        }
    }
}

int main()
{
    create_tree();

    cout << "Pre order:" << endl;
    pre_order(root);
    cout << endl;

    cout << "In order:" << endl;
    in_order(root);
    cout << endl;

    cout << "Post order:" << endl;
    post_order(root);
    cout << endl;

    return 0;
}