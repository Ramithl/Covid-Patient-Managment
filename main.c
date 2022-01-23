/*
CO253 Mini Project: COVID PATIENT MANAGEMENT SYSTEM
Author: LAKSARA L. G. R.
Registration No: E/18/189


Remote Repository: https://github.com/Ramithl/Covid-Patient-Managment.git


!!CAUTION!!
Compile the program and execute it in the system terminal.
Since the program is using a function to move the cursor around the terminal,
There might be some errors in text editor terminals.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>

//Initializing Structure
typedef struct patient
{
    char nic[13];
    int age;
    char name[50];
    char gender[10];
    char AdmissionDate[15];
} patient;

/* ----- SUPPORT FUNCTIONS ----- */

//Funtion to move cursor around the terminal
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//Function to get user's input and return it
char *getCommand()
{
    char *command = (char *)malloc(sizeof(char) * 10); //Character array for the command

    scanf(" %[^\n]", command);
    return command;
}

//Funtion to print default commands
void printFunc()
{
    printf("\n\n---------------------------------------------------------\n");
    printf("COVID-19 PATIENT MANAGEMENT SYSTEM\n");
    printf("---------------------------------------------------------\n");
    printf("0. Quit\n1. Add a Patient Record\n2. Find a Patient Record\n3. Print all Patient Record\n4. Delete a Patient Record\n");
    printf("\nMORE COMMANDS");
    printf("\n5. Sort the records by name alphabetically\n6. Sort the records by admission date\n7. Edit a record\n");
    printf("---------------------------------------------------------\n");
    printf("ENTER OPTION [0-7]\n");
    printf("---------------------------------------------------------\n\n");
    printf("ENTER: ");
}

//Funtion to get the longest name of the patients list
int longestName(patient *patients, int PatientCount)
{
    int maxLength = 0, temp;
    for (int i = 0; i < PatientCount; i++)
    {
        temp = strlen(patients[i].name);
        if (temp > maxLength)
        {
            maxLength = temp;
        }
    }
    return maxLength;
}

//Function to print Male or Female depending on the input
void MaleOrFemale(char *gender)
{
    if (strcmp(gender, "M") == 0)
    {
        printf("Male");
    }
    else if (strcmp(gender, "F") == 0)
    {
        printf("Female");
    }
    else
    {
        printf("ERROR");
    }
}

/* ----- MAIN FUNCTIONS ----- */

void editRecords(patient *patients, int PatientCount)
{
    int found = 0;
    char nic[13], temp;

    printf("---------------------------------------------------------\n");
    printf("EDIT PATIENT'S RECORD\n");
    printf("---------------------------------------------------------\n\n");

    scanf("%c", &temp);
    printf("Enter the NIC number of the patient: ");
    scanf("%[^\n]", &nic);

    for (int i = 0; i < PatientCount; i++)
    {
        if (strcmp(patients[i].nic, nic) == 0)
        {
            found = 1;
            while (found = 1)
            {
                system("cls");
                printf("Here's the details of NIC number: %s\n\n", patients[i].nic);
                printf("1. Name: %s\n"
                       "2. NIC %s\n"
                       "3. Age: %d\n"
                       "4. Gender: %s\n"
                       "5. Admission date: %s\n\n",
                       patients[i].name, patients[i].nic, patients[i].age, patients[i].gender, patients[i].AdmissionDate);
                int command, temp;
                printf("Choose what to update [1-5]: ");
                scanf("%d", &command);
                switch (command)
                {
                case 1:
                    scanf("%c", &temp);
                    printf("\n\nEnter the new name : ");
                    scanf("%[^\n]", &patients[i].name);
                    break;
                case 2:
                    scanf("%c", &temp);
                    printf("\n\nEnter the new NIC [Example: 991312154V/19991312154]: ");
                    scanf("%[^\n]", &patients[i].nic);
                    break;
                case 3:
                    printf("\n\nEnter the new age [Example: 22]: ");
                    scanf("%d", &patients[i].age);
                    break;
                case 4:
                    printf("\n\nEnter the new gender [M/F]: ");
                    scanf("%s", &patients[i].gender);
                    break;
                case 5:
                    scanf("%c", &temp);
                    printf("\n\nEnter the new admission date [Example: 2022/01/01]: ");
                    scanf("%[^\n]", &patients[i].AdmissionDate);
                    break;
                default:
                    break;
                }
                printf("\n\n---------------------------------------------------------\n");
                printf("RECORD UPDATED SUCCESSFULLY!\n");
                printf("---------------------------------------------------------\n\n");

                printf("\n\nDo you want to edit another detail of this patient? [Y/N]: ");
                char response;
                scanf(" %c", &response); //Taking the confirmation input

                if (response == 89 || response == 121) //Checking if the input is 'Y' or 'y'
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
            break;
        }
    }

    if (found == 0)
    {
        system("cls");
        printf("Sorry, There is no record for the NIC number - %s", &nic);
    }
}

//Funtion to sort array alphabetically
void sortArrayName(patient *patients, int PatientCount)
{
    patient temp;

    //Sort array using the Buuble Sort algorithm
    for (int i = 0; i < PatientCount; i++)
    {
        for (int j = 0; j < PatientCount - 1 - i; j++)
        {
            if (strcmp(patients[j].name, patients[j + 1].name) > 0)
            {
                //swap patients[j] and patients[j+1]
                temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }
}

//Funtion to sort array by date of admission
void sortArrayDate(patient *patients, int PatientCount)
{
    patient temp;

    //Sort array using the Buuble Sort algorithm
    for (int i = 0; i < PatientCount; i++)
    {
        for (int j = 0; j < PatientCount - 1 - i; j++)
        {
            if (strcmp(patients[j].AdmissionDate, patients[j + 1].AdmissionDate) > 0)
            {
                //swap patients[j] and patients[j+1]
                temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }
}

//Function to search patients within the patient array by NIC number
void findPatient(patient *patients, int PatientCount)
{
    int found = 0;
    char nic[13], temp;

    printf("---------------------------------------------------------\n");
    printf("FINDING PATIENT'S RECORD\n");
    printf("---------------------------------------------------------\n\n");

    scanf("%c", &temp);
    printf("Enter the NIC number of the patient: ");
    scanf("%[^\n]", &nic);

    //Loop through the array
    for (int i = 0; i < PatientCount; i++)
    {
        if (strcmp(patients[i].nic, nic) == 0) //Comparing 2 strings
        {
            found = 1;
            printf("\nName:  %s", patients[i].name);
            printf("\nNIC:  %s", patients[i].nic);
            printf("\nAge:  %d years", patients[i].age);
            printf("\nGender:  %s", patients[i].gender);
            printf("\nAdmission Date:  %s", patients[i].AdmissionDate);
            break;
        }
    }

    if (found == 0)
    {
        system("cls");
        printf("Sorry, There is no record for the NIC number - %s", nic);
    }
}

//Funtion to delete a record of a patient
void deletePatient(patient *patients, int *PatientCount)
{
    int found = 0;
    int noPatients = *PatientCount;
    char nic[13], temp;

    printf("---------------------------------------------------------\n");
    printf("DELETE A PATIENT RECORD\n");
    printf("---------------------------------------------------------\n\n");

    scanf("%c", &temp);
    printf("Enter the NIC number of the patient: ");
    scanf("%[^\n]", &nic);

    for (int i = 0; i < noPatients; i++)
    {
        if (strcmp(patients[i].nic, nic) == 0)
        {
            found = 1;

            //Deleting the element by moving the elemnts by one index to the left
            for (int j = i; j < noPatients; j++)
            {
                patients[j] = patients[j + 1];
                noPatients--;
            }
            printf("\nRecord of the patient %s deleted succesfully", nic);
            break;
        }
    }

    if (found == 0)
    {
        system("cls");
        printf("Sorry, There is no record for the NIC number - %s", nic);
    }
}

//Function for printing all the records in the patients array
void parintAllPatients(patient *patients, int PatientCount)
{
    int nic, MaxNameLength, found = 0;
    MaxNameLength = longestName(patients, PatientCount); //Getting the longest name within the record to align the table according to it
    gotoxy(5 + (int)((MaxNameLength + 19) / 2), 4);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ALL PATIENTS RECORD \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(5, 6);
    for (int i = 0; i < MaxNameLength + 64; i++)
    {
        printf("=");
    }

    //Table Titles
    gotoxy(5, 7); //Moving cursor to the 5th row and 7th column
    printf("Name");
    gotoxy(5 + MaxNameLength + 5, 7);
    printf("NIC NO.");
    gotoxy(5 + MaxNameLength + 5 + 12 + 5, 7);
    printf("Gender");
    gotoxy(5 + MaxNameLength + 5 + 12 + 5 + 8 + 5, 7);
    printf("Age");
    gotoxy(5 + MaxNameLength + 5 + 12 + 5 + 8 + 5 + 9 + 5, 7);
    printf("Admission Date");
    gotoxy(5, 8);
    for (int i = 0; i < MaxNameLength + 64; i++)
    {
        printf("=");
    }

    //Table data
    for (int i = 0; i < PatientCount; i++)
    {
        gotoxy(5, 10 + i);
        printf("%s", patients[i].name);
        gotoxy(5 + MaxNameLength + 5, 10 + i);
        printf("%s", patients[i].nic);
        gotoxy(5 + MaxNameLength + 5 + 12 + 5, 10 + i);
        MaleOrFemale(patients[i].gender);
        gotoxy(5 + MaxNameLength + 5 + 12 + 5 + 8 + 5, 10 + i);
        printf("%d Years", patients[i].age);
        gotoxy(5 + MaxNameLength + 5 + 12 + 5 + 8 + 5 + 9 + 5, 10 + i);
        printf("%s", patients[i].AdmissionDate);
    }
}

//Funtion to add a record
patient addPatient()
{

    patient new; //Creating new object and returning it
    int temp;

    printf("---------------------------------------------------------\n");
    printf("ADMITTING NEW PATIENT\n");
    printf("---------------------------------------------------------\n");
    scanf("%c", &temp); //Temp variable to skip new line of previous line
    printf("Enter Name (Max Characters = 100): ");
    scanf("%[^\n]", &new.name);
    scanf("%c", &temp);
    printf("Enter NIC Number [Example: 991312154V/19991312154]: ");
    scanf("%[^\n]", &new.nic);
    printf("Enter Gender [M/F]: ");
    scanf(" %s", &new.gender);
    printf("Enter Age [Example: 22]: ");
    scanf("%d", &new.age);
    scanf("%c", &temp);
    printf("Enter Date of Admission [Example: 2022/01/01]: ");
    scanf("%[^\n]", &new.AdmissionDate);

    return new;
}

void main()
{
    patient *patients = (patient *)malloc(sizeof(patient)); //Initilizing patients structure array
    int quit = 0, PatientCount = 0;

    while (quit == 0) //All the functions are wrapped around this loop to work the program till user decide to exit
    {
        printFunc();
        char *command = getCommand();

        if (strcmp(command, "1") == 0)
        {
            while (quit == 0)
            {
                system("cls");
                patients = (patient *)realloc(patients, (PatientCount + 1) * sizeof(patient)); //Everytime adding a new patient allocated memory increased using realloc
                patients[PatientCount] = addPatient();
                PatientCount++;
                printf("\n\n\nDo you want to add more patients? (Y/N): ");
                char response;
                scanf(" %c", &response);
                if (response == 89 || response == 121)

                {
                    continue;
                }
                else
                {
                    break;
                }
            }
        }

        else if (strcmp(command, "2") == 0)
        {
            while (quit == 0)
            {
                system("cls");
                system("cls");
                findPatient(patients, PatientCount);
                printf("\n\nDo you want to find another patients (Y/N): ");
                char response;
                scanf(" %c", &response);
                if (response == 89 || response == 121)

                {
                    continue;
                }
                else
                {
                    break;
                }
            }
        }

        else if (strcmp(command, "3") == 0)
        {
            while (quit == 0)
            {
                system("cls");
                parintAllPatients(patients, PatientCount);
                printf("\n\n\n\nPress any key to return to main menu... ");
                getch();
                break;
            }
        }

        else if (strcmp(command, "4") == 0)
        {
            while (quit == 0)
            {
                system("cls");
                deletePatient(patients, &PatientCount);
                PatientCount--;
                patients = (patient *)realloc(patients, (PatientCount) * sizeof(patient)); //Reallocate the memory for the new array
                printf("\n\nDo you want to delete another record (Y/N): ");
                char response;
                scanf(" %c", &response);
                if (response == 89 || response == 121)

                {
                    continue;
                }
                else
                {
                    break;
                }
            }
        }

        else if (strcmp(command, "5") == 0)
        {
            system("cls");
            sortArrayName(patients, PatientCount);
            printf("Records ares sorted by name alphabetically");
            printf("\n\n\n\nPress any key to return to main menu... ");
            getch();
        }

        else if (strcmp(command, "6") == 0)
        {
            system("cls");
            sortArrayDate(patients, PatientCount);
            printf("Records are sorted by admission date");
            printf("\n\n\n\nPress any key to return to main menu... ");
            getch();
        }

        else if (strcmp(command, "7") == 0)
        {
            while (quit == 0)
            {
                system("cls");
                editRecords(patients, PatientCount);
                printf("\n\nDo you want to edit another record (Y/N): ");
                char response;
                scanf(" %c", &response);
                if (response == 89 || response == 121)

                {
                    continue;
                }
                else
                {
                    break;
                }
            }
        }

        else if (strcmp(command, "0") == 0)
        {
            system("cls");
            free(command);
            free(patients);
            exit(0);
        }

        else
        {
            system("cls");
            printf("!!Please input a correct command!!");
            printf("\n\nPress any key to continue... ");
            getch();
            free(command);
        }

        system("cls");
    }
}
