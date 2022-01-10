#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

//Initializing Structure
typedef struct patient
{

    int nic;
    int age;
    char name[50];
    char gender;
    char AdmissionDate[15];
} patient;

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
    int nic, found = 0;
    printf("---------------------------------------------------------\n");
    printf("FINDING PATIENT\n");
    printf("---------------------------------------------------------\n\n");
    printf("Enter the NIC number of the patient: ");
    scanf("%d", &nic);
    for (int i = 0; i < PatientCount; i++)
    {
        if (patients[i].nic == nic)
        {
            found = 1;
            printf("\nName: %s\t|\tNIC: %d\t|\tAge: %d\t|\tGender: %c", patients[i].name, patients[i].nic, patients[i].age, patients[i].gender);
            break;
        }
    }

    if (found == 0)
    {
        system("cls");
        printf("Sorry, There is no record for the NIC number - %d", nic);
    }
}


//Funtion to delete a record of a patient
void deletePatient(patient *patients, int PatientCount){
    printf("---------------------------------------------------------\n");
    printf("DELETE A PATIENT RECORD\n");
    printf("---------------------------------------------------------\n\n");
    int nic, found = 0;
    printf("Enter the NIC number of the patient: ");
    scanf("%d", &nic);
    for (int i = 0; i < PatientCount; i++)
    {
        if (patients[i].nic == nic)
        {
            found = 1;
            for (int j = i; j < PatientCount; j++)
            {
                patients[i]=patients[i+1];
                PatientCount--;
                
            }
            printf("Record of the patient %d deleted succesfully", patients[i].nic);
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
    printf("---------------------------------------------------------\n");
    printf("All RECORDS\n");
    printf("---------------------------------------------------------\n");

    for (int i = 0; i < PatientCount; i++)
    {
        printf("\nName: %s\t|\tNIC: %d\t|\tAge: %d\t\t|\tGender: %c", patients[i].name, patients[i].nic, patients[i].age, patients[i].gender);
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
    printf("Enter NIC: ");
    scanf("%d", &new.nic);
    printf("Enter Gender: ");
    scanf(" %c", &new.gender);
    printf("Enter Age: ");
    scanf("%d", &new.age);

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
                patients = (patient *)realloc(patients, (PatientCount + 1) * sizeof(patient)); //Everytime adding a new patient allocated memory increasing using realloc
                patients[PatientCount] = addPatient();
                PatientCount++;
                printf("\nDo you want to add more patients? (Y/N): ");
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
            system("cls");
            parintAllPatients(patients, PatientCount);
            break;
        case 4:
            deletePatient(patients, PatientCount);
            break;
        case 0:
            exit(0);
            break;
        case 7:
            printf("\e[1;1H\e[2J");
            break;

        default:
            system("cls");
            printf("Please input a correct command!\nEnter: ");
            
            break;
        }
    }

    // patients[0] = addPatient();
    // patients[1] = addPatient();

    // printf("NIC: %d\t\tName: %s", patients[0].nic, patients[0].name);
    // printf("\nNIC: %d\t\tName: %s", patients[1].nic, patients[1].name);
}
