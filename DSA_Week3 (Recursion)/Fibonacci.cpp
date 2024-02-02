//4. Fibonacci series upto nth term

//Fibonacci series upto nth term
//Aakanxa Modha
//230970031
//January 19, 2024

#include<iostream>
using namespace std;

long fib(int no)
{
        if(no == 0 || no == 1)
                return no;
        return (fib(no-1) + fib(no-2));
}

int main()
{
        int  num;

        cout<<"-:Fibonacci Series:-"<<endl;

        cout<<"Enter a number: "<<endl;
        cin>>num;

        for(int i=0; i<num; i++)
        {
                cout<<fib(i)<<"  ";
        }
        cout<<"\n";
}
