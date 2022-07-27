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

void infixToPostfix(string infix, string &postfix)
{
    stack<char> s;
    postfix = "";
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            s.push('(');
        }
        else if (infix[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            while (!s.empty() && s.top() != '(' && precedence(infix[i]) <= precedence(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
        else
        {
            postfix += infix[i];
        }
    }
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
}

void postfixToInfix(string postfix, string &infix)
{
    stack<char> s;
    infix = "";
    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            infix += " ";
            infix += postfix[i];
            infix += " ";
        }
        else
        {
            infix += postfix[i];
        }
    }
    while (!s.empty())
    {
        infix += " ";
        infix += s.top();
        s.pop();
    }
}

void InfixToPrefix(string infix, string &prefix)
{
    string postfix;
    infixToPostfix(infix, postfix);
    postfixToInfix(postfix, prefix);
}

void infixEvaluation(string infix, int &result)
{
    string postfix;
    infixToPostfix(infix, postfix);
    stack<int> s;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            s.push(postfix[i] - '0');
        }
        else
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            switch (postfix[i])
            {
            case '+':
                s.push(b + a);
                break;
            case '-':
                s.push(b - a);
                break;
            case '*':
                s.push(b * a);
                break;
            case '/':
                s.push(b / a);
                break;
            }
        }
    }
    result = s.top();
}

void postfixEvaluation(string postfix, int &result)
{
    stack<int> s;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            s.push(postfix[i] - '0');
        }
        else
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            switch (postfix[i])
            {
            case '+':
                s.push(b + a);
                break;
            case '-':
                s.push(b - a);
                break;
            case '*':
                s.push(b * a);
                break;
            case '/':
                s.push(b / a);
                break;
            }
        }
    }
    result = s.top();
}

int main()
{
    string postfix, infix, prefix;
    int result;

    cout << "Enter the infix expression: ";
    cin >> infix;
    cout << "Infix expression: " << infix << endl;
    cout << "Infix evaluation: ";
    infixEvaluation(infix, result);
    cout << result << endl;
    infixToPostfix(infix, postfix);
    cout << "Postfix expression: " << postfix << endl;
    postfixEvaluation(postfix, result);
    cout << "Postfix evaluation: " << result << endl;

    cout << "Enter the postfix expression: ";
    cin >> postfix;
    cout << "Postfix expression: " << postfix << endl;
    cout << "Postfix evaluation: ";
    postfixEvaluation(postfix, result);
    cout << result << endl;
    postfixToInfix(postfix, infix);
    cout << "Infix expression: " << infix << endl;
    infixEvaluation(infix, result);
    cout << "Infix evaluation: " << result << endl;

    cout << "Enter the infix expression: ";
    cin >> infix;
    cout << "Infix expression: " << infix << endl;
    InfixToPrefix(infix, prefix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}