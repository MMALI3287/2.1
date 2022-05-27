#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main()
{
    string str1, str2;
    cout << "str1 = ";
    cin >> str1;
    cout << "str2 = ";
    cin >> str2;
    if (strstr(str1.c_str(), str2.c_str()))
    {
        cout << "Found";
    }
    else
        cout << "Not Found";

    return 0;
}