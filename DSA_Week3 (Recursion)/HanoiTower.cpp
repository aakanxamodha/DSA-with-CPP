//1. Hanoi towers

//Tower of Hanoi for n disks (Recursion application)
//Aakanxa Modha
//230970031
//January 19, 2024

#include<iostream>
using namespace std;

void towers(int n, char source, char dest, char auxi)
{
        static int step = 0;

        if(n == 1)
                cout<<"Move from "<<source<<" to "<<dest<<endl;
        else
        {
                towers(n-1, source, auxi, dest);
                cout<<"Move from "<<source<<" to "<<dest<<endl;
                towers(n-1, auxi, dest, source);
        }
}

int main()
{
        int num;

        cout<<"Enter the  number of disks: "<<endl;
        cin>>num;

        towers(num, 'A', 'C', 'B');
}
