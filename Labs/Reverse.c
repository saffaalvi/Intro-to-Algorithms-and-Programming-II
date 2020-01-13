//Reverse a buffer through both an iterative and recursive approach

#include <stdio.h>
#include <string.h>

//function prototypes
void Reverse(char *ptrArray);
void RecursiveReverse(char *ptrArray, int start, int end);

//main function
int main()
{
    //PART 1
    char Buffer1[] = {'t','h','i','s',' ','i','s',' ', 't', 'h', 'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'b', 'u', 'f', 'f', 'e', 'r', '.', '\0'};      //first buffer
    char Buffer2[] = "this is the second buffer.";      //second buffer
    char Buffer3[80];                                   //third buffer
    printf("PART 1: \n");
    printf("Enter the string for Buffer3 (at most 79 characters): ");
    scanf("%79[^\n]s", Buffer3);        //sets characters entered as elements of Buffer3, ensures it doesn't go over 79 characters and that it reads the string including whitespace characters
    printf("Buffer 1: %s \nBuffer 2: %s \nBuffer 3: %s\n", Buffer1, Buffer2, Buffer3);
    
    //PART 2
    printf("PART 2: \n");
    char *pBuffer = Buffer3;        //pBuffer is a pointer variable initialized to point to Buffer3
    printf("Displaying the contents of Buffer3 using a while loop: ");
    while (*pBuffer != '\0')         //loop continues until null character is reached
    {
        printf("%c", *pBuffer++); //displays the characters of Buffer3 using the pointer pBuffer
    }
    printf("\n");
    
    //Part 3
    printf("PART 3: \n");
    char revBuffer[] = "HELLO WORLD!";                //array reversed by iterative function
    char revRecBuffer[] = "HELLO WORLD!";             //array reversed by recursive function
    //iterative
    printf("Before reversing, revBuffer is %s\n", revBuffer);   
    Reverse(revBuffer);         //calls Reverse function to iteratively reverse revBuffer
    printf("Reverse of revBuffer using iteration is: %s\n", revBuffer);
    //recursive
    printf("Before reversing, revRecBuffer is %s\n", revRecBuffer);
    int length = strlen(revRecBuffer);                  //length of array
    RecursiveReverse(revRecBuffer, 0, length-1);        //calls RecursiveReverse function to recursively reverse revRecBuffer
    printf("Reverse of revRecBuffer using recursion is: %s\n", revRecBuffer);
    
}

//PART 3
void Reverse(char *ptrArray)        //iterative function definition
//This function reverses the elements in an array using iteration by swapping the elements
//Input: parameter - pointer variable ptrArray, when function is called, array revBuffer is used
//no output or return
{
    int length = strlen(ptrArray);    //length of array
    for (int i=0; i<length; i++, length--)      //loop to go through each element of array
    {
        char temp;          //placeholder used for swapping
        //swapping the elements
        temp = ptrArray[i];
        ptrArray[i] = ptrArray[length-1];
        ptrArray[length-1] = temp;
    }
}
void RecursiveReverse(char *ptrArray, int start, int end) //recursive function definition
//This function reverses the elements in an array using recursion by swapping the elements
//Input: parameters - pointer variable ptrArray, starting character, ending character, when function is called, array recRevBuffer is used
//no output or return
{
    char temp;                  //placeholder used for swapping
    if (start>=end)             //base case
        return;
    //swapping the elements of the array:
    temp = ptrArray[start];
    ptrArray[start] = ptrArray[end];
    ptrArray[end] = temp;
    RecursiveReverse(ptrArray, ++start, --end);        //recursive step
}
