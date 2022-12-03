#include <bits/stdc++.h>
using namespace std;

int main()
{
    int la[] = {56, 56, 12, 35, 78, 90};
    int temp = 56;
    int ptr = 35;
    int j = sizeof(la) / sizeof(la[0]);
    int i = 0;
    while (i < sizeof(la) / sizeof(la[0]))
    {
        cout << la[i] << endl;
        i++;
    }
    return 0;
}