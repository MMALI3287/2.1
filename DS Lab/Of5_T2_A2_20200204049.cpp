#include <bits/stdc++.h>
using namespace std;

int prec(char c)
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
            while (!s.empty() && s.top() != '(' && prec(infix[i]) <= prec(s.top()))
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

int infixEvaluation(string infix)
{
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

string postfixToInfix(string postfix)
{
    stack<string> s;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            string temp(1, postfix[i]);
            s.push(temp);
        }
        else
        {
            string temp = s.top();
            s.pop();
            string temp2 = s.top();
            s.pop();
            s.push("(" + temp2 + postfix[i] + temp + ")");
        }
    }
    return s.top();
}

int main()
{
    string postfix;
    cout << "Enter the postfix expression: ";
    cin >> postfix;
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Postfix Evaluation: " << postfixEvaluation(postfix) << endl;
    cout << "Infix Expression: " << postfixToInfix(postfix) << endl;
    cout << "Infix Evaluation: " << infixEvaluation(postfixToInfix(postfix)) << endl;
    return 0;
}