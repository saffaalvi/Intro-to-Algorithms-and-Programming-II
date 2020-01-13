//Sorts an array into ascending order and prints sorted array
//Calculates the sum, average, minimum, and maximum of the array
//Reverses the elements of the array and prints reversed array

#include <stdio.h>

//function prototypes
void swap(int * var1, int * var2);
void Sort(int size, int array[]);
void PrintArray(int size, int array []);
void ArrayInfo(int array[], int size, float *sum, float *average, int *min, int *max);
void ReverseArray (int size, int *ptr2Array);

//main function
int main() {
    int min, max;           //minimum and maximum number
    float sum, average;     //sum of elements and average of elements in array
    int data [] = {2, 7, 8, -8, 1, 9, 3, 5};
    Sort(sizeof(data)/sizeof(int), data);           //calls function Sort (sorts array into ascending array)
    PrintArray(sizeof(data)/sizeof(int), data);     //calls PrintArray to print out elements of array
    ArrayInfo(data, sizeof(data)/sizeof(int), &sum, &average, &min, &max);  //calls ArrayInfo with the addresses of sum, average, min, and max (addresses will get values in function which will be printed in this main function
    printf("Sum = %.0f\nAverage = %.2f\nMinimum: %d\nMaximum: %d\n", sum, average, min, max);
    ReverseArray (sizeof(data)/sizeof(int), data);          //calls ReverseArray which reverses the order of the elements in the array
    PrintArray(sizeof(data)/sizeof(int), data);             //calls PrintArray which prints the new reversed array
    return 0;
}

//function definitions
void PrintArray(int size, int array [])
//This function prints the array index, value at that index, and memory address of the elements in the array
//Input: integer size of array, integer array (data)
//Output: no return value, displays index, elements, and memory addresses of array
{
    for(int i=0; i<size; i++)
    {
        printf("array[%d] = %d, memory address = %p \n", i, array[i], &array[i]);
    }

}

void swap(int * var1, int * var2)
//This function swaps two value in the array
//Input: int *var1 (value of var1) and int *var2 (value of var2)
//Output: no return value, swaps the elements in the array
{

    int temp;           //placeholder
    temp = *var1;
    *var1 = *var2;
    *var2 = temp;
    
}

void Sort(int size, int array[])
//This function sorts the elements of the array in ascending order
//Input: integer size of array, integer array (data)
//Output: no return value, changes the order of elements in the array
{

    int done = 0;           //flag to indicate no swap has occurred
    for (int i=0; i<size-1 && !done; i++)       //starts from left of array
    {
        done=1;             //if done swapping, no swap occurs in this next pass
        for (int j=size-1; j>i; j--)            //starts from right of array
        {
            if (array[j]<array[j-1])
            {
                swap(&array[j], &array[j-1]);      //calls function swap to swap values of array
                done=0;     //swap occurred, not done
            }
        }
    }
}

void ArrayInfo(int array[], int size, float *sum, float *average, int *min, int *max)
//this function calculates the sum, average, minimum value, and maximum value of the elements in the array and sets them as the values the addresses of sum, average, min, and max
//Input: integer array (data), integer size of array, float *sum (value of sum), float *average (value of average), integer *min (value of min), integer *max (value of max)
//Output: no return value, sets the values for sum, average, min, and max used in the main function
{
    float arrSum=0;             //sum of elements in array
    *min = array[0];            //minimum value in array (since it's sorted, it's the first element)
    *max = array[size-1];       //maximum value in array (since it's sorted, it's the last element)
    for (int i=0; i<size; i++)  //loop to go through each element of array
        arrSum+=array[i];       //adds each element of array to arrSum
    *sum = arrSum;              //value of sum is arrSum
    *average = (arrSum/size);   //value of average is the sum/number of elements (size)
}

void ReverseArray (int size, int *ptr2Array)
//This function reverses the order of the elements in the array (descending)
//Input: integer size of array, integer *ptr2Array (element of array)
//Output: no output, changes the order of elements in the array
{
    int temp;               //placeholder
    int start = 0, end = size-1;    //start is first element, end is last element
    while(start<end)                //when start>=end, loop will end
    {
        temp = ptr2Array[end];              //temp is address of last element
        ptr2Array[end] = ptr2Array[start];  //address of last element becomes address of first element
        ptr2Array[start]=temp;              //address of first element becomes address of temp
        start++;      //increments start so loop can continue with next element
        end--;        //decrements end so loop can continue with second last element, etc.
    }
    
}

