#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, key, flag = 0;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Input key: " << endl;
    cin >> key;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (arr[i] == key)
        {
            cout << "Key found at array index " << i << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "Key not found " << endl;

    return 0;
}