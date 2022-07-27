#include <bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}

string infixToPrefix(string infix)
{
    reverse(infix.begin(), infix.end());
    string prefix = "";
    stack<char> s;
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] >= '0' && infix[i] <= '9')
        {
            prefix += infix[i];
        }
        else if (infix[i] == '(')
        {
            s.push('(');
        }
        else if (infix[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                prefix += s.top();
                s.pop();
            }
            s.pop();
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            while (!s.empty() && s.top() != '(' && precedence(infix[i]) <= precedence(s.top()))
            {
                prefix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
        else
        {
            prefix += infix[i];
        }
    }
    while (!s.empty())
    {
        prefix += s.top();
        s.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main()
{
    string infix;
    cout << "Enter the infix expression: ";
    cin >> infix;
    cout << "Infix expression: " << infix << endl;
    cout << "Prefix expression: " << infixToPrefix(infix) << endl;
    return 0;
}