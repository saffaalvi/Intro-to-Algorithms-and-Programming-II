//allows user to input employee record (firstname, lastname, id) and saves into file employee.dat.
//also allows user to retrieve employee information

//library headers
#include<stdio.h>
#include<stdlib.h>

struct employee
{
    char firstname[40];         //firstname of employee up to 39 usable characters
    char lastname[40];          //lastname of employee up to 39 usable characters
    int id;                     //integer id of employee
};typedef struct employee Employee;

//function prototypes
void InputEmployeeRecord(Employee *ptrEmp);
void PrintEmployeeRecord(const Employee e);
void SaveEmployeeRecord(const Employee e[], const char *FileName);

//main function
int main()
{
    
    Employee empArray[3];       //array for employee information
    int empnum;
    for (int i=0; i<3; i++)
        InputEmployeeRecord(&empArray[i]);  //input 3 employee records
    printf("Enter employee number's record you want to retrieve (1, 2, or 3): ");       //asks user which employee record they want to retrieve
    scanf("%d", &empnum);
    do{
        printf("Number has to be 1, 2, or 3! Try again: ");
        scanf("%d", &empnum);
    }while(empnum<1 || empnum>3);
    PrintEmployeeRecord(empArray[empnum-1]);    //prints information of a given employee
    SaveEmployeeRecord(empArray, "employee.dat");   //saves the employee records into file employee.dat
    
}

//function definitions
void InputEmployeeRecord(Employee *ptrEmp)
//This function inputs the employee data interactively from the keyboard
//Input: parameter - pointer ptrEmp, user will input employee ID, firstname, and lastname which will be saved to the right location
//Output: no return value
{
        printf("Enter Employee Details: \n");
        scanf("%d %s %s", &ptrEmp->id, ptrEmp->firstname, ptrEmp->lastname);
}

void PrintEmployeeRecord(const Employee e)
//This function displays the contents of a given employee record
//Input: record of given employee to be printed
//Output: no return value, prints the employee information
{
    printf("%d %s %s\n", e.id, e.firstname, e.lastname);
}

void SaveEmployeeRecord(const Employee e[], const char *FileName)
//This function saves the contents of the employee record list to the newly created text file specified by FileName
//Input: array e of type employee, file name information is to be saved in
//Ouput: no return value, information in array will be saved to file or user will be told file could not be opened (if error occurs)
{
    FILE *file = fopen (FileName, "w");       //file=FileName (employee.dat) file pointer and fopen opens the file for writing ("w")
    if (file == NULL)                         //error message
    {
        printf("File could not be opened");
    }
    else
    {
        fprintf(file, "ID FIRSTNAME LASTNAME\n");       //outputs headers into file
        for(int i = 0; i<3; i++)                        //loop to go through each element of the array (employee information)
        {
            fprintf(file, "%d %s %s", e[i].id, e[i].firstname, e[i].lastname);      //outputs id, firstname, and lastname into file
            fprintf(file, "\n");        //outputs newline to file
        }
    fclose(file);           //closes file
    }
}

