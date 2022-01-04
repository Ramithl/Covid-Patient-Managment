#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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
        printf("Sorry, There is no record for the NIC number");
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
    


void deletePatient()
{
    printf("---------------------------------------------------------\n");
    printf("DELETE PATIENT FUNCTION CALLED SUCCESSFULLY\n");
    printf("---------------------------------------------------------\n");
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

    while (quit == 0)
    {
        printFunc();
        command = getCommand();
        switch (command)
        {
        case 1:
            system("cls");
            patients = (patient *)realloc(patients, (PatientCount + 1) * sizeof(patient)); //Everytime adding a new patient allocated memory increasing using realloc
            patients[PatientCount] = addPatient();
            PatientCount++;
            break;
        case 2:
            system("cls");
            findPatient(patients, PatientCount);
            break;
        case 3:
            system("cls");
            parintAllPatients(patients, PatientCount);
            break;
        case 4:
            deletePatient();
            break;
        case 0:
            exit(0);
            break;

        default:
            printf("Please input a correct command!");
            exit(-1);
            break;
        }
    }

    // patients[0] = addPatient();
    // patients[1] = addPatient();

    // printf("NIC: %d\t\tName: %s", patients[0].nic, patients[0].name);
    // printf("\nNIC: %d\t\tName: %s", patients[1].nic, patients[1].name);
}
