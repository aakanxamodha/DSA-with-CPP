//d) Lower triangular matrix

//Lower triangular matrix
//Aakanxa Modha
//230970031
//January 7, 2024

#include<iostream>
using namespace std;

class LowerTriangular
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

                void lowerRowMajor()
                {
                        cout<<"Lower triangular row-major: [ ";
                        for(i=0; i<row; i++)
                        {
                                for(j=0; j<col; j++)
                                {
                                        if(i>=j)
                                        {
                                                int index = i * (i + 1) / 2 + j;
                                                cout<<matrix[i][j]<<" ";
                                        }
                                }
                        }
                        cout<<"] "<<endl;
                }

                void lowerColMajor()
                {
                        cout<<"Lower triangular column-major: [ ";
                        for(j=0; j<col; j++)
                        {
                                for(i=0; i<row; i++)
                                {
                                        if(i>=j)
                                        {
                                                int index = j * (j + 1) / 2 + i;
                                                cout<<matrix[i][j]<<" ";
                                        }
                                }
                        }
                        cout<<"] "<<endl;
                }

                void findElement(int rowIn, int colIn)
                {
                        if(rowIn >= 0 && rowIn < row && colIn >= 0 && colIn < col)
                                cout<<"The element at position ("<<rowIn<<","<<colIn<<") : "<<matrix[rowIn][colIn]<<endl;
                        else
                                cout<<"Invalid position..!"<<endl;
                }

		void findOffsetRowMajor(int rowIn, int colIn)
    		{
        		if(rowIn >= 0 && rowIn < row && colIn >= 0 && colIn < col)
        		{
            			if(colIn <= rowIn)
            			{
                			int offset = rowIn*col+colIn;
                			cout<<"Offset in Row-Major Order for position (" << rowIn << "," << colIn << ") : "<<offset<<endl;
            			}
            			else
            			{
                			cout<<"Offset in Row-Major Order for position (" << rowIn << "," << colIn << ") : -1 (above the main diagonal)"<<endl;
            			}
        		}
        		else
            			cout<<"Invalid position..!"<<endl;
    		}

    		void findOffsetColMajor(int rowIn, int colIn)
    		{
        		if(rowIn >= 0 && rowIn < row && colIn >= 0 && colIn < col)
        		{
            			if(colIn <= rowIn)
            			{
                			int offset = colIn*row+rowIn;
                			cout<<"Offset in Column-Major Order for position (" << rowIn << "," << colIn << ") : "<<offset<<endl;
            			}
            			else
            			{
                			cout<<"Offset in Column-Major Order for position (" << rowIn << "," << colIn << ") : -1 (above the main diagonal)"<<endl;
            			}
        		}
        		else
            			cout<<"Invalid position..!";
    		}

};

int main()
{
        LowerTriangular lt;
        lt.getData();
	lt.displayData();
        lt.lowerRowMajor();
        lt.lowerColMajor();

        int rowIn, colIn;

        cout<<"Enter the row index: ";
        cin>>rowIn;
        cout<<"Enter the column index: ";
        cin>>colIn;

        lt.findElement(rowIn, colIn);
	lt.findOffsetRowMajor(rowIn, colIn);
    	lt.findOffsetColMajor(rowIn, colIn);

        return 0;
}