//2.  Factorial of a given number

//Factorial of a given number
//Aakanxa Modha
//230970031
//January 19, 2024

#include<iostream>
using namespace std;

int fact(int a)
{
	if(a==0)
		return 1;
	else
        	return (a*fact(a-1));
}
int main()
{
        int num, result;

        cout<<"Enter a number: "<<endl;
        cin>>num;

        result = fact(num);
        cout<<"Factorial of " <<num<< " : "<<result<<endl;
}
