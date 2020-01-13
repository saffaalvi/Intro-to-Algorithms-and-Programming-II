//loads employee information (firstname, lastname, id) from employee.dat file, capitalizes the first letters of first and last name,
//and saves the capitalized names and ID into the file (overwrites employee.dat)

//library headers
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct employee
{
    char firstname[40];         //firstname of employee up to 39 usable characters
    char lastname[40];          //lastname of employee up to 39 usable characters
    int id;                     //integer id of employee
};typedef struct employee Employee;

//function prototypes
void LoadEmployeeInfo(Employee e[], const char *FileName);
void WordCap(char *string);
void SaveEmployeeRecords(Employee e[], const char *FileName);

//mian function
int main()
{
    Employee empArray[3];         //array for employee information
    LoadEmployeeInfo(empArray, "employee.dat");       //loads employee information from file employee.dat
    SaveEmployeeRecords(empArray, "employee.dat");    //saves new employee information to employee.dat
    return 0;
}

//function definitions
void LoadEmployeeInfo(Employee e[], const char *FileName)
//This function loads the employee information from the file employee.dat and enters it into the array
//Input: array of type Employee and filename that information is read from
//Output: no return value

{
    FILE *file = fopen(FileName, "r");  //file=FileName (employee.dat) file pointer and fopen opens the file for reading ("r")
    char junk[3][10];                   //first line in employee.dat file is ID FIRSTNAME LASTNAME which isn't employee info so junk array is to store those characters
    if (file == NULL)               //error message
        printf("File not opened");
    else
    {
        for (int i = 0; i <= 3; i++)        //loop to go through employee information in file and add it to array
        {
            if (i==0)                       //first line are headers which are junk
                for (int j=0; j<3; j++)
                    fscanf(file, "%s", junk[i]);
            else
                fscanf(file, "%d %s %s", &e[i].id, e[i].firstname, e[i].lastname);  //scan employee info and add to array
        }
        fclose(file);       //close the file
    }
}

void SaveEmployeeRecords(Employee e[], const char *FileName)
//This function saves the new employee information into the file employee.dat
//Input: array of type Employee and filename information is saved in (employee.dat)
//Output: no return value
{
    FILE *file = fopen(FileName, "w");  //file=employee.dat file pointer and fopen opens the file to write in ("w")
    if (file == NULL)                   //error message
        printf("File not opened.");
    else
    {
        fprintf(file, "ID FIRSTNAME LASTNAME\n");   //headers outputted into file
        for (int i=1; i<=3; i++)                    //loop to go through employee information
        {
                WordCap(e[i].firstname);            //calls function WordCap to capitalize first letter of firstname
                WordCap(e[i].lastname);             //calls function WordCap to capitalize first letter of lastname
                fprintf(file, "%d %s %s", e[i].id, e[i].firstname, e[i].lastname);      //outputs data to file
                fprintf(file, "\n");                //outputs newline to file
        }
        fclose(file);           //closes the file
    }
}

void WordCap(char *string)
//This function capitalizes the first letter of the string inputted into it
//Input: pointer to string that needs to be capitalized
//Output: no return value
{
    string[0] = toupper(string[0]);         //calls c library function toupper to capitalize the first letter of the string
}
