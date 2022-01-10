#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>



void gotoxy(int x, int y)
{
COORD c;
c.X = x;
c.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void main(){
    // COORD c;
    // c.X = 40;
    // c.Y = 16;
  
    // SetConsoleCursorPosition(
    //     GetStdHandle(STD_OUTPUT_HANDLE), c);
    gotoxy(26, 4);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ALL PATIENTS RECORDS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(5, 6);
    printf("==========================================================================================");

    gotoxy(5, 7);
    printf("Name\t\t    NIC No.\t      Gender\t\tAge \t\tAdmission Date\n"); //TABLE TITLES !

    gotoxy(5, 8);
    printf("==========================================================================================");

    gotoxy(5, 10);
    printf("Ramith Laksara");
    gotoxy(28, 10);
    printf("789546521302");
    gotoxy(46, 10);
    printf("Female");
    gotoxy(64, 10);
    printf("22 Years");
    gotoxy(80, 10);
    printf("2022/01/09");

}