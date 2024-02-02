//2. Represent a polynomial using 1-D array and perform addition operation on two polynomials.

//Addition of two polynomials
//Aakanxa Modha
//230970031
//January 12, 2024


#include<iostream>
using namespace std;

const int maxPow = 50;

class addPolynomial
{
public:
    int pow1, pow2, exp1[maxPow], exp2[maxPow], result[maxPow], bigPow;

    addPolynomial()
    {
        for(int i=0; i<= maxPow; i++)
        {
            exp1[i]=0;
            exp2[i]=0;
            result[i]=0;
        }
    }

    void getData()
    {
        cout<<"Enter the power of first polynomial: ";
        cin>>pow1;
        cout<<"Enter the power of second polynomial: ";
        cin>>pow2;

        cout<<"Enter coeffs for first poly: ";
        for(int i=pow1; i>= 0; i--)
        {
            cout<<"Coeffs of x^"<<i<<" : ";
            cin>>exp1[i];
        }

        cout<<"Enter coeffs for second poly: ";
        for(int i=pow2; i>=0; i--)
        {
            cout<<"Coeffs of x^"<<i<<" : ";
            cin>>exp2[i];
        }
    }

    void addition()
    {
        bigPow = max(pow1, pow2);
        for(int i = 0; i <= bigPow; i++)
        {
            result[i] = exp1[i] + exp2[i];
        }
    }

    void displayData()
    {
        cout<<"First polynomial: ";
        for(int i = pow1; i >= 0; i--)
        {
            if(exp1[i] != 0)
            {
                cout<<exp1[i]<<"x^"<<i;
                if(i != 0 && exp1[i-1] != 0)
                {
                    cout<<" + ";
                }
            }
        }
        cout<<endl;

        cout<<"Second polynomial: ";
        for(int i = pow2; i >= 0; i--)
        {
            if(exp2[i] != 0)
            {
                cout<<exp2[i]<<"x^"<<i;
                if(i != 0 && exp2[i-1] != 0)
                {
                    cout<<" + ";
                }
            }
        }
        cout<<endl;

        cout<<"Sum: ";
        for(int i = bigPow; i >= 0; i--)
        {
            if(result[i] != 0)
            {
                cout<<result[i]<<"x^"<<i;
                if(i != 0 && result[i-1] != 0)
                {
                    cout<<" + ";
                }
            }
        }
        cout<<endl;
    }
};

int main()
{
    addPolynomial ap;

    ap.getData();
    ap.addition();
    ap.displayData();
                           
    return 0;
}