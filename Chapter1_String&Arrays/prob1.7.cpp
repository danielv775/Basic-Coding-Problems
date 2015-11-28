#include <iostream>
using namespace std;

const int ROW = 5;
const int COL = 4;

void Zerofy(int matrix[ROW][COL], int m, int n);
void setZeros(int matrix[ROW][COL], int ROW, int COL);
void nullifyRow(int matrix[ROW][COL], int row);
void nullifyCol(int matrix[ROW][COL], int col);

int main()
{
    int matrix[ROW][COL] = {
        {1,0,1,1},
        {2,2,2,2},
        {3,3,3,3},
        {4,4,4,4},
        {5,5,5,5}
    };
    
    cout << "Original Matrix " << endl;
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }
    
    //Zerofy(matrix, ROW, COL);
    setZeros(matrix, ROW, COL);
    
    
    cout << "Zero Crossed Matrix" << endl;
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }
}

//Use 2 bool arrays to store the row index and col index, and nullify after
void setZeros(int matrix[ROW][COL], int ROW, int COL)
{   
    //keep track of rows to be nullified
    bool row[ROW];
    //keep track of columns to be nullified
    bool col[COL];
    
    //set bool arrays to all 0s, no 0 found yet
    for(int i = 0; i < ROW;i++)
    {
        row[i] = 0;
    }
 
    for(int i = 0; i < COL; i++)
    {
        col[i] = 0;
    }
    
    for(int i = 0; i <ROW; i++)
    {
        for(int j = 0; j <COL;j++)
        {
            //found a 0 in matrix
            if(matrix[i][j] == 0)
            {
                //update row and col arrays, to true, indicating that row or col must be nullified
                //because there is a zero somewhere there
                row[i] = true;
                col[j] = true;
            }
        }
    }
    //Nullify Rows
    //check each row
    for(int i = 0; i<ROW; i++)
    {   
        //if there was a zero in that row
        if(row[i])
        {
            //set every element to 0 at that row
            nullifyRow(matrix,i);
        }
    }
    
    //Nullify Columns
    //check each column
    for(int j = 0; j<COL; j++)
    {   
        //if there was a zero in that col
        if(col[j])
        {
            //set every element to 0 at that col
            nullifyCol(matrix,j);
        }
    }
    
}

//Nullify Functions
void nullifyRow(int matrix[ROW][COL], int row)
{
    for(int j = 0; j<COL; j++)
    {
        matrix[row][j] = 0;
    }
}

void nullifyCol(int matrix[ROW][COL], int col)
{
    for(int i = 0; i< ROW; i++)
    {
        matrix[i][col] = 0;
    }
}
/*****************/

//1st solution
//If zero found in matrix, replace all other elements with 0's
//in its column and row
void Zerofy(int matrix[ROW][COL], int ROW, int COL)
{
    int x = 0;
    int y  = 0;
    int i,j;
    for(i = 0; i<ROW; i++)
    {
        for(j = 0; j<COL; j++)
        {
            if(matrix[i][j] == 0)
            {
                x = i;
                y = j;
                break;
            }
        }
    }
    //x is row index that must be converted to all 0s
    //y is the column index that must be converted to all 0s
    
    //if index was set because of a found 0
    if( (x != 0 && y != 0) || (matrix[0][0] == 0) )
    {
        //change all elements to 0 in the y column
        for(int i = 0; i<ROW;i++)
        {
            matrix[i][y] = 0;
        }
        //change all elements to 0 in x column
        for(int i = 0; i<COL;i++)
        {
            matrix[x][i] = 0;
        }
    }
    
}