#include <bits/stdc++.h>
using namespace std;

void VectorSelectionSort(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        int min = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[min])
            {
                min = j;
            }
        }
        int temp = v[i];
        v[i] = v[min];
        v[min] = temp;
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
    VectorSelectionSort(v);
    cout << endl
         << "Sorted vector: " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}