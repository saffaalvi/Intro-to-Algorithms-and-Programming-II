//extracts, sorts, and prints the words in a string in alphabetical order

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 300             //max number of characters in the string

//function prototype
void ParseSentence(char s[]);

//main function
int main()
{
    char s[MAX] = "hello world, how are you today.";    //string passed through function
    ParseSentence(s);       //calls function ParseSentence to extract and sort the words in string alphabetically
}

//function definition
void ParseSentence(char s[])
//this function extracts each word from a sentence and then re-prints the words in alphabetical order
//input: null-terminated string S
//output: no return value
{
    int count=0;                         //number of words
    unsigned long length = strlen(s);   //length of string
    char newList[length][length];   //new list with elements as each word in the previous array
    char swap[length];              //used as placeholder when swapping
    char *p_token = strtok(s, " ,;.");  //pointer for tokens for strtok

    //to tokenize the string:
    while(p_token!=NULL)
    {
        strcpy(newList[count], p_token);    //copies p_token (each word from string s) to newList
        count++;                            //increments number of words
        p_token = strtok(NULL, " ,;.");     //strtok starts again but at NULL
    }
    
    //to sort the words in the string alphabetically:
    for (int i=0; i<count; i++)         //loop to compare each element of newList to one another
        for (int j=i+1; j<count; j++)
        {
            if (strcmp(newList[i], newList[j])>0)   //if newList[i]>newList[j] then it will return greater than zero, meaning they should be swapped
            {
                //swapping
                strcpy(swap, newList[i]);
                strcpy(newList[i], newList[j]);
                strcpy(newList[j], swap);
            }
        }

    for (int c=0; c<count; c++)         //prints the newList, sorted
        printf("%s\n", &newList[c][0]);
}
