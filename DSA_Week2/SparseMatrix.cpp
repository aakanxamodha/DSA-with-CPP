//1. Represent a sparse matrix using 1-D array. Use this 1-D array to reconstruct the original matrix.

//Sparse matrix
//Aakanxa Modha
//230970031
//January 12, 2024

#include<iostream>
using namespace std;

struct sparse
{
        int row;
        int col;
        int val;
};

class sparseMatrix
{
        public:
                int i, j, k, rows, cols, size;
                sparse matrix[50];

                void getTriplets()
                {
                        cout<<"Enter the number of rows: ";
                        cin>>rows;
                        cout<<"Enter the number of columns: ";
                        cin>>cols;
                        cout<<"Enter the number of non-zero elements: ";
                        cin>>size;

                        cout<<"Enter the elements(row, col, val): ";
                        for(i=0; i<size; i++)
                        {
                                cin>>matrix[i].row;
                                cin>>matrix[i].col;
                                cin>>matrix[i].val;
                        }
                }

                void displayTriplets()
                {
                        cout<<"Triplets Representation: "<<endl;
                        cout<<"Row\tColumn\tValue"<<endl;
                        for(i=0; i<size; i++)
                        {
                                cout<<matrix[i].row<<"\t";
                                cout<<matrix[i].col<<"\t";
                                cout<<matrix[i].val<<"\t";
                                cout<<endl;
                        }
                }



                void insert(int row, int col, int val)
                {
                        if(val!=0)
                        {
                                matrix[size].row=row;
                                matrix[size].col=col;
                                matrix[size].val=val;
                                size++;
                        }
                }

                void printOriginal()
                {
                        for(i=0; i<rows; i++)
                        {
                                for(j=0; j<cols; j++)
                                {
                                        int element=0;
                                        for(k=0; k<size; k++)
                                        {
                                                if(matrix[k].row == i && matrix[k].col == j)
                                                {
                                                        element=matrix[k].val;
                                                        break;
                                                }
                                        }
                                        cout<<element<<" ";
                                }
                                cout<<endl;
                        }
                }
};

int main()
{
        sparseMatrix sm;
        sm.getTriplets();
        sm.displayTriplets();
        sm.insert(0,0,0);
        sm.printOriginal();

        return 0;
}
