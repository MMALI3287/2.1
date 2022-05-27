#include <bits/stdc++.h>
using namespace std;

void countingSort(int arr[], int n, int base)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[(arr[i] / base) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / base) % 10] - 1] = arr[i];
        count[(arr[i] / base) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
    int m = *max_element(arr, arr + n);
    for (int base = 1; m / base > 0; base *= 10)
    {
        countingSort(arr, n, base);
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    radixsort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
