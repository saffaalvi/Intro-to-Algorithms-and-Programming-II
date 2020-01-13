//Assignment 3
//Allows user to create an event list, which they can modify by scheduling an event or deleting an event
//they can also load an event list (replacing the current list), display the event list, and/or save the list

//LIBRARY HEADERS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 5       //max number of elements in list

//structure definition of an event aggregate data type used when scheduling the events
struct event
{
    int hour; // int variable for the hour between 0 and 23 inclusive
    int minute; // int variable for the minute between 0 and 59 inclusive
    char description[41]; // a valid string describing the event
};typedef struct event Event;   //alias for struct event

//BASE FUNCTION PROTOTYPES
int InputRange(int min, int max);
Event* InputEvent(Event *newEvent);
int AddEventAtIndex(Event list[], Event e, int i);
int InsertionSortEvent(Event list[], int *p_size, Event e);
void DisplayEvent(Event e);
void DisplayEventList(Event list[], int size);
int DeleteEvent(Event list[], int i, int *p_size);
//BONUS FUNCTION PROTOTYPES
int SaveEventList(char *filename,Event list[],int size);
int LoadEventList(char *filename,Event list[],int *p_size);
char* encode(char*s);
char* decode(char*s);

//MAIN FUNCTION
int main()
{
    Event EventList[MAX];   //array of type Event to store the list of events
    int eventListSize=0;    //number of events stores in EventList array
    int input = 0;          //number user enters from menu
    Event tempEvent;        //tempEvent of type Event used in function InputEvent when user enters information of an event
    do{     //do...while loop to ensure program menu keeps being displayed until user enters 6 to exit
        printf("__= Scheduler v1.0 =__\n");     //displaying menu
        printf("  1. Schedule an event.\n  2. Delete an event.\n  3. Display schedule.\n");
        printf("  4. Save schedule.\n  5. Load schedule.\n  6. Exit.\n");
        input = InputRange(1,6);    //calls function InputRange with minimum and maximum numbers of menu to ensure user enters a valid number
        switch (input){          //switch cases to appropriately respond to each menu number selected by user
            case 1:      //User chooses to schedule an event
            {
                if (eventListSize<MAX)      //eventListSize must be less than MAX (5) to add more events
                    InsertionSortEvent(EventList, &eventListSize, *InputEvent(&tempEvent));
                else            //if MAX has been reached, no new event will be added, instead message is displayed
                    printf("The maximum number of events you can add to the schedule has been reached!\nWe apologize for any inconvenience this may cause.\n");
                break;
            }
            case 2:     //User chooses to delete an event
            {
                if (eventListSize==0)       //if eventListSize is 0, there are no events to delete
                    printf("You need to have an event to delete first...\n");
                else
                {
                    DisplayEventList(EventList, eventListSize);     //calls function DisplayEventList to display events in EventList
                    printf("Which event would you like to delete or -1 to cancel?\n");
                    int delNum = InputRange(-1, eventListSize-1);      //ensures event user chooses to delete is in range
                    if (delNum!=-1)            //user doesn't want to cancel, so delete the event
                        DeleteEvent(EventList, delNum, &eventListSize);        //calls function DeleteEvent to delete the selected event
                }
                break;
            }
            case 3:     //User chooses to display schedule
            {
                if(eventListSize==0)     //if eventListSize is 0, there are no events to display
                    printf("You need to have an event to display first...\n");
                else
                {
                    DisplayEventList(EventList, eventListSize); //calls function DisplayEventList to display events in EventList
                }
                break;
            }
            //bonus functions:
            case 4:     //User chooses to save schedule
            {
                char file[41];          //file name to save as (chose as max of 40 characters)
                printf("File name: ");
                scanf("%40s", file);
                int saved = SaveEventList(file, EventList, eventListSize);      //calls function SaveEventList to save the list in file with name user entered, returning number of events saved
                printf("%d events saved into schedule file named %s", saved, file);
                break;
            }
            case 5:    //User chooses to load schedule
            {
                char file2[41];     //file name to load from (chose as max of 40 characters)
                printf("This action will replace the current schedule.\n");
                printf("File name (or ""abort"" to cancel operation: ");
                scanf("%40s", file2);
                if (strcmp(file2, "abort")!=0)          //if user enters "abort", file will not be loaded
                {
                    int loaded = LoadEventList(file2, EventList, &eventListSize);        //calls function Load EventList to load the file user entered into EventList array
                    printf("%d events loaded into schedule file named %s", loaded, file2);
                }
                break;
            }
            case 6: printf("Goodbye..."); break;        //exit the program
                
        }
    }while(input!=6);
    return 0;
}

//BASE FUNCTION DEFINITIONS
int InputRange(int min, int max)
//This function prompts the user infinitely until an integer in the range min and max (inclusive) is entered
//Input: parameters - integer minimum and maximum number in range, also gets integer input from user
//Output: returns valid integer entered by the user
{
    int num = 0;        //integer number user enters
    while(1)            //loop keeps going until valid integer is entered
    {
        printf("Please enter an integer between %d and %d: ", min, max);
        scanf("%d", &num);
        if (num>=min && num<=max)   //if number is in range, loop is broken
            break;
        printf("Invalid input!\n");
    }
    return num;         //returns valid integer number entered by user
}
Event* InputEvent(Event *newEvent)
//This function asks the user for the hour, minute, and description of the event, ensuring the hour and minute are in range by using InputRange().
//Input: pointer for the event that needs to be filled with the values entered bu the user
//Output: returns pointer for that same event
{
    if (newEvent!=NULL)     //ensure pointer isn't null
    {
        printf("Enter the event time:\n");
        newEvent->hour = InputRange(0,23);      //stores valid integer hour entered by user into address for that event
        newEvent->minute = InputRange(0,59);    //store valid integer minute entered by user into address for that event
        printf("Enter the event description: ");
        getchar();                              //gets a character from stdin
        scanf("%[^\n]s", newEvent->description);    //stores the sting entered into description for that event, ignoring whitespaces
    }
    return newEvent;        //returns pointer for event
}

int AddEventAtIndex(Event list[], Event e, int i)
//This function takes the Event type character array list, the event e that has already been filled in by the user, and the index of where event is to be stored into the array, and sets the location at i with the information of the new event
//Input: array of type Event, populate event (e) of type Event, integer index i where event is to be stored
//Output: returns the integer index i
{
    list[i].hour = e.hour;          //sets the hour in the index i in list with the hour of the event e
    list[i].minute = e.minute;      //sets the minute in the index i in list with the minute of the event e
    strcpy(list[i].description, e.description);     //copies the description from the event e into the description in the location i of list
    return i;        //returns integer index i
}

int InsertionSortEvent(Event list[], int *p_size, Event e)
//This function sorts the events in the array of type Event (list) in ascending order of time by using AddEventAtIndex
//Input: array of type Event (EventList), integer pointer to size of EventList (passed by reference *p_size), and event (e) of type Event that's ready to be added to the list
//Output: returns index of where the event (e) was added in the list
{
    int i = *p_size-1;                        //index of where event is added into list (initialized to size of EventList - 1)
    int first = (e.hour)*60 + e.minute;      //total time in minutes of the event (used to compare to event already in list[i])
    int second = (list[i].hour)*60 + list[i].minute;    //total time in minutes of the element in index of list (used to compare to event e)
    for (;i>=0 && first<second; i--)                    //loop sees if event time is less than the event time in list so it can add the event accordingly
    {
        second = (list[i].hour)*60 + list[i].minute;
        AddEventAtIndex(list, list[i], i+1);    //inserts event in list[i] to the list at proper index
    }
    AddEventAtIndex(list, e, i+1);              //inserts event e to list at proper index
    (*p_size)++;                //increments size of list
    return i+1;                 //returns index of where event was added
    
}

void DisplayEvent(Event e)
//This function displays the event e in proper format of hh:mm description
//Input: event e of type Event
//Output: no return value, displays event information
{
    printf("%02d:%02d %s\n", e.hour, e.minute, e.description);
}

void DisplayEventList(Event list[], int size)
//This function displays the contents of EventList with the index number in which the events are stored in the array by using DisplayEvent
//Input: array of type Event (EventList), and size of array
//Output: no return value, displays contents of EventList
{
    for (int i=0; i<size; i++)          //loop to go through each element of array
    {
        printf("[%d] ", i);             //prints index number
        DisplayEvent(list[i]);          //displays each event information
    }
}

int DeleteEvent(Event list[], int i, int *p_size)
//This function deletes all the information of an event from the character array list of type Event (EventList) at an index given by the user, updating the size of the list as well.
//Input: array of type Event (EventList), index of event to be deleted, and pointer to size of array
//Output: returns integer index if the event is successfully deleted, or returns -1 if unsuccessful (if the index (i) is not valid or list is empty)
{
    if (i>=0 || i<*p_size)          //ensures index is valid
    {
        for (;i<*p_size; i++)
            list[i] = list[i+1];   //event at index entered is removed and rest of elements of are shifted
        (*p_size)--;       //size of list is reduced
        return i;          //index i is returned indicating successful deletion of event
    }
    else
        return -1;      //deletion was not successful, returns -1
}

//BONUS FUNCTION DEFINITIONS
int SaveEventList(char *filename, Event list[], int size)
//This function saves all the contents of array of type Event (EventList) to a file with the name specified by the user, returning the number of events saved or -1 if it fails. Uses the function encode to remove all the spaces from the description before saving and replacing them with underscores.
//Input: pointer to name of file provided by user, array of type Event (EventList), and size of array
//Output: integer number of records saved if successful, or -1 if failed
{
    FILE *file = fopen(filename, "w");          //opens file to be written into with file name provided by user
    if (file == NULL)                          //failure to open file
        return -1;
    else
    {
        for (int i=0; i<size; i++)
        {
            encode(list[i].description);    //calls function encode to replace all spaces with underscores
            fprintf(file, "%d %d %s\n", list[i].hour, list[i].minute, list[i].description);   //inputs all the contents of the list into the file
        }
        fclose(file);           //closes the file
    }
    return size;            //returns size/number of records saved
}

int LoadEventList(char *filename, Event list[], int *p_size)
//This function loads the contents of a file entered by the user and overwrites the array of type Event (EventList) with the contents of the file. It also updates the size of the array to the number of events in the file. Uses the function decode to remove all the underscores from the description before saving and replacing them with spaces (back to original form)
//Input: file name of the file information is to be loaded from (provided by user), array of type Event (EventList) whose contents will be overwritten, and size of array that is updated to size of events in file
//Output: integer number of events if successful or -1 if unsuccessful
{
    int i=0;            //index of event
    FILE *file = fopen(filename, "r");  //opens file to be read with filename specified by user
    if (file==NULL)     //failure to open file
        return -1;
    else
    {
        while(!feof(file))      //loop continues until end of file
        {
            fscanf(file, "%d %d %s", &list[i].hour, &list[i].minute,list[i].description);   //scans the contents of the file and adds them to the index of the list
            decode(list[i].description);        //uses the function decode to replace underscores to spaces to revert back to original form
            i++;        //increments the index to add to each element of list
        }
        fclose(file);       //closes the file
    }
    *p_size = i;            //updates size of array
    DeleteEvent(list,i,p_size); //new line causes an extra index to be added so delete the last index and update the size by calling function DeleteEvent
    return *p_size;         //returns new size of array
    
}

char* encode(char* s)
//This function replaces all the spaces in a string with underscores
//Input: pointer to string
//Output: returns the string
{
    while(*s!='\0')     //loop continues until null character of string is reached
    {
        if (*s==' ')    //if the value of the string pointer is space
            *s='_';     //set to underscore
        s++;            //increments index of string
    }
    return s;           //returns string
}

char* decode(char*s)
//This function replaces all the underscores in a string with spaces
//Input: pointer to string
//Output: returns the string
{
    while(*s!='\0')     //loop continues until null character of string is reached
    {
        if (*s=='_')    //if the value of the string pointer is underscore
            *s=' ';     //set to space
        s++;
    }
    return s;           //returns string
}

