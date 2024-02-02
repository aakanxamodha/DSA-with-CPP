//2. Map the following 2-D arrays (matrices) to 1-D arrays (lists).
//a) Diagonal matrix

//Diagonal Matrix
//Aakanxa Modha
//230970031
//January 5, 2024

#include<iostream>
using namespace std;

class Diagonal
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

                void mapRow()
                {
                        cout<<"Diagonal Matrix row-major: [";
                        for(i=0; i<row; i++)
                        {
                                for(j=0; j<col; j++)
                                {
                                        if(i == j)
                                        {
                                                int index = i * col + j;
                                                cout<<matrix[i][j];

                                                if(i < row - 1 && j < col - 1)
                                                {
                                                        cout<<", ";
                                                }
                                        }
                                }
                        }
                        cout<<"]"<<endl;
                }

                void mapCol()
                {
                        cout<<"Diagonal Matrix column-major: [";
                        for(j=0; j<col; j++)
                        {
                                for(i=0; i<row; i++)
                                {
                                        if(i == j)
                                        {
                                                int index = j * row + i;
                                                cout<<matrix[i][j];

                                                if(i < row - 1 && j < col - 1)
                                                {
                                                        cout<<", ";
                                                }
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
                                cout<<"Invalid position..!";
                }

		void findOffsetRowMajor(int rowIn, int colIn)
    		{
		        if(rowIn >= 0 && rowIn < row && colIn >= 0 && colIn < col)
        		{
            			if(rowIn == colIn)
            			{
                			int offset = rowIn*col+colIn;
                			cout<<"Offset in Row-Major Order for position (" << rowIn << "," << colIn << ") : "<<offset<<endl;
            			}
            			else
            			{
                			cout<<"Offset in Row-Major Order for position (" << rowIn << "," << colIn << ") : -1 (off the diagonal)"<<endl;
            			}
        		}
        		else
            			cout<<"Invalid position..!"<<endl;
    		}

    		void findOffsetColMajor(int rowIn, int colIn)
    		{
        		if(rowIn >= 0 && rowIn < row && colIn >= 0 && colIn < col)
        		{
            			if(rowIn == colIn)
            			{
                			int offset = colIn*row+rowIn;
                			cout<<"Offset in Column-Major Order for position (" << rowIn << "," << colIn << ") : "<<offset<<endl;
            			}
            			else
            			{
                			cout<<"Offset in Column-Major Order for position (" << rowIn << "," << colIn << ") : -1 (off the diagonal)"<<endl;
            			}
        		}
        		else
            			cout<<"Invalid position..!"<<endl;
    		}
		
};

int main()
{
        Diagonal d;

        d.getData();
	d.displayData();
        d.mapRow();
        d.mapCol();

        int rowIn, colIn;
        cout<<"Enter the row index: ";
        cin>>rowIn;
        cout<<"Enter the column index: ";
        cin>>colIn;

        d.findElement(rowIn, colIn);
	d.findOffsetRowMajor(rowIn, colIn);
   	d.findOffsetColMajor(rowIn, colIn);

        return 0;
}
