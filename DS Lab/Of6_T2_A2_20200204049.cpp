#include <bits/stdc++.h>
using namespace std;

int graph[200][200];
int status[200];

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

void push(int Node)
{
    node *temp = new node(Node);
    temp->next = head;
    head = temp;
}

int pop()
{
    int x = head->val;
    head = head->next;
    return x;
}

bool isEmpty()
{
    if (head == NULL)
        return true;
    return false;
}

void inputGraph(int N, int E)
{
    int i, j, x, y;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            graph[i][j] = 0;
        }
    }
    for (i = 1; i <= E; i++)
    {
        cout << "Enter First Node of the edge: ";
        cin >> x;
        cout << "Enter Second Node of the edge: ";
        cin >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
}

void printAM(int N)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            printf(" %d ", graph[i][j]);
        }
        printf("\n");
    }
}

void initStatus(int N)
{
    for (int i = 1; i <= N; i++)
    {
        status[i] = 1;
    }
}

void addNeighbors(int nodeN, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (graph[nodeN][i] == 1 && status[i] == 1)
        {
            push(i);
            status[i] = 2;
            cout << "Waiting: " << i << endl;
        }
    }
}

void dfs(int source, int n)
{
    // step 1
    initStatus(n);

    // step 2
    push(source);
    status[source] = 2;

    // step 3
    while (!isEmpty())
    {
        // step 4
        int nodeN;
        nodeN = pop();
        cout << "DFS: " << nodeN << endl;
        status[nodeN] = 3;

        // step 5
        addNeighbors(nodeN, n);
    }
}

int main()
{
    int n, e, source;
    printf("Enter no of Node: ");
    scanf("%d", &n);

    printf("Enter no of Edge: ");
    scanf("%d", &e);

    printf("Enter Source: ");
    scanf("%d", &source);
    inputGraph(n, e);
    printAM(n);
    dfs(source, n);

    return 0;
}
