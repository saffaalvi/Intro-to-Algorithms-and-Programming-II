//Assignment 4
//Loads event data from file (mylist.txt), arranges the events in chronological order, and saves the new order into mylist.txt, overwriting the contents of the file
//Clears the existing list at the end (frees the memory space of each node)

//LIBRARY HEADERS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//structure definition of an event aggregate data type used when scheduling the events
struct event
{
    int hour; // int variable for the hour between 0 and 23 inclusive
    int minute; // int variable for the minute between 0 and 59 inclusive/Users/saffaalvi/Desktop/assign5.c
    char description[41]; // a valid string describing the event (up to 40 usable characters)
    struct event* ptrNext; //self-referential pointer to next node
};typedef struct event Event;   //alias for struct event

//FUNCTION PROTOTYPES
Event *createEvent();
Event *InsertionSort(Event* ptrNew);
void loadEvents(char *filename);
void saveEvents(char *filename);
void clearList();

Event* ptrFirst = NULL;     //points to first element of list, initially NULL indicating it's an empty list
Event* ptrLast = NULL;      //points to last element of list, initially NULL indicating it's an empty list

//MAIN FUNCTION
int main()
{
    loadEvents("mylist.txt");       //calls loadEvents to load data from file
    saveEvents("mylist.txt");       //calls saveEvents to save new data to file
    clearList();                    //clears existing list
    return 0;
}

//FUNCTION DEFINITIONS

Event *createEvent()
//This function creates a new Event using malloc (allocating the memory for the new Event). It then returns a pointer to the new Event or NULL.
//Input: no input
//Output: returns ptrNew (pointer to new event) or NULL if no more memory is available
{
    Event *ptrNew = (Event*) malloc(sizeof(Event));
    return ptrNew;
}

Event *InsertionSort(Event* ptrNew)
//This function adds the new event and adds it to the linked list in order (sorting its contents by time in chronological order) and returns the pointer to the new event (ptrNew)
//Input: ptrNew, pointer to new event of type Event
//Output: no return value
{
    int first, second, next;    //first Event's time, second Event's time, and next will be used for time of next Event in list
    int check=0;                //checks if element should be added to the front of the list (0 if yes, 1 if no)

    //case 1: adding to an empty list
    if (ptrFirst == NULL)
    {
        ptrFirst = ptrNew;
        ptrLast = ptrNew;
    }
    else
    {
        first = (ptrNew->hour)*60 + (ptrNew->minute);       //total time in minutes (used to compare)
        Event* ptrCurr = ptrFirst;                          //pointer of type Event to ptrFirst
        second = (ptrCurr->hour)*60 + (ptrCurr->minute);    //total time in minutes (used to compare)
        while(first>second)     //loop will continue while first time is larger than the second time
        {
            next = (ptrCurr->ptrNext->hour)*60 + (ptrCurr->ptrNext->minute);  //total minutes of next event in list
            check=1;        //don't add to front
            if(next>first || ptrCurr->ptrNext == NULL)  //time of next element is greater, break the loop
                break;
            if(next==first && strcmp(ptrCurr->ptrNext->description,ptrNew->description)>0) //if time is same but next description is bigger than first, break loop
                break;
            ptrCurr = ptrCurr->ptrNext;                 //points to element after where ptrNew is supposed to be added
            second = (ptrCurr->hour)*60 + (ptrCurr->minute);    //time of second changes to next element's time
            if(ptrCurr->ptrNext == NULL)   //breaks loop when there aren't any more elements after current
                break;
        }
        if(check==0)    //add to front of list
        {
            //if events are not the same, add to list (removes repeat events from the list)
            if((first == second && strcmp(ptrCurr->description,ptrNew->description)!=0) || first!=second)
            {
                ptrNew->ptrNext=ptrFirst;
                ptrFirst = ptrNew;
            }
            
        }
        else        //don't need to add to the front of the list (add somewhere in the middle)
        {
            ptrNew->ptrNext = ptrCurr->ptrNext;   //add ptrNew in front of prtCurrent
            ptrCurr->ptrNext = ptrNew;
            if(ptrCurr==ptrLast)        //means ptrNew was added to the end of the list
                ptrLast=ptrNew;
        }
    }
    return ptrNew;
}

void loadEvents(char *filename)
//This function loads the information from a file (specified in main function) and stores each line in the file as an Event into a linked list
//Input: file name for where information is coming from
//Output: no return value

{
    FILE *file = fopen(filename, "r");  //opens file to be read with filename specified in main
    Event *ptrNew = NULL;
    
    if (file==NULL)             //error opening file (prints error message)
        printf("Error!");
    else
    {
        while(!feof(file))      //loop continues until end of file
        {
            ptrNew = createEvent();
            fscanf(file, "%d %d %s", &ptrNew->hour, &ptrNew->minute, ptrNew->description);  //scans contents of the file, adding them to contents of ptrNew (linked list)
            ptrNew->ptrNext = NULL;
            InsertionSort(ptrNew);      //calls InsertionSort to add to list in order
        }
    }
}

void saveEvents(char *filename)
//This function overwrites the file contents with the newly sorted list of Events
//Input: file name of file to be overwritten with contents of the list
//Output: no return value
{
    FILE *file = fopen(filename, "w");   //opens file to be written in with filename specified in main
    Event* ptrCurrent = NULL;
    
    if (file==NULL)             //error opening file (prints error message)
        printf("Error!");
    else
    {
        ptrCurrent = ptrFirst;
        while(ptrCurrent != NULL)   //loop to keep writing into file until ptrCurrent is NULL
        {
            fprintf(file, "%d %d %s\n", ptrCurrent->hour, ptrCurrent->minute, ptrCurrent->description);
            ptrCurrent = ptrCurrent->ptrNext;
        }
        
        fclose(file);   //closes the file
    }

}
void clearList()
//This function frees the memory space of each node using free()
//Input: no input
//Ouput: no output
{
    Event* ptrDelete = NULL;    //ptrDelete is set to point to node to be deleted (ptrFirst)
    
    while (ptrFirst != NULL)
    {
        ptrDelete = ptrFirst;   //ptrDelete is set ptrFirst (node to be deleted)
        ptrFirst = ptrFirst->ptrNext;   //updating ptrFirst (beginning of list) to point to ptrNext
        free(ptrDelete);        //node is erased
    }
    ptrLast = NULL;
}

