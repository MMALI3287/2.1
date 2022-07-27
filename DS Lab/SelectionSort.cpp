#include <bits/stdc++.h>
using namespace std;

int main() // SelectionSort
{
    int n, temp;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        temp = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[temp])
                temp = j;
        }
        swap(arr[i], arr[temp]);
    }
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}