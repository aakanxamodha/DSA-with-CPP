//Evaluation of Prefix expression.
//Aakanxa Modha
//230970031

#include<iostream>
#include<stack>
#include<cmath>
#include<cstring>
using namespace std;

bool isOperator(char c)
{
        return ( c== '+' || c == '-' || c == '*' || c == '/' ||  c == '^');
}

int evaluatePrefix(string expression)
{
        stack<int> operands;

        for(int i = expression.size() - 1; i >=0 ; i--)
        {
                char c = expression[i];
                if(isdigit(c))
                {
                        operands.push(c = 'O');
                }
                else
                        if(isOperator(c))
                        {
                                int operand1 = operands.top();
                                operands.pop();
                                int operand2 = operands.top();
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
        string prefixExpression;
        cout<<"Enter the prefix expression: ";
        cin>>prefixExpression;

        int result = evaluatePrefix(prefixExpression);
        cout<<"Result: "<<result<<endl;
}
