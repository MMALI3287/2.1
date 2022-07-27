#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *prev;
    int val;
    node *next;

    node(int x)
    {
        prev = NULL;
        val = x;
        next = NULL;
    }
};
node *head;

void INSERT_F(int x)
{
    node *temp = new node(x);
    temp->next = head;
    temp->prev = NULL;
    if (head != NULL)
        head->prev = temp;
    head = temp;
}

void INSERT_N(int x, int n)
{
    node *temp = new node(x);
    if (n == 1)
    {
        temp->next = head;
        temp->prev = NULL;
        head = temp;
    }
    else
    {
        node *curr = head;
        for (int i = 1; i < n - 1; i++)
            curr = curr->next;
        temp->next = curr->next;
        curr->next = temp;
        temp->prev = curr;
        temp->next->prev = temp;
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
        temp->prev = temp1;
    }
}

void DELETE_F()
{
    node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}

void DELETE_N(int n)
{
    node *temp = head;
    if (n == 1)
    {
        head = head->next;
        delete temp;
    }
    else
    {
        for (int i = 1; i < n - 1; i++)
            temp = temp->next;
        node *temp1 = temp->next;
        temp->next = temp1->next;
        temp1->next->prev = temp;
        delete temp1;
    }
}

void DELETE_L()
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
}

int SEARCH(int x)
{
    node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        if (temp->val == x)
            return cnt;
        temp = temp->next;
        cnt++;
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

void PRINT_REV()
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
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
        printf("7. Print\n8. Reverse Print\n9. Search\n");
        printf("10. Exit\n");
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
            PRINT_REV();
            break;
        case 9:
            printf("\n Enter value: ");
            scanf("%d", &x);
            printf("Value found at position: %d\n", SEARCH(x));
            break;
        case 10:
            return 0;
            break;
        default:
            continue;
        }
    }

    return 0;
}
