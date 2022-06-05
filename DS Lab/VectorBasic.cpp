#include <vector>
#include <iostream>
using namespace std;

void printVe(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

int main()
{
    // declare a vector
    vector<int> vct;
    vct.push_back(5);
    vct.push_back(6);
    vct.push_back(7);
    vct.push_back(8);
    int y;
    cin >> y;
    vct.push_back(y);
    cin >> y;
    vct.push_back(y);

    for (int i = 0; i < vct.size(); i++)
    {
        cout << vct[i] << endl;
    }

    // user input
    vector<int> vct1;
    int x;
    for (int i = 0; i < 4; i++)
    {
        cin >> x;
        vct1.push_back(x);
    }
    printVe(vct1);

    // array to vector
    int arr[] = {2, 7, 4, 1, 5, 3};
    vector<int> vct2(arr, arr + sizeof(arr) / sizeof(int));
    printVe(vct2);
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;
    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    vector<int> vct3(arr1, arr1 + n);
    cout << "Array1 to vector: " << endl;
    printVe(vct3);
    return 0;
}