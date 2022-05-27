#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, high, low, mid, key, flag = 0;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the key: ";
    cin >> key;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            cout << "Key found at array index " << mid << endl;
            flag = 1;
            break;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (flag == 0)
        cout << "Key not found " << endl;
    return 0;
}