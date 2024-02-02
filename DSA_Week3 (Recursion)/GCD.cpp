//3. GCD of 2 numbers

//GCD of two numbers
//Aakanxa Modha
//230970031
//January 19, 2024

#include<iostream>
using namespace std;

int gcd(int a, int b)
{
        if(b==0)
                return a;
        if(a==0)
                return b;
        return gcd(b, a%b);
}
int main()
{
        int gcdResult, num1, num2;

        cout<<"-:GCD Algo:-"<<endl;

        cout<<"Enter 2 numbers: "<<endl;
        cin>>num1>>num2;

        gcdResult = gcd(num1, num2);
        cout<<"GCD of "<<num1<<" and "<<num2<<": "<<gcdResult<<endl;
}
