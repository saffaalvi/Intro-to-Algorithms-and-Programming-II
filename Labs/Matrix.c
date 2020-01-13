//allows user to set matrix data, then prints the matrix.
//checks if matrix is a distinct square and/or a magic square
//gets the transpose of the matrix and also sorts and prints sorted original matrix

#include <stdio.h>
#define MAX 100             //maximum size of the matrix is 100
//function prototypes
void setMatrixData(int numOfRows, int mat[][numOfRows]);
void printMatrixData(int numOfRows, int mat[][numOfRows]);
int isMagicSquare(int numOfRows, int mat[][numOfRows]);
int isDistinctSquare(int numOfRows, int mat[][numOfRows]);
void SortRowWise(int numOfRows, int mat[][numOfRows]);
void GetTranspose(int numOfRows, int mat[][numOfRows], int tran[][numOfRows]);

//main function
int main()
{
    int matrix[MAX][MAX];           //original matrix
    int transpose[MAX][MAX];        //transpose of original matrix
    int numOfRows;                  //size of square matrix (number of rows and columns)
    printf("Enter the size of the square matrix (>0 and <=100): ");
    scanf("%d", &numOfRows);
    if (numOfRows<0 || numOfRows>100){      //size must be positive and less than or equal to 100
        printf("Number must be in range! Run again with a valid size!\n");
        return 0;}
    setMatrixData(numOfRows, matrix);       //sets matrix data
    printf("Your matrix is set to:\n");
    printMatrixData(numOfRows, matrix);     //prints matrix
    if (isDistinctSquare(numOfRows, matrix) == 1){
        printf("This matrix is a distinct matrix! ");   //if it is a distinct matrix (return value of isDistinctSquare = 1) it will check to see if its also a magic square
        if (isMagicSquare(numOfRows, matrix) == 1){     //if return value of isMagicSquare = 1, it is a magic square
            printf("This matrix is also a magic square!");}
        else{                                           //if return value of isMagicSquare isn't 1, it isn't a magic square
            printf("This matrix is not a magic square.");}
    }
    else{                                               //if it is not a distinct matrix, it is also not a magic square
        printf("This matrix is not a distinct matrix or a magic square.");}
    printf("\nThe transpose of this matrix is:\n");
    GetTranspose(numOfRows, matrix, transpose);         //sets and prints transpose matrix
    SortRowWise(numOfRows, matrix);                     //sorts and prints sorted original matrix
    
    printf("Done...\n");
    return 0;
}

//function definitions
void setMatrixData(int numOfRows, int mat[][numOfRows])
//This function asks the user for integers and sets them as the elements in the matrix (2D array)
//Input: integers (from user), parameters of the function are the integer number of rows/columns and the integer array "matrix"
//Output: no return value, asks user to enter integers
{
    for (int i=0; i<numOfRows; i++)
    {
        for (int c=0; c<numOfRows; c++)
        {
            printf("Enter the integer in row %d and column %d: ", i, c);    //asks user to input integer for each position in the matrix
            scanf("%d", &mat[i][c]);        //sets entered integer in each element of the matrix
        }
    }
}

void printMatrixData(int numOfRows, int mat[][numOfRows])
//This function prints the matrix (elements entered by the user) in a tabular format
//Input: no input by user, parameters: integer array "matrix" with data set in setMatrixData and integer number of rows/columns in matrix
//Output: no return value, prints out matrix in tabular format
{
    for (int i=0; i<numOfRows; i++)
    {
        for (int c=0; c<numOfRows; c++)
        {
            printf("%d ", mat[i][c]);       //prints each element in each position
        }
        printf("\n");                   //starts a new line for each row
    }
}

int isMagicSquare(int numOfRows, int mat[][numOfRows])
//This function checks to see if the matrix entered is a magic square (filled with distinct positive integers and the sum in each row, column and diagonal is equal)
//input: no input from user, parameters are integer array "matrix" set from setMatrixData and integer number of rows/columns
//output: integer value, returns 0 if matrix is not a magic square, returns 1 if matrix is a magic square
{
    int sumOfDiagonal = 0, sumOfDiagonalTwo=0;              //sum of two diagonals
    for (int d = 0; d<numOfRows; d++){
        sumOfDiagonal+=mat[d][d];                           //sum of first diagonal (from left to right), will be compared to everything to see if sums            are the same
        sumOfDiagonalTwo+=mat[d][numOfRows-d-1];}           //sum of second diagonal (from right to left)
    for (int i=0; i<numOfRows; i++)
    {
        int sumOfRow = 0;                 //sum of rows
        int sumOfColumn = 0;              //sum of columns
        for (int c=0; c<numOfRows; c++)
        {
            if (mat[i][c]<0){           //if the matrix contains any negative integers, it is not a magic square
                return 0;}
            sumOfRow+=mat[i][c];        //adds each element of the row to sumOfRow
            sumOfColumn+=mat[c][i];     //adds each element of the column to sumOfColumn
        }
        if (sumOfDiagonal!=sumOfDiagonalTwo || sumOfDiagonal!=sumOfRow || sumOfDiagonal!=sumOfColumn)   //every sum must equal each other
            return 0;
    }
    return 1;               //will return 1 if all conditions are satisfied (means it is a magic square)
}
int isDistinctSquare(int numOfRows, int mat[][numOfRows])
//This function checks to see whether the matrix is distinct (no elements are repeated)
//input: no input from user, parameters are integer number of rows/columns and integer array "matrix"
//output: integer value, returns 0 if matrix is not distinct, returns 1 if matrix is distinct
{
    for (int i=0; i<numOfRows; i++)
    {
        for (int c=0; c<numOfRows; c++)
        {
            int check=mat[i][c];            //element of matrix that is compared each time
            for (int r=0; r<numOfRows; r++)
            {
                for (int j=0; j<numOfRows; j++)
                {
                    if (i!=r && c!=j && check==mat[r][j]){  //if the element equals any other element (other than when its that same position) it is not a distinct matrix, so return 0
                        return 0;}
                }
            }
        }
    }
    return 1;                   //if no element equals the other, it will satisfy all conditions and is distinct so return 1
}

void SortRowWise(int numOfRows, int mat[][numOfRows])
//This function sorts the matrix with a row-wise approach; each row is sorted in ascending order
//Input: no input from the user, parameters: integer number of rows/columns and integer array "matrix"
//Output: no return value, prints out the new sorted matrix using the function printMatrixData
{
    for (int i=0; i<numOfRows; i++)
    {
        for (int c=0; c<numOfRows-1; c++)
        {
            for (int m=c+1; m<numOfRows; m++)
                if (mat[i][c] > mat[i][m])
                {
                    int swap = mat[i][c];           //acts as a placeholder for the first value
                    mat[i][c] = mat[i][m];          //swap places, first value now becomes second
                    mat[i][m] = swap;               //smaller value
                }
            
        }
    }
    printf("After sorting your original matrix, your new matrix is:\n");
    printMatrixData(numOfRows, mat);           //uses printMatrixData to print new sorted matrix
    
}

void GetTranspose(int numOfRows, int mat[][numOfRows], int tran[][numOfRows])
//This function takes elements of the original matrix, switching the rows and columns and setting them as elements in the integer array "transpose" to create the transpose of the original matrix
//Input: no input from the user, parameters: integer number of rows/columns and integer arrays "matrix" and "transpose"
//Output: no return value, prints the transpose matrix
{
    for (int i=0; i<numOfRows+1; i++)           //loops to go through each element of the matrix
    {
        for (int j=0; j<numOfRows; j++)
        {
            tran[i][j] = mat[j][i];     //the elements of the transpose matrix are arranged by switching the rows and columns of the original matrix
        }
    }
    printMatrixData(numOfRows, tran);   //uses the function printMatrixData to print the transpose matrix
}
