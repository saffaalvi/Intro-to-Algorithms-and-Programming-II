//Iterative and recursive functions to:
//find:
//1)Sum of previous Terms     2)Sum of Squares                                      3)Greatest Common Divisor
//4)Power                     5)Positive integers less than n and divisibly by m
//and 6)Draw a triangle of *

#include <stdio.h>
//Function prototypes (if there is an r before the function names, it is the recursive version, others are iterative)
int fun1(int n);
int rfun1(int n);
int fun2(int n);
int rfun2(int n);
long Fibonacci(long n);
long rFibonacci(long n);
int gcd(int x, int y);
int rgcd(int x, int y);
int Power(int a, int b);
int rPower(int a, int b);
void posDiv(int n, int m);
void rposDiv(int n, int m);
void rprintStars(int n);        //used for rDrawTriangle
void DrawTriangle(int n);
void rDrawTriangle(int n);

int main(void)
//The main function displays a menu for the user and asks for the user's choice of which function they would like to use. Based on the response, it then asks the user to enter either one or two integers and calls the appropriate function
//Input: one integer to choose from main menu and another one or two integers (depends on function chosen)
//Output: displays menu, asks for choice, asks for one or two integers, then displays iterative and recursive result based on function chosen
{
    int choice;             //user's choice of which function is used
    int num, num2;          //number(s) user enters
    long int itAnswer;      //answer from iterative version of the function
    long int reAnswer;      //answer from the recursive version of the function
    printf("Main Menu:\n");
    printf(" 0--Sum of Previous Terms\n 1--Sum of Squares\n 2--Fibonacci\n 3--Greatest Common Divisor\n 4--Power\n 5--Positive integers less than n and divisible by m\n 6--Draw a Triangle\n"); //displays menu of different functions
    printf("Please enter which function you would like to use: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 0:         //fun1 and rfun1
            printf("Please enter one integer (>=1): ");
            scanf("%d", &num);
            if (num<=0){            //number entered should be greater than 0
                printf("Invalid number! Run program again!");
                break;}
            itAnswer = fun1(num);
            reAnswer = rfun1(num);
            printf("Iterative answer = %ld and Recursive answer = %ld.", itAnswer, reAnswer);
            break;
        case 1:        //fun2 and rfun2
            printf("Please enter one integer (>=1): ");
            scanf("%d", &num);
            if (num<=0){           //number entered should be greater than 0
                printf("Invalid number! Run program again!");
                break;}
            itAnswer = fun2(num);
            reAnswer = rfun2(num);
            printf("Iterative answer = %ld and Recursive answer = %ld.", itAnswer, reAnswer);
            break;
        case 2:        //Fibonacci and rFibonacci
            printf("Please enter one integer (>=0): ");
            scanf("%d", &num);
            if (num<0){         //number entered should be greater than or equal to 0
                printf("Invalid number! Run program again!");
                break;}
            itAnswer = Fibonacci(num);
            reAnswer = rFibonacci(num);
            printf("Iterative answer = %ld and Recursive answer = %ld.", itAnswer, reAnswer);
            break;
        case 3:         //gcd and rgcd
            printf("Please enter two integers (>=0): ");
            scanf("%d%d", &num, &num2);
            if (num<0 || num2<0){   //numbers entered should be greater than or equal to 0
                printf("Invalid numbers! Run program again!");
                break;}
            itAnswer = gcd(num, num2);
            reAnswer = rgcd(num, num2);
            printf("Iterative answer = %ld and Recursive answer = %ld.", itAnswer, reAnswer);
            break;
        case 4:         //Power and rPower
            printf("Please enter two integers (>=0): ");
            scanf("%d%d", &num, &num2);
            if (num<0 || num2<0){   //numbers entered should be greater than or equal to 0
                printf("Invalid numbers! Run program again!");
                break;}
            itAnswer = Power(num, num2);
            reAnswer = rPower(num, num2);
            printf("Iterative answer = %ld and Recursive answer = %ld.", itAnswer, reAnswer);
            break;
        case 5:        //posDiv and rposDiv
            printf("Please enter two positive integers (first number must be less than second number): ");
            scanf("%d%d", &num, &num2);
            if (num<0 || num2<0){   //numbers entered should be greater than or equal to 0
                printf("Invalid numbers! Run program again!");
                break;}
            if (num>num2){          //first number must be less than second number
                printf("First number must be less than second number! Run program again!");
                break;}
            printf("Iterative: ");
            posDiv(num, num2);
            printf("Recursive: ");
            rposDiv(num, num2);
            break;
        case 6:        //DrawTriangle and rDrawTriangle
            printf("Please enter one integer (>0): ");
            scanf("%d", &num);
            if (num<=0){            //number entered should be greater than 0
                printf("Invalid number! Run program again!");
                break;}
            printf("Iterative: \n");
            DrawTriangle(num);
            printf("\nRecursive: \n");
            rDrawTriangle(num);
            break;
        default:      //any other number entered is not valid, must run program again and enter a valid number
            printf("Not an option! Please run again and enter a number between 0 and 6. Thank you!");
            break;
    }
}
//Function Definitions:
//SUM OF PREVIOUS TERMS (#1)
int fun1(int n)
//This function calculates the sum of the numbers preceding the number entered
//Input: one integer n (greater than or equal to 1)
//Output: returns an integer value of the sum of the numbers preceding the number entered (returns 1+2+...+n)
{
    int sum=0;
    for (int i=1; i<=n; i++){   //keeps adding numbers until n is reached
        sum = sum + i;}
    return sum;
}
int rfun1(int n)
//This function calculates the sum of the numbers preceding the number entered
//Input: one integer n (greater than or equal to 1)
//Output: returns an integer value of the sum of the numbers preceding the number entered (returns 1+2+...+n)
{
    if (n==1)
        return 1;
    else
        return(n + rfun1(n-1));
}
//SQUARED SUM (#2)
int fun2(int n)
//This function calculates the sum of the squares of integers, starting from 2, and ending at the square of the numberentered+1
//Input: one integer n (greater than or equal to 1)
//Output: returns positive integer (sum = (1+1)(1+1) + (2+1)(2+1) +...+ (n+1)(n+1))
{
    int sum=0;
    while(n!=0)
    {
        sum+=((n+1)*(n+1));
        n--;                    //decrements n each time so each number preceding n (until 0) is run through the sum formula
    }
    return sum;
}

int rfun2(int n)
//This function calculates the sum of the squares of integers, starting from 2, and ending at the square of the numberentered+1
//Input: one integer n (greater than or equal to 1)
//Output: returns positive integer (sum = (1+1)(1+1) + (2+1)(2+1) +...+ (n+1)(n+1))
{
    if (n==1)
        return 4;
    else
        return((n+1)*(n+1)+rfun2(n-1));
}
//FIBONACCI (#3)
long Fibonacci(long n)
//This function calculates the sum of the terms of the Fibonacci sequence that precede the term number entered
//input: one integer n (greater than or equal to 0)
//output: returns positive integer (sum = term0 + term1 + term2 +...+ termn)
{
    int sum=0;
    int first=0, second=1;      //term0 (first) is 0 and term1 (second) is 1
    if (n==0 || n==1)           //sum for term0 and term1 = term0 and term1 respectively
        return n;
    else{
        for(int i=1; i!=n; i++)     //loop to count up to n terms
        {
        sum=first+second;
        first=second;
        second=sum;
        }
    }
    return sum;
}

long rFibonacci(long n)
//This function calculates the sum of the terms of the Fibonacci sequence that precede the term number entered
//input: one integer n (greater than or equal to 0)
//output: returns positive integer (sum = term0 + term1 + term2 +...+ termn)
{
    if (n==0 || n==1)           //sum for term0 and term1 = term0 and term1 respectively
        return n;
    else
        return rFibonacci(n-1) + rFibonacci(n-2);
}
//GCD (#4)
int gcd(int x, int y)
//This function calculates the greatest common divisor of two numbers
//input: two integers (greater than or equal to 0)
//output: returns one positive integer (greatest common divisor of the two numbers entered)
{
    int result=0;
    for (int i=1; i<=x; i++)
    {
        if (x%i==0 && y%i==0)   //checks to make sure the number is a divisor of both x and y (no remainder)
        {
            result=i;
        }
    }
    return result;
}
int rgcd(int x, int y)
//This function calculates the greatest common divisor of two numbers
//input: two integers (greater than or equal to 0)
//output: returns one positive integer (greatest common divisor of the two numbers entered)
{
    if (y==0)
        return x;
    else
        return rgcd(y, x%y);
}
//POWER (#5)
int Power(int a, int b)
//This function takes the first integer entered as a base and raises itself to the exponent of the second number entered (calculating a to the power of b)
//input: two integers (greater than or equal to 0, where a is the base and b is the exponent)
//output: returns one positive integer (a*a*a...*a (b times))
{
    int result = 1;
    while(b!=0)
    {
        result = result*a;
        b--;                    //decrements b each time (until it reaches 0) so a is only multiplied by itself b times
    }
    return result;
}
int rPower(int a, int b)
//This function takes the first integer entered as a base and raises itself to the exponent of the second number entered (calculating a to the power of b)
//input: two integers (greater than or equal to 0, where a is the base and b is the exponent)
//output: returns one positive integer (a*a*a...*a (b times))
{
    if (b==0)
        return 1;
    else
        return (a*Power(a, b-1));
}
//POSITIVE INTEGERS LESS THAN N AND DIVISIBLE BY M (#6)
void posDiv(int m, int n)
//This function calculates and prints the positive integers that are less than the value of n and dividible by m, where m<n
//input: two integers (greater than or equal to 0, and first<second)
//output: several positive integers printed (less than n and divisible my m)
{
    while(n!=0)        //all positive integers below n
    {
        if(n%m==0)              //checks to see if i is a divisor of m
            printf("%d ",n);    //prints all numbers less than n and divisible by m
        n--;
    }
}
void rposDiv(int m, int n)
//This function prints the positive integers that are less than the value of n and dividible by m, where m<n
//input: two integers (greater than or equal to 0, and first<second)
//output: several positive integers printed (less than n and divisible my m)
{
    if(n<=0)           //stops from being an infinite loop
        return;
    if(n%m==0)          //divisible so print the numbers
        printf("%d ", n);
    rposDiv(m, n-1);
}
//DRAW TRIANGLE (#7)
void DrawTriangle(int n)
//This function displays/prints a right triangle made of asterisks with the height being the number entered by the user
//Input: one integer (greater than 0)
//Output: prints right triangle made with asterisks, of height n
{
    int i;
    for (i=0; i<n; i++){            //number of rows
        for (int x=0; x<=i; x++){   //number of stars in each row
            printf("*");}           //prints number of stars in each row
        printf("\n");}              //starts at new row
}
void rprintStars(int n)
//This function prints the amount of asterisks needed in each row, it is then used in the function rDrawTriangle to be displayed in the correct order
//input: one integer (greater than 0)
//output: prints each row of asterisks in correct length
{
    if (n==1)
        printf("*");
    else
    {
        rprintStars(n-1);       //prints number of stars in each row (recursive step)
        printf("*");
    }
}

void rDrawTriangle(int n)
//This function displays/prints a right triangle made of asterisks with the height being the number entered by the user
//Input: one integer (greater than 0)
//Output: prints right triangle made with asterisks of height n (this function works with rprintStars to complete the triangle)
{
    if(n==1)
    {
        rprintStars(1);     //first row (prints one star)
        printf("\n");       //new row started
    }
    else{
        rDrawTriangle(n-1); //recursive step
        rprintStars(n);     //prints stars
        printf("\n");       //new row started
    }
}
