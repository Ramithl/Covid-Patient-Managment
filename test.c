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
    printf("0. Quit\n1. Add a Patient Record\n2. Print a Patient Record\n3. Print all Patient Record\n4. Delete a Patient Record\n");
    printf("---------------------------------------------------------\n");
    printf("ENTER OPTION [0-4]\n");
    printf("---------------------------------------------------------\n\n");
    printf("ENTER: ");
}

//Function to search patients within the patient array by NIC number
void findPatient(patient *patients, int PatientCount)
{

    printf("---------------------------------------------------------\n");
    printf("FINDING PATIENT\n");
    printf("---------------------------------------------------------\n\n");
    int found = 0;
    char nic[13], temp;
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

//Funtion to delete a record of a patient
void deletePatient(patient *patients, int PatientCount)
{
    printf("---------------------------------------------------------\n");
    printf("DELETE A PATIENT RECORD\n");
    printf("---------------------------------------------------------\n\n");
    int found = 0;
    char nic[13], temp;
    scanf("%c", &temp);
    printf("Enter the NIC number of the patient: ");
    scanf("%[^\n]", &nic);
    for (int i = 0; i < PatientCount; i++)
    {
        if (strcmp(patients[i].nic, nic) == 0)
        {
            found = 1;
            for (int j = i-1; j < PatientCount; j++)
            {
                patients[i] = patients[i + 1];
                PatientCount--;
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
    int nic, found = 0;
    gotoxy(26, 4);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ALL PATIENTS RECORD \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(5, 6);
    printf("==========================================================================================");

    gotoxy(5, 7);
    printf("Name\t\t    NIC No.\t      Gender\t\tAge \t\tAdmission Date\n"); //TABLE TITLES !

    gotoxy(5, 8);
    printf("==========================================================================================");

    for (int i = 0; i < PatientCount; i++)
    {
        
        gotoxy(5, 10+i);
        printf("%s", patients[i].name);
        gotoxy(28, 10+i);
        printf("%s", patients[i].nic);
        gotoxy(46, 10+i);
        printf("%c", patients[i].gender);
        gotoxy(64, 10+i);
        printf("%d", patients[i].age);
        gotoxy(80, 10+i);
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
    scanf("%c", &temp);
    printf("Enter Name: ");
    scanf("%[^\n]", &new.name);
    scanf("%c", &temp);
    printf("Enter NIC Number: ");
    scanf("%[^\n]", &new.nic);
    printf("Enter Gender: ");
    scanf(" %c", &new.gender);
    printf("Enter Age: ");
    scanf("%d", &new.age);
    scanf("%c", &temp);
    printf("Enter Date of Admission: ");
    scanf("%[^\n]", &new.AdmissionDate);

    return new;
}

void main()
{
    patient *patients = (patient *)malloc(sizeof(patient)); //Initilizing patients structure array
    int command, quit = 0, PatientCount = 0;
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 COVID PATIENTS MANAGMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

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
            deletePatient(patients, PatientCount);
            break;
        case 0:
            free(patients);
            exit(0);
            break;
        case 7:
            printf("\e[1;1H\e[2J");
            break;

        default:
            system("cls");
            free(patients);
            printf("Please input a correct command!\nEnter: ");

            break;
        }
        system("cls");
    }
}
