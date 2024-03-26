//Conversion of Infix expression to Postfix expression (using stack).
//Aakanxa Modha
//230970031

#include<iostream>
#include<stack>
#include<string>
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

string infixToPostfix(string expression)
{
        stack<char> stk;
        string postfix = " ";

        for(char& c: expression)
        {
                if(isalnum(c))
                        postfix += c;
                else
                        if(c == '(')
                                stk.push('(');
                        else
                                if(c == ')')
                                {
                                        while(!stk.empty() && stk.top() != '(')
                                        {
                                                postfix += stk.top();
                                                stk.pop();
                                        }
                                }
                                else
                                {
                                        while(!stk.empty() && precedence(c) <= precedence(stk.top()))
                                        {
                                                postfix += stk.top();
                                                stk.pop();
                                        }
                                        stk.push(c);
                                }
        }

        while(!stk.empty())
        {
                postfix += stk.top();
                stk.pop();
        }

        return postfix;
}

int main()
{
        string infixExpression;
        cout<<"Enter the infix expression: ";
        cin>>infixExpression;

        string postfixExpression = infixToPostfix(infixExpression);
        cout<<"Postfix expression: " <<postfixExpression<<endl;

}
