#include <bits/stdc++.h>
using namespace std;

bool VectorLinearSearch(vector<int> v, int key)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == key)
        {
            return true;
        }
    }
    return false;
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
    cout << "Vector: " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    int key;
    cout << endl
         << "Enter the key: ";
    cin >> key;
    if (VectorLinearSearch(v, key))
    {
        cout << "Key found" << endl;
    }
    else
    {
        cout << "Key not found" << endl;
    }
    return 0;
}