#include <iostream>
using namespace std;

const int ROWS = 4;
const int COL = 4;
void rotate(int matrix[ROWS][COL], int n);


int main()
{
    int matrix[ROWS][COL] = {
        {1,1,1,1},
        {2,2,2,2},
        {3,3,3,3},
        {4,4,4,4}
    };
    
    cout << "Unrotated Matrix" << endl;
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }
    
    //pass ROWS or COL because NxN
    rotate(matrix, ROWS);
    
    cout << endl;
    
    cout << "Rotated Matrix" << endl;
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }
}

//Rotates NxN matrix by 90 degrees, O(n^2)
void rotate(int matrix[ROWS][COL], int n)
{
    //iterate through layers in matrix first
    //a Matrix has n/2 layers 4x4 has 2, 5x5 has 2 layers
    for(int layer = 0; layer < n/2; ++layer)
    {   
        //set start and end points for iteration within a layer
        //last is the length of the side n-layer inward -1
        int first = layer;
        int last = n - layer - 1;
        for(int i  = first; i < last; ++i)
        {
            //offset changes after 4 elements have been swapped, now the next elements within
            //the layer can be swapped
            int offset = i - first;
            
            //column changes means second index changes with iteration
            //row changes means first index changes with iteration
            
            //save top
            int top = matrix[first][i];
            
            //move left to top
            matrix[first][i] = matrix[last-offset][first];
                
            //move bottom to left
            matrix[last-offset][first] = matrix[last][last-offset];
                
            //move right to bottom
            matrix[last][last-offset] = matrix[i][last];
            
            //move top to right
            matrix[i][last] = top;
            
        }
    }
}