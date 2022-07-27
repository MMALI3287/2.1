#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *next;

    node(int x)
    {
        val = x;
        next = NULL;
    }
};
node *head;

void INSERT_F(int x)
{
    node *temp = new node(x);
    temp->next = head;
    head = temp;
}

void INSERT_N(int x, int n)
{
    node *temp = new node(x);
    if (n == 1)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        node *curr = head;
        for (int i = 1; i < n - 1; i++)
            curr = curr->next;
        temp->next = curr->next;
        curr->next = temp;
    }
}

void INSERT_L(int x)
{
    node *temp = new node(x);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        node *temp1 = head;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
}

void DELETE_F()
{
    node *temp = head;
    head = head->next;
    delete temp;
}

void DELETE_N(int n)
{
    node *temp = head;
    node *prev = NULL;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        if (count == n)
        {
            if (prev == NULL)
            {
                head = temp->next;
                delete temp;
                return;
            }
            prev->next = temp->next;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void DELETE_L()
{
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

int SEARCH(int x)
{
    node *temp = head;
    int count = 1;
    while (temp != NULL)
    {
        if (temp->val == x)
            return count;
        temp = temp->next;
        count++;
    }
    return -1;
}

void PRINT()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    head = NULL;
    int x, n;

    while (true)
    {
        printf("1. Insert First\n2. Insert N\n3. Insert Last\n");
        printf("4. Delete First\n5. Delete N\n6. Delete Last\n");
        printf("7. Print\n8. Search\n");
        printf("9. Exit\n");
        printf("Enter Choice: ");
        int ch;
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\n Enter value: ");
            scanf("%d", &x);
            INSERT_F(x);
            break;
        case 2:
            printf("\n Enter value, position: ");
            scanf("%d%d", &x, &n);
            INSERT_N(x, n);
            break;
        case 3:
            printf("\n Enter value: ");
            scanf("%d", &x);
            INSERT_L(x);
            break;
        case 4:
            DELETE_F();
            break;
        case 5:
            printf("\n Enter position: ");
            scanf("%d", &n);
            DELETE_N(n);
            break;
        case 6:
            DELETE_L();
            break;
        case 7:
            PRINT();
            break;
        case 8:
            printf("\n Enter value: ");
            scanf("%d", &x);
            printf("Value found at position: %d\n", SEARCH(x));
            break;
        case 9:
            return 0;
            break;
        default:
            continue;
        }
    }

    return 0;
}
