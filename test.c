/*
CO253 Mini Project: COVID PATIENT MANAGEMENT SYSTEM
Author: LAKSARA L. G. R.
Registration No: E/18/189

--CAUTION--
Please close the terminal before compiling the program. otherwise it may cause some errors in compiling since the program included <windows.h> header file.
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
    char gender;
    char AdmissionDate[15];
} patient;

//Funtion to move cursor around the terminal
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//Function to get user's input and return it
int getCommand()
{
    int command;
    scanf("%d", &command);
    return command;
}

//Funtion to print default commands
void printFunc()
{
    printf("\n\n---------------------------------------------------------\n");
    printf("COVID-19 PATIENT MANAGEMENT SYSTEM\n");
    printf("---------------------------------------------------------\n");
    printf("0. Quit\n1. Add a Patient Record\n2. Print a Patient Record\n3. Print all Patient Record\n4. Delete a Patient Record\n5. Sort records by name alphabetically\n");
    printf("---------------------------------------------------------\n");
    printf("ENTER OPTION [0-4]\n");
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

    for (int i = 0; i < PatientCount; i++)
    {
        if (strcmp(patients[i].nic, nic) == 0)
        {
            found = 1;
            printf("\nName: %s\t|\tNIC: %s\t|\tAge: %d\t|\tGender: %c", patients[i].name, patients[i].nic, patients[i].age, patients[i].gender);
            break;
        }
    }

    if (found == 0)
    {
        system("cls");
        printf("Sorry, There is no record for the NIC number - %s", nic);
    }
}

//Function to search patients within the patient array by NIC number and edit the corresponding record
void editPatient(patient *patients, int PatientCount)
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
            printf("\nName: %s\t|\tNIC: %s\t|\tAge: %d\t|\tGender: %c", patients[i].name, patients[i].nic, patients[i].age, patients[i].gender);
            printf("\n\nDo you need to edit this patients info? (Y/N");
            char response;
            scanf(" %c", &response);
            if (response == 78 || response == 110)
            {
                break;
            }
            else
            {
                continue;
            }
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
            for (int j = i; j < noPatients; j++)
            {
                patients[j] = patients[j + 1];
                noPatients--;
            }
            printf("Record of the patient %s deleted succesfully", patients[i].nic);
            break;
        }
    }

    if (found == 0)
    {
        system("cls");
        printf("Sorry, There is no record for the NIC number - %d", nic);
    }
}

//Function for printing all the records in the patients array
void parintAllPatients(patient *patients, int PatientCount)
{
    int nic, MaxNameLength, found = 0;
    MaxNameLength = longestName(patients, PatientCount);
    gotoxy(5 + (int)((MaxNameLength + 19) / 2), 4);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ALL PATIENTS RECORD \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(5, 6);
    for (int i = 0; i < MaxNameLength + 64; i++)
    {
        printf("=");
    }

    gotoxy(5, 7);
    printf("Name"); //TABLE TITLES !
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

    for (int i = 0; i < PatientCount; i++)
    {
        gotoxy(5, 10 + i);
        printf("%s", patients[i].name);
        gotoxy(5 + MaxNameLength + 5, 10 + i);
        printf("%s", patients[i].nic);
        gotoxy(5 + MaxNameLength + 5 + 12 + 5, 10 + i);
        printf("%c", patients[i].gender);
        gotoxy(5 + MaxNameLength + 5 + 12 + 5 + 8 + 5, 10 + i);
        printf("%d Years", patients[i].age);
        gotoxy(5 + MaxNameLength + 5 + 12 + 5 + 8 + 5 + 9 + 5, 10 + i);
        printf("%s", patients[i].AdmissionDate);
    }
}

patient addPatient()
{

    patient new; //Creating new object and returning it
    int temp;

    printf("---------------------------------------------------------\n");
    printf("ADMITTING NEW PATIENT\n");
    printf("---------------------------------------------------------\n");
    scanf("%c", &temp); //Temp variable to skip new line of previous line
    printf("Enter Name (Max Characters = 50): ");
    scanf("%[^\n]", &new.name);
    scanf("%c", &temp);
    printf("Enter NIC Number [Example: 991312154V/19991312154]: ");
    scanf("%[^\n]", &new.nic);
    printf("Enter Gender [M/F]: ");
    scanf(" %c", &new.gender);
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
    int command, quit = 0, PatientCount = 0;

    while (quit == 0)
    {
        printFunc();
        command = getCommand();
        switch (command)
        {
        case 1:
            while (quit == 0)
            {
                system("cls");
                patients = (patient *)realloc(patients, (PatientCount + 1) * sizeof(patient)); //Everytime adding a new patient allocated memory increased using realloc
                patients[PatientCount] = addPatient();
                PatientCount++;
                printf("\n\n\nDo you want to add more patients? (Y/N): ");
                char response;
                scanf(" %c", &response);
                if (response == 78 || response == 110)

                {
                    break;
                }
                else
                {
                    continue;
                }
            }
            break;
        case 2:
            while (quit == 0)
            {
                system("cls");
                findPatient(patients, PatientCount);
                printf("\n\nDo you want to find another patients (Y/N): ");
                char response;
                scanf(" %c", &response);
                if (response == 78 || response == 110)

                {
                    break;
                }
                else
                {
                    continue;
                }
            }
            break;
        case 3:
            while (quit == 0)
            {
                system("cls");
                parintAllPatients(patients, PatientCount);
                printf("\n\n\n\nPress any key to return to main menu... ");
                getch();
                break;
            }
            break;
        case 4:
            system("cls");
            deletePatient(patients, &PatientCount);
            PatientCount--;
            patients = (patient *)realloc(patients, (PatientCount) * sizeof(patient));
            break;
        case 0:
            free(patients);
            exit(0);
            break;
        case 5:
            system("cls");
            sortArrayName(patients, PatientCount);
            printf("Records ares sorted by name alphabetically");
            printf("\n\n\n\nPress any key to return to main menu... ");
            getch();
            break;

        default:
            command = 1;
            system("cls");
            printf("!!Please input a correct command!!");
            printf("\n\nPress any key to continue... ");
            getch();
            break;
        }
        system("cls");
        command = 1;
    }
}
