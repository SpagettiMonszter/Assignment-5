#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Matrix
{
private:

    int matrixRows;
    int matrixColumns;
    int **myMatrix;

public:
    // parameterized constructor 
    // parameters include rows and columns of type int
    Matrix(int rows, int columns)
    {
        matrixRows = rows;
        matrixColumns = columns;
        myMatrix = new int*[matrixRows];
        
        for(int index = 0; index < matrixRows; index++)
        {
            myMatrix[index] = new int[matrixColumns];
        }
    }

    // function to fill the matrix with random values
    void fillMatrix() 
    {
        srand(time(nullptr));
        for (int a = 0; a < matrixRows; a++)
        {
            for (int b = 0; b < matrixColumns; b++)
            {
                myMatrix[a][b] = rand() % 100;
            }
        }
    }

    // print matrix to console
    void printMatrix()
    {
        for (int a = 0;  a < matrixRows; a++)
        {
            for( int b = 0; b < matrixColumns; b++)
            {
                // print rowxcolumn
                cout << myMatrix[a][b] << " ";
            }
            cout << endl;
        }
    }

    // destructor - deallocate memory
    // avoid memory loss
    
    ~Matrix() 
    {
        for (int index = 0; index < matrixRows; index++)
        {
            delete[] myMatrix[index];
        }
        delete[] myMatrix;
    }
};

int main()
{

    int rows=0;
    int columns=0;

    cout<<"Enter rows and columns: "<<endl;
    cin>>rows>>columns;

    int **board=new int *[rows];
    for(int i=0; i<rows; i++){
        board[i]=new int[columns];
    }


    cout<<"Enter matrix: "<<endl;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            board[i][j]=rand()%100;
        }
    }    

    cout<<"Print matrix: "<<endl;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }    


    for(int i=0; i<rows; i++){
    // 
        if(board!=NULL)
            delete [] board[i];
        }

        delete [] board;
        board=nullptr;
        cout<<endl;
    
    return 0;

};

