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

struct Tuples
{
    Node *p;
    int i;

    Tuples(Node *n, int x)
    {
        p = n;
        i = x;
    }
    void setI(int x)
    {
        i = x;
    }
    int getPVal()
    {
        return p->data;
    }
    Node *left()
    {
        return p->left;
    }
    Node *right()
    {
        return p->right;
    }
};

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

bool empty()
{
    if (root == NULL)
        return true;
    return false;
}

void push(int node)
{
    Node *temp = new Node(node);
    temp->left = root;
    root = temp;
}

int front()
{
    return root->data;
}

void pop()
{
    root = root->left;
}

int top()
{
    return root->data;
}

void pre_orderIterativePrint(Node *node)
{
    stack<Tuples> st;
    Tuples t = Tuples(node, 1);
    st.push(t);

    while (!st.empty())
    {
        t = st.top();
        st.pop();

        if (t.p != NULL)
        {
            switch (t.i)
            {
            case 1:
            {
                t.setI(2);
                st.push(t);
                cout << t.getPVal() << "  -->  ";
                break;
            }
            case 2:
            {
                t.setI(3);
                st.push(t);
                Tuples leftT = Tuples(t.left(), 1);
                st.push(leftT);
                break;
            }
            case 3:
            {
                Tuples rightT = Tuples(t.right(), 1);
                st.push(rightT);
                break;
            }
            }
        }
    }

    cout << "END";
}

void in_orderIterativePrint(Node *node)
{
    stack<Tuples> st;
    Tuples t = Tuples(node, 1);
    st.push(t);

    while (!st.empty())
    {
        t = st.top();
        st.pop();

        if (t.p != NULL)
        {
            switch (t.i)
            {
            case 1:
            {
                t.setI(2);
                st.push(t);
                Tuples leftT = Tuples(t.left(), 1);
                st.push(leftT);
                break;
            }
            case 2:
            {
                cout << t.getPVal() << "  -->  ";
                t.setI(3);
                st.push(t);
                break;
            }
            case 3:
            {
                Tuples rightT = Tuples(t.right(), 1);
                st.push(rightT);
                break;
            }
            }
        }
    }

    cout << "END";
}

void post_orderIterativePrint(Node *node)
{
    stack<Tuples> st;
    Tuples t = Tuples(node, 1);
    st.push(t);
    while (!st.empty())
    {
        t = st.top();
        st.pop();
        if (t.p != NULL)
        {
            switch (t.i)
            {
            case 1:
            {
                t.setI(2);
                st.push(t);
                Tuples leftT = Tuples(t.left(), 1);
                st.push(leftT);
                break;
            }
            case 2:
            {
                t.setI(3);
                st.push(t);
                Tuples rightT = Tuples(t.right(), 1);
                st.push(rightT);
                break;
            }
            case 3:
            {
                cout << t.getPVal() << "  -->  ";
                break;
            }
            }
        }
    }

    cout << "END";
}

void level_order(Node *node)
{
    queue<Node *> Queue;
    Queue.push(node);
    while (!Queue.empty())
    {
        Node *n = Queue.front();
        Queue.pop();
        cout << n->data << "  -->  ";
        if (n->left != NULL)
        {
            Queue.push(n->left);
        }
        if (n->right != NULL)
        {
            Queue.push(n->right);
        }
    }

    cout << "END";
}

int main()
{
    create_tree();

    cout << "Pre order:  ";
    pre_orderIterativePrint(root);
    cout << endl
         << endl;

    cout << "In order:  ";
    in_orderIterativePrint(root);
    cout << endl
         << endl;

    cout << "Post order:  ";
    post_orderIterativePrint(root);
    cout << endl
         << endl;

    cout << "Level order:  ";
    level_order(root);
    cout << endl;
}