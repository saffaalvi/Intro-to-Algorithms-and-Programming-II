//Assignment 1
//Allows user to set size of 2D array then populate it with random numbers between a min and max number entered by user
//Displays the array
//Finds the largest number in array, sums a column (entered by user), and sorts the array in ascending or descending order
//Copies contents of array A into array B exactly
//Copies contents of array A into array B (of same size) so that array B has the contents of array A in clockwise spiral sorted order
//Displays array B

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COL 20          //max column size is 20
#define ROW 20          //max row size is 20

//FUNCTION PROTOTYPES
void PopulateArray2DUnique(int A[][COL], unsigned int rowsize, unsigned int colsize, int min, int max);
void DisplayArray2D(int A[][COL], unsigned int rowsize, unsigned int colsize);
int FindLargest(int A[][COL], unsigned int rowsize, unsigned int colsize);
int FindColSum(int A[][COL], unsigned int rowsize, unsigned int colsize, unsigned int col_to_sum);
int Sort2DArray(int A[][COL], unsigned int rowsize, unsigned int colsize, int order);
int CopyArray2D(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize);
int CopyArray2DSpiral(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize);

//MAIN FUNCTION
int main()
{
    int A[ROW][COL];  //matrix A with max size [20][20]
    int B[ROW][COL];    //matrix B with max size [20][20] - used as a copy of matrix A
    unsigned int rowsize, colsize;   //size of row and column entered by user (must be positive)
    int max, min;
    int col;                //column to sum, entered by user
    int order;              //order to sort matrix, entered by user (ascending or descending)
    printf("Enter rowsize (>0 and <=20): ");
    scanf("%d", &rowsize);
    printf("Enter colsize (>0 and <=20): ");
    scanf("%d", &colsize);
    printf("Enter min number for elements in array: ");
    scanf("%d", &min);
    printf("Enter max number for elements in array: ");
    scanf("%d", &max);
    PopulateArray2DUnique(A, rowsize, colsize, min, max);         //populates array A with random integers between min and max
    DisplayArray2D(A, rowsize, colsize);
    int largest = FindLargest(A, rowsize, colsize);               //the largest number in array A
    printf("The largest number in the array is %d\n", largest);
    printf("Enter column to sum: ");
    scanf("%d", &col);
    int colSum =  FindColSum(A, rowsize, colsize, col);          //sum of column number entered by user
    printf("Sum of column: %d\n", colSum);
    printf("Enter order for sorting matrix (1 = ascending, 2 = descending): ");
    scanf("%d", &order);
    int ord = Sort2DArray(A, rowsize, colsize, order);          //sorts array in ascending (1) or descending order (2)
    if (ord == 1)
        printf("Your new matrix in ascending order is:\n");
    else
        printf("Your new matrix in descending order is:\n");
    DisplayArray2D(A, rowsize, colsize);
    CopyArray2D(A, B, rowsize, colsize);                    //copies elements of array A into array B
    printf("Matrix B (Copy of Matrix A) is: \n");
    DisplayArray2D(B, rowsize, colsize);
    printf("Spiral Form: \n");
    CopyArray2DSpiral(A, B, rowsize, colsize);
    DisplayArray2D(B, rowsize, colsize);
    return 0;
}

//FUNCTION DEFINITIONS
void PopulateArray2DUnique(int A[][COL], unsigned int rowsize, unsigned int colsize, int min, int max)
//This function populates array A with random integers between the min and max entered by the user
//Input: parameters - int array A, unsigned int row size (entered by user), unsigned int column size (entered by user), minimum and maximum numbers entered by user for the range of the random elements in the array
//Output: no return value, sets elements of the array
{
    srand(time(NULL));                  //ensures random elements are changed every time program is run
    for (int i=0; i<rowsize; i++)
    {
        for (int c=0; c<colsize; c++)
        {
            A[i][c] = min + (rand() % (max+1-min));     //sets each element of the array with a random number ranging between min and max
        }
    }
}
void DisplayArray2D(int A[][COL], unsigned int rowsize, unsigned int colsize)
//this function prints array A with the elements assigned in function PopulateArray2DUnique
//input: parameters - int array A, unsigned int row size, unsigned int column size
//output: no return value, prints array A
{
    for (int i=0; i<rowsize; i++)
    {
        for (int c=0; c<colsize; c++)
        {
            printf("%d\t", A[i][c]);       //prints each element in each position
        }
        printf("\n");
    }
}
int FindLargest(int A[][COL], unsigned int rowsize, unsigned int colsize)
//This function finds the largest element in the array and returns it
//input: parameters - int array A, unsigned int row size, unsigned int column size
//output: returns integer value max (largest number in array)
{
    int max = A[0][0];
    for (int i=0; i<rowsize; i++)
    {
        for (int c=0; c<colsize; c++)
        {
            if (A[i][c] > max)              //if element is greater than max, max becomes that element
                max = A[i][c];
        }
    }
    return max;
}
int FindColSum(int A[][COL], unsigned int rowsize, unsigned int colsize, unsigned int col_to_sum)
//This function find the sum of the column entered by user and returns it
//input: parameters - int array A, int row size, int column size, int col_to_sum (column user wants to sum)
//output: returns integer sum of column
{
    int sum = 0;                    //sum of column
    for (int i=0; i<rowsize; i++)
    {
        sum+=A[i][col_to_sum];      //sum adds each element of new row but same column to itself
    }
    return sum;
}
int Sort2DArray(int A[][COL], unsigned int rowsize, unsigned int colsize, int order)
//This function sorts the array A in either ascending or descending order depending on what the user enters
//input: parameters - int array A, int array B, unsigned int row size, unsigned int column size, int order
//output: returns integer variable ord to indicate ascending order (1) or descending order (2)
{
    int temp;                           //temporary value for element
    int ord = 0;                        //order of sort (ascending or descending)
    {
        for (int c=0; c<colsize; c++)
        {
            for (int m=0; m<rowsize; m++)
            {
                for (int n=0; n<colsize; n++)
                {
                    if (order == 1){            //ascending
                    if(A[i][c]<A[m][n])
                    {
                        temp = A[i][c];
                        A[i][c]=A[m][n];
                        A[m][n]=temp;
                        ord = 1;                //ord is 1 to indicate ascending
                    }
                    }
                    else{                       //descending
                        if(A[i][c]>A[m][n])
                        {
                            temp = A[i][c];
                            A[i][c]=A[m][n];
                            A[m][n]=temp;
                            ord = 2;                //ord is 2 to indicate descending
                        }
                    }
                }
                }
            }
        }
    return ord;            //returns ord (ascending or descending)
}
int CopyArray2D(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize)
//This function copies the elements of array A into array B
//input: parameters - int array A, int array B, unsigned int row size, unsigned int column size
//output: returns 0 at end of function
{
    for (int i=0; i<rowsize; i++)
    {
        for (int c=0; c<colsize; c++)
        {
            B[i][c] = A[i][c];                  //each element of B[i][c] is set to the element in A[i][c]
        }
    }
    return 0;           //returns 0 for end of function
}
int CopyArray2DSpiral(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize)
//This function copies contents of array A into array B (of same size) so that array B has the contents of array A in clockwise spiral sorted order
//input: parameters - int array A, int array B, unsigned int row size, unsigned int column size
//output: returns 0 at end of function

{
    int rowPos = 0, colPos = 0;     //used for position of row and column in array A
    int r=0, c=0;                       //used for position of row and column in array B
    int m=rowsize, n=colsize;           //since rowsize and colsize will be decremented, copied them into variables m and n so original don't get                                       changed
    while(1)                  //when going through the elements in the rows and columns, they must be less than the rowsize and columnsize
    {
        //loop for going from left of the row to the right of the row
        for (int i=c; i<n; i++)
        {
            B[r][i]=A[rowPos][colPos];      //sets element of A into the proper position in matrix B
            colPos++;                       //increments colPos to get every element in the row
            if (colPos == colsize){         //indicates when to start next row
                rowPos++;                   //goes to next row
                colPos = 0;                 //position of the column returns to 0
                if (rowPos==rowsize)        //breaks loop if rowsize is reached
                    return 0;
            }
        }
        r++;                //r is incremented for use in the next loop
        
        //loop for going from top of the column to bottom of the column
        for (int i=r; i<m; i++)
        {
            B[i][n-1] = A[rowPos][colPos];
            colPos++;
            if (colPos == colsize){
                rowPos++;
                colPos = 0;
                if (rowPos==rowsize)
                    return 0;
            }
        }
        n--;                //n is decremented for use in next loop
        
        //loop for going from right of the row to the left of the row
        for (int i = n-1; i >= c; i--)
        {
            B[m-1][i] = A[rowPos][colPos];
            colPos++;
            if (colPos == colsize){
                rowPos++;
                colPos = 0;
                if (rowPos==rowsize)
                    return 0;
            }
        }
        m--;              //m is decremented for use in next loop
   
        //loop for going from bottom of column to top of column
        for (int i = m-1; i >= r; i--)
        {
            B[i][c] = A[rowPos][colPos];
            colPos++;
            if (colPos == colsize){
                rowPos++;
                colPos = 0;
                if (rowPos==rowsize)
                    return 0;
            }
        }
        c++;            //c is incremented for use in first loop
    }
    return 0;           //returns 0 for end of function
}
    
    
