//1. Obtain the Row-major and Column-major representation of the given input matrix.

//Row major and Column major order.
//Aakanxa Modha
//230970031
//January 5, 2024

#include<iostream>
using namespace std;

class RowCol
{
        public:
                int i, j, row, col,  num;
                int matrix[50][50];

                void getData()
                {
                        cout<<"Enter the number of rows: ";
                        cin>>row;
                        cout<<"Enter the number of columns: ";
                        cin>>col;

                        //int matrix[50][50];

                        for(i=0; i<row; i++)
                        {
                                for(j=0; j<col; j++)
                                {
                                        cout<<"Enter the element at ("<<i<<","<<j<<") position: ";
                                        cin>>matrix[i][j];
                                }
                        }
                }

		void displayData()
		{
			cout<<"Original Matrix: [";
			for(i=0; i<row; i++)
			{
				for(j=0; j<col; j++)
				{
					cout<<matrix[i][j]<<" ";
				}
			}
			cout<<"] ";
		}

                void rowMajor()
                {
                        cout<<"Row-Major Order: [";
                        for(i=0; i<row; i++)
                        {
                                for(j=0; j<col; j++)
                                {
                                        cout<<matrix[i][j];
                                        int index = i*(col+j);
                                        if(index != (row*col)-1)
                                        {
                                                cout<<", ";
                                        }
                                }
                        }
                        cout<<"]"<<endl;
                }

                void colMajor()
                {
                        cout<<"Column-Major Order: [ ";
                        for(j=0; j<col; j++)
                        {
                                for(i=0; i<row; i++)
                                {
                                        cout<<matrix[i][j];
                                        int index = j*(row+i);
                                        if(index != (row*col)-1)
                                        {
                                                cout<<" ";
                                        }
                                }
                        }
                        cout<<"]"<<endl;
                }

                void findElement(int rowIn, int colIn)
                {
                        if(rowIn >= 0 && rowIn < row && colIn >= 0 && colIn < col)
                                cout<<"The element at position ("<<rowIn<<","<<colIn<<") : "<<matrix[rowIn][colIn];
                        else
                                cout<<"Invalid position..!";
                }

		void findOffsetRowMajor(int rowIn, int colIn)
    		{
        		if(rowIn >= 0 && rowIn < row && colIn >= 0 && colIn < col)
        		{
            			int offset = rowIn*col+colIn;
            			cout<<"Offset in Row-Major Order for position (" << rowIn << "," << colIn << ") : "<<offset<<endl;
        		}
        		else
            			cout<<"Invalid position..!";
    		}

    		void findOffsetColMajor(int rowIn, int colIn)
    		{
        		if(rowIn >= 0 && rowIn < row && colIn >= 0 && colIn < col)
        		{
            			int offset = colIn*row+rowIn;
            			cout<<"Offset in Column-Major Order for position (" << rowIn << "," << colIn << ") : "<<offset<<endl;
        		}
        		else
            			cout<<"Invalid position..!";
    		}
};

int main()
{
        RowCol rc;
        rc.getData();
	rc.displayData();
        rc.rowMajor();
        rc.colMajor();

        int rowIn, colIn;
        cout<<"Enter the row index: ";
        cin>>rowIn;
        cout<<"Enter the column index: ";
        cin>>colIn;

        rc.findElement(rowIn, colIn);
	rc.findOffsetRowMajor(rowIn, colIn);
    	rc.findOffsetColMajor(rowIn, colIn);

        return 0;
}
