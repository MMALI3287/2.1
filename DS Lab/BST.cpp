#include <bits/stdc++.h>
using namespace std;

struct BNode
{
    int data;
    BNode *left;
    BNode *right;

    BNode(int data)
    {
        data = data;
        left = right = NULL;
    }
};

struct BST
{
    BNode *root;
    BST()
    {
        root = NULL;
    }
    void insert(int data)
    {
        BNode *newNode = new BNode(data);
        if (root == NULL)
        {
            root = newNode;
            return;
        }
        BNode *temp = root;
        while (temp != NULL)
        {
            if (data < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = newNode;
                    return;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = newNode;
                    return;
                }
                temp = temp->right;
            }
        }
    }
    void inorder(BNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    void preorder(BNode *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(BNode *root)
    {
        if (root == NULL)
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    void levelorder(BNode *root)
    {
        queue<BNode *> q;
        q.push(root);
        while (!q.empty())
        {
            BNode *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    void deleteNode(int data)
    {
        BNode *temp = root;
        BNode *parent = NULL;
        while (temp != NULL)
        {
            if (data == temp->data)
                break;
            parent = temp;
            if (data < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if (temp == NULL)
            return;
        if (temp->left == NULL && temp->right == NULL)
        {
            if (parent->left == temp)
                parent->left = NULL;
            else
                parent->right = NULL;
            delete temp;
            return;
        }
        if (temp->left == NULL)
        {
            if (parent->left == temp)
                parent->left = temp->right;
            else
                parent->right = temp->right;
            delete temp;
            return;
        }
        if (temp->right == NULL)
        {
            if (parent->left == temp)
                parent->left = temp->left;
            else
                parent->right = temp->left;
            delete temp;
            return;
        }
        BNode *successor = temp->right;
        BNode *successorParent = temp;
        while (successor->left != NULL)
        {
            successorParent = successor;
            successor = successor->left;
        }
        temp->data = successor->data;
        if (successorParent->left == successor)
            successorParent->left = successor->right;
        else
            successorParent->right = successor->right;
        delete successor;
    }
    void findHeightIterative(BNode *root)
    {
        queue<BNode *> q;
        q.push(root);
        q.push(NULL);
        int height = 0;
        while (!q.empty())
        {
            BNode *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                if (!q.empty())
                    q.push(NULL);
                height++;
                continue;
            }
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        cout << height << " ";
    }
    void findLCA(BNode *root, int n1, int n2)
    {
        if (root == NULL)
            return;
        if (root->data == n1 || root->data == n2)
        {
            cout << root->data << " ";
            return;
        }
        findLCA(root->left, n1, n2);
        findLCA(root->right, n1, n2);
    }
    void findLCAIterative(BNode *root, int n1, int n2)
    {
        queue<BNode *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            BNode *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                if (!q.empty())
                    q.push(NULL);
                continue;
            }
            if (temp->data == n1 || temp->data == n2)
            {
                cout << temp->data << " ";
                return;
            }
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    void findDistance(BNode *root, int n1, int n2)
    {
        if (root == NULL)
            return;
        if (root->data == n1 || root->data == n2)
        {
            cout << root->data << " ";
            return;
        }
        findDistance(root->left, n1, n2);
        findDistance(root->right, n1, n2);
    }
    void findDistanceIterative(BNode *root, int n1, int n2)
    {
        queue<BNode *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            BNode *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                if (!q.empty())
                    q.push(NULL);
                continue;
            }
            if (temp->data == n1 || temp->data == n2)
            {
                cout << temp->data << " ";
                return;
            }
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    void findDistanceK(BNode *root, int n1, int n2, int k)
    {
        if (root == NULL)
            return;
        if (root->data == n1 || root->data == n2)
        {
            cout << root->data << " ";
            return;
        }
        if (k == 0)
            return;
        findDistanceK(root->left, n1, n2, k - 1);
        findDistanceK(root->right, n1, n2, k - 1);
    }
    void findDistanceKIterative(BNode *root, int n1, int n2, int k)
    {
        queue<BNode *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            BNode *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                if (!q.empty())
                    q.push(NULL);
                continue;
            }
            if (temp->data == n1 || temp->data == n2)
            {
                cout << temp->data << " ";
                return;
            }
            if (k == 0)
                return;
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
};
int main()
{
    BST bt;
    bt.insert(10);
    bt.insert(5);
    bt.insert(15);
    bt.insert(3);
    bt.insert(7);
    bt.insert(12);
    bt.insert(18);
    bt.insert(1);
    bt.insert(4);
    bt.insert(6);
    bt.insert(8);
    bt.insert(11);
    bt.insert(13);
    bt.insert(16);
    bt.insert(19);
    bt.insert(2);
    bt.insert(9);
    bt.insert(14);
    bt.insert(17);
    bt.insert(20);
    bt.deleteNode(10);
    bt.findHeightIterative(bt.root);
    bt.findLCA(bt.root, 1, 2);
    bt.findLCAIterative(bt.root, 1, 2);
    bt.findDistance(bt.root, 1, 2);
    bt.findDistanceIterative(bt.root, 1, 2);
    bt.findDistanceK(bt.root, 1, 2, 2);
    bt.findDistanceKIterative(bt.root, 1, 2, 2);
    return 0;
}
