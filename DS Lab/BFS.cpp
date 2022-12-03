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

void enqueue(int Node)
{
    node *temp = new node(Node);
    node *temp1 = head;
    while (temp1->next != NULL)
        temp1 = temp1->next;
    temp1->next = temp;
}

int dequeue()
{
    int value;
    value = head->val;
    head = head->next;
    return value;
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
            printf("%d ", graph[i][j]);
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
        if (status[i] == 1 && graph[nodeN][i] == 1)
        {
            enqueue(i);
            status[i] = 2;
            cout << "Waiting: " << i << endl;
        }
    }
}
void bfs(int source, int n)
{
    // step 1
    initStatus(n);

    // step 2
    enqueue(source);
    status[source] = 2;

    // step 3
    while (!isEmpty())
    {
        // step 4
        int N;
        N = dequeue();
        cout << N << ": ";
        status[N] = 3;

        // step 5
        addNeighbors(N, n);
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
    bfs(source, n);

    return 0;
}