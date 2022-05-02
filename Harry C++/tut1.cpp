#include <iostream>
using namespace std;

int main()
{
    static int a = 9;
    const int b = 10;
    cout << a << endl;
    a = 10;
    cout << a << endl;
    return 0;
}