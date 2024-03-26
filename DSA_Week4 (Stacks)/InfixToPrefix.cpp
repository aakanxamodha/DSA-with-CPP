//Conversion of infix expression to prefix expression (using stack).
//Aakanxa Modha
//230970031

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int precedence(char op)
{
        if(op == '^')
                return 3;
        else
                if(op == '*' || op == '/')
                        return 2;
                else
                        if(op == '+' || op == '-')
                                return 1;
                        else
                                return -1;
}

string infixToPrefix(string expression)
{
        stack<char> stk;
        string prefix = " ";

        reverse(expression.begin(), expression.end());

        for(char& c : expression)
        {
                if(isalnum(c))
                        prefix += c;
                else
                        if(c == ')')
                                stk.push(')');
                        else
                                if(c == '(')
                                {
                                        while(!stk.empty() && stk.top() != ')')
                                        {
                                                prefix += stk.top();
                                                stk.top();
                                        }
                                }
                                else
                                {
                                        while(!stk.empty() && precedence(c) < precedence(stk.top()))
                                        {
                                                prefix += stk.top();
                                                stk.pop();
                                        }
                                        stk.push(c);
                                }
        }

        while(!stk.empty())
        {
                prefix += stk.top();
                stk.pop();
        }

        reverse(prefix.begin(), prefix.end());
        return prefix;
}

int main()
{
        string infixExpression;
        cout<<"Enter the infix expression: ";
        cin>>infixExpression;

        string prefixExpression = infixToPrefix(infixExpression);
        cout<<"Prefix Expression: "<< prefixExpression<<endl;
}
