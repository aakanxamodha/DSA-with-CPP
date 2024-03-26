//Evaluation of Postfix expression.
//Aakanxa Modha
//230970031

#include<iostream>
#include<stack>
#include<cmath>
#include<cstring>
using namespace std;

bool isOperator(char c)
{
        return ( c =='+' || c ==  '-' || c == '/'|| c == '^' || c == '*');
}

int evaluatePostfix(string expression)
{
        stack<int> operands;

        for(char& c: expression)
        {
                if(isdigit(c))
                {
                        operands.push( c - 'O');
                }
                else
                        if(isOperator(c))
                        {
                                int operand2 = operands.top();
                                operands.pop();
                                int operand1 = operands.top();
                                operands.pop();

                                switch(c)
                                {
                                        case '+':
                                                operands.push(operand1 + operand2);
                                                break;

                                        case '-':
                                                operands.push(operand1 - operand2);
                                                break;

                                        case '*':
                                                operands.push(operand1 * operand2);
                                                break;

                                        case '/':
                                                operands.push(operand1/operand2);
                                                break;

                                        case '^':
                                                operands.push(pow(operand1, operand2));
                                                break;
                                }
                        }
        }
        return operands.top();
}

int main()
{
        string postfixExpression;
        cout<<"Enter the postfix expression: ";
        cin>>postfixExpression;

        int result = evaluatePostfix(postfixExpression);
        cout<<"Result: "<<result<<endl;
}
