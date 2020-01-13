//Assignment 2 - Anagrams
//Checks if words entered by user are anagrams of each other and assigns each word to an anagram group

//LIBRARY HEADERS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//FUNCTION PROTOTYPES
void ReadWord(char word[]);
void AssignAnagramGroup(int wordcount);
bool isAnagram(char word1[],char word2[]);
void SortWordList();
void CalculateTopFiveGroups();

//GLOBAL VARIABLES
char WordList[101][21];         //list of words, stores up to 100 words
int AnagramGroup[101];          //stores corresponding group ID for each word
int wordcount=0;                //number of words in the list
int anagramgroupcount=1;        //number of anagram groups
int anagramgroupsizes[101];     //stores size of each anagram group depending on its index
int sortedgroupid[101];         //stores id of sorted anagrams groups

//MAIN FUNCTION
int main()
{
    char word[21];      //inputted words that go into the WordList
    printf("Enter the words in the list (maximum 100 words, maximum 20 characters in each word, STOP to end):\n");
    
    do{
        ReadWord(word);                                 //reads each word inputted and stores it into array
        if (strcmp(word, "STOP")==0 || wordcount > 99) //loop will keep running until STOP is entered or 100 words have been reached
            break;
        strcpy(WordList[wordcount++], word);    //copies the words entered by user into WordList
        AssignAnagramGroup(wordcount-1);        //assigns each word in WordList to an anagram group
    }while(1);
    
    SortWordList();
    CalculateTopFiveGroups();
    
    //DISPLAYING OUTPUT:
    for(int i=1; i<=5; i++)
    {
        if (anagramgroupsizes[i]==0)          //won't print groups of size 0
            continue;
        printf("Group of size %d ", anagramgroupsizes[i]);
        for(int j=0; j<wordcount; j++)
        {
            if(AnagramGroup[j]==sortedgroupid[i])
                printf("%s ", WordList[j]);
        }
        printf("\n");
    }
    return 0;
}


//FUNCTION DEFINITIONS

void ReadWord(char word[])
//This function stores the string entered by the user into array word
//Input: parameter - character array word
//Output: no return value
{
    scanf ("%20s", word);   //will only scan first 20 characters (maximum number of characters)
}

bool isAnagram(char word1[],char word2[])
//This function checks whether two words are anagrams of each other by tracking how many times each letter appears in each word and comparing the amounts
//Input: parameters - character arrays word 1 and word 2
//Output: bool values, 0 if the two words aren't anagrams and 1 if they are anagrams
{
    int c=0;                //index for arrays
    int done=0;             //to keep loop running
    int f, s;               //index used to track frequencies
    int word1letters[26]={0}, word2letters[26]={0};  //two arrays to track how many times each letter appears in word1 and word2
    
    //WORD1
    do{                         //do...while loop to go through each letter of word1
        if (word1[c] == '\0')   //loop will end when null character of word1 is reached
            break;
        f = word1[c]-'a';       //subtracts 'a' from each letter of word1
        word1letters[f]++;      //increments number in index f of array word1letters
        c++;                    //increments c to go to next letter in word1
    }while(!done);
    
    c=0;
    
    //WORD2
    do{
        if (word2[c] == '\0')   //loop will end when null character of word2 is reached
            break;
        s = word2[c]-'a';       //subtracts 'a' from each letter of word2
        word2letters[s]++;      //increments number in index s of array word2letters
        c++;                    //increments c to go to next letter in word2
    }while(!done);
    
    //COMPARING WORD1 AND WORD2
    for (int i=0; i<26; i++)        //loop to go through each element of word1letters and word2letters
    {
        if(word1letters[i]!=word2letters[i])    //not an anagram
        {
            return 0;               //return 0
        }
    }
    return 1;                      //if 0 isn't returned, it is an anagram so return 1
}

void AssignAnagramGroup(int wordcount)
//This function will assign each word in WordList to an anagram group
//Input: integer wordcount (total number of words in WordList)
//Output: no return value
{
    int i;                      //counter for loop, used as index for arrays
    if(wordcount==0)            //the first word in the list
    {
        AnagramGroup[0]=1;          //anagram group of first word is 1
        anagramgroupsizes[1]=1;     //group id of first word is 1
    }
    else            //assigns all other words to anagram groups
    {
        for(i=0; i<wordcount; i++)
        {
            //assigning anagrams to the same groups:
            if(isAnagram(WordList[wordcount],WordList[i]) == 1)
            {
                AnagramGroup[wordcount]=AnagramGroup[i];
                anagramgroupsizes[AnagramGroup[i]]+=1;          //adds one to the number of words in that anagram group size
                break;
            }
        }
        if (i==wordcount)                //creates a new group for the word at the end of WordList
        {
            AnagramGroup[wordcount]=++anagramgroupcount;        //increments number of anagram groups
            anagramgroupsizes[AnagramGroup[i]]+=1;              //adds one to the number of words in that anagram group size
        }
    }
}

void SortWordList()
//This function sorts the words in WordList alphabetically
//Input: no input
//Output: no return value
{
    char tempchar[21];  //placeholder for swapping words within the list
    
    //alphabetically sorting the list:
    for (int i=0;i<wordcount;i++)
    {
        for (int j=0;j<wordcount-1;j++)
        {
            if (strcmp(WordList[j],WordList[j+1])>0)
            {
                //switching the positions of the words in WordList
                strcpy(tempchar,WordList[j]);
                strcpy(WordList[j],WordList[j+1]);
                strcpy(WordList[j+1],tempchar);
                
                //switching the positions of the groups in AnagramGroup for words switched above
                int temp=AnagramGroup[j];
                AnagramGroup[j]=AnagramGroup[j+1];
                AnagramGroup[j+1]=temp;
            }
        }
    }
}

void CalculateTopFiveGroups()
//This function calculates the five largest anagram groups and reorders the array anagramgroupsizes accordingly
//Input: no input
//Output: no return value
{
    char match1[21], match2[21];    //arrays for when two anagram groups have same number of words
    int temp;                       //used as placeholder for swapping
    int j;                          //used in loops and as indexes for arrays
    for(int c=1; c<anagramgroupcount+1; c++)
        sortedgroupid[c]=c;                     //populates sortedgroupid with consecutive numbers c (reordered after)
    
    for(int i=0; i<anagramgroupcount; i++)
    {
        for (j=1; j<anagramgroupcount+1-i; j++)
        {
            if (anagramgroupsizes[j]<anagramgroupsizes[j+1])
            {
                //sorts the order of the anagram group sizes
                temp=anagramgroupsizes[j];
                anagramgroupsizes[j]=anagramgroupsizes[j+1];
                anagramgroupsizes[j+1]=temp;
                
                //sorts order of group id
                temp=sortedgroupid[j];
                sortedgroupid[j]=sortedgroupid[j+1];
                sortedgroupid[j+1]=temp;
            }
            
            //if two group sizes are equal, look for alphabetical order:
            if(anagramgroupsizes[j]==anagramgroupsizes[j+1])
            {
                for(int k=0; k<wordcount; k++)
                    if(AnagramGroup[k]==sortedgroupid[j])       //check group id
                    {
                        strcpy(match1,WordList[k]);             //copies word to match1 to be compared after
                        break;
                    }
                for(int k=0;k<wordcount;k++)
                    if(AnagramGroup[k]==sortedgroupid[j+1])     //check group id
                    {
                        strcpy(match2,WordList[k]);             //copies word to match2 to be compared after
                        break;
                    }
                
                //compare the matches and swap if first is larger than second
                if(strcmp(match1,match2)>0)
                {
                    //swaps groupsizes
                    temp=anagramgroupsizes[j];
                    anagramgroupsizes[j]=anagramgroupsizes[j+1];
                    anagramgroupsizes[j+1]=temp;
                    
                    //swaps group ids
                    temp=sortedgroupid[j];
                    sortedgroupid[j]=sortedgroupid[j+1];
                    sortedgroupid[j+1]=temp;
                }
            }
            
        }
    }
}
