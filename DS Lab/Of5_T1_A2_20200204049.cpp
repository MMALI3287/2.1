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

string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";
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
    return postfix;
}

int infixEvaluation(string infix)
{
    infix = "(" + infix + ")";
    stack<int> operand;
    stack<char> operator1;
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] >= '0' && infix[i] <= '9')
        {
            operand.push(infix[i] - '0');
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            operator1.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            char op = operator1.top();
            operator1.pop();
            int op1 = operand.top();
            operand.pop();
            int op2 = operand.top();
            operand.pop();
            if (op == '+')
            {
                operand.push(op2 + op1);
            }
            else if (op == '-')
            {
                operand.push(op2 - op1);
            }
            else if (op == '*')
            {
                operand.push(op2 * op1);
            }
            else if (op == '/')
            {
                operand.push(op2 / op1);
            }
        }
    }
    return operand.top();
}

int postfixEvaluation(string postfix)
{
    stack<int> s;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            int c1 = s.top();
            s.pop();
            int c2 = s.top();
            s.pop();
            if (postfix[i] == '+')
            {
                s.push(c2 + c1);
            }
            else if (postfix[i] == '-')
            {
                s.push(c2 - c1);
            }
            else if (postfix[i] == '*')
            {
                s.push(c2 * c1);
            }
            else if (postfix[i] == '/')
            {
                s.push(c2 / c1);
            }
        }
        else
        {
            s.push(postfix[i] - '0');
        }
    }
    return s.top();
}

int main()
{
    string infix;
    cout << "Input infix expression: ";
    cin >> infix;
    cout << "Infix Expression: " << infix << endl;
    cout << "Infix Evaluation: " << infixEvaluation(infix) << endl;
    cout << "Postfix Expression: " << infixToPostfix(infix) << endl;
    cout << "Postfix Evaluation: " << postfixEvaluation(infixToPostfix(infix)) << endl;
    return 0;
}