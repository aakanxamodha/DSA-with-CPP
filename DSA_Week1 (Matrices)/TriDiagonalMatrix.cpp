//b) Tri-diagonal matrix

//Tridiagonal matrix
//Aakanxa Modha
//230970031
//January 5, 2024

#include<iostream>
using namespace std;

class Tridiagonal
{
        public:
                int i, j, row, col;
                int matrix[50][50];

                void getData()
                {
                        cout<<"Enter the number of rows: ";
                        cin>>row;
                        cout<<"Enter the number of columns: ";
                        cin>>col;

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

                void triDiagonalRowMajor()
                {
                        cout<<"Tridiagonal matrix row-major: [ ";
                        for(i=0; i<row; i++)
                        {
                                for(j=0; j<col; j++)
                                {
                                        if((i-j==-1) || (i-j==0) || (i-j==1))
                                        {
                                                int index = i * col + j;
                                                cout<<matrix[i][j]<<" ";
                                        }
                                }
                        }
                        cout<<"]"<<endl;
                }

                void triDiagonalColMajor()
                {
                        cout<<"Tridiagonal matrix column-major: [ ";
                        for(j=0; j<col; j++)
                        {
                                for(i=0; i<row; i++)
                                {
                                        if((i-j==-1) || (i-j==0) || (i-j==1))
                                        {
                                                int index = j * row + i;
                                                cout<<matrix[i][j]<<" ";
                                        }
                                }
                        }
                        cout<<"]"<<endl;
                }


                void findElement(int rowIn, int colIn)
                {
                        if(rowIn >= 0 && rowIn < row && colIn >= 0 && colIn < col)
                                cout<<"The element at position ("<<rowIn<<","<<colIn<<"): "<<matrix[rowIn][colIn]<<endl;
                        else
                                cout<<"Invalid position..!"<<endl;
                }

		void findOffsetRowMajor(int rowIn, int colIn)
    		{
        		if(rowIn >= 0 && rowIn < row && colIn >= 0 && colIn < col)
        		{
            			if(colIn == rowIn || colIn == rowIn - 1 || colIn == rowIn + 1)
            			{
                			int offset = rowIn*(3*col)+colIn;
               	 			cout<<"Offset in Row-Major Order for position (" << rowIn << "," << colIn << ") : "<<offset<<endl;
            			}
            			else
            			{
                			cout<<"Offset in Row-Major Order for position (" << rowIn << "," << colIn << ") : -1 (outside tridiagonal)"<<endl;
            			}
        		}
        		else
            			cout << "Invalid position..!"<<endl;
    		}

    		void findOffsetColMajor(int rowIn, int colIn)
    		{
        		if(rowIn >= 0 && rowIn < row && colIn >= 0 && colIn < col)
        		{
            			if(colIn == rowIn || colIn == rowIn - 1 || colIn == rowIn + 1)
            			{
                			int offset = colIn*(3*row)+rowIn;
                			cout<<"Offset in Column-Major Order for position (" << rowIn << "," << colIn << ") : "<<offset<<endl;
            			}
            			else
            			{
                			cout<<"Offset in Column-Major Order for position (" << rowIn << "," << colIn << ") : -1 (outside tridiagonal)"<<endl;
            			}
        		}
        		else
            			cout << "Invalid position..!";
    		}
};

int main()
{
        Tridiagonal t;
        t.getData();
	t.displayData();
        t.triDiagonalRowMajor();
        t.triDiagonalColMajor();

        int rowIn, colIn;

        cout<<"Enter the row index: ";
        cin>>rowIn;
        cout<<"Enter the column index: ";
        cin>>colIn;

        t.findElement(rowIn, colIn);
	t.findOffsetRowMajor(rowIn, colIn);
    	t.findOffsetColMajor(rowIn, colIn);

        return 0;
}
