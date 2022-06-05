#include <bits/stdc++.h>
using namespace std;

void VectorInsertionSort(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int key = v[i];
        int j = i - 1;
        for (j = i - 1; j >= 0 && v[j] > key; j--)
        {
            v[j + 1] = v[j];
        }
        v[j + 1] = key;
    }
}

int main()
{
    vector<int> v;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << "Vector before sorting: " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    VectorInsertionSort(v);
    cout << endl
         << "Sorted vector: " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}