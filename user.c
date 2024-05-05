#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "list.h"

extern int TotalStudents;
extern struct student school[MAXSTUDENTS];


void userMode(void)
{
    char id[IDMAX];
    char name[NAMEMAX];
    char password[PASSWORDMAX];
    int found_Student;
    char key,IsCorrect=3;

    printf("Enter student ID: ");
    string_scan(id,IDMAX);
    found_Student=student_Search1(school,id);
    while(IsCorrect)
    {
            if(found_Student!=-1)
            {
                printf("Enter student Password: ");
                string_scan(password,PASSWORDMAX);
                if(strcasecmp(school[found_Student].password,password)==0)
                {
                    do
                    {

                        int choice;
                        printf("\n\t\t\t  User Menu\t\t\n");
                        printf("\t\t==================================\n\n");
                        printf("\t\t[1]view your Record\n");
                        printf("\t\t[2]Edit your Password\n");
                        printf("\t\t[3]Edit your name \n");
                        printf("Enter choice: ");
                        scanf("%d",&choice);
                        switch(choice)
                        {

                        case 1:
                            student_print(school[found_Student]);

                            break;
                        case 2:
                            student_editPassword(school,id);
                            break;
                        case 3:
                            student_editName(school,id);


                            break;
                        default:
                            printf("Invalid Number \n\n");
                        }
                        printf("Press any key to continue, Q to Quit ...");
                        scanf(" %c",&key);
                        system("cls");
                    }
                    while(key!='Q' && key!='q');
                }
                else
                {
                    IsCorrect--;
                    system("cls");
                    printf("Wrong Password \n\n");
                }
            }
            else
            {
                printf("Not found Student!!\n");
            }
    }
}





int student_Search1(struct student*arr,char*id)
{
    int i;
    for( i=0 ; i<TotalStudents ; i++)
    {
        if((strcmp(id,arr[i].id)==0))
        {
            return i;
        }
    }
    return -1;

}

int student_Search2(struct student*arr,char*password)
{
    int i;
    for( i=0 ; i<TotalStudents ; i++)
    {
        if((strcmp(password,arr[i].password)==0))
        {
            return i;
        }
    }
    return -1;

}

void student_editName(struct student*arr,char*id )
{
    int i;
    for( i=0 ; i<TotalStudents ; i++)
    {
        if(strcmp(arr[i].id,id)==0)
        {
            printf("Enter name: ");
            string_scan(arr[i].name,NAMEMAX);
            printf("\n");
        }
    }

    printf("\n\n\t\t\t Edit your name successfully! \n\n\n");
    writeToFile(*arr);
}

void student_editPassword(struct student*arr,char*id )
{
    int i;
    for( i=0 ; i<TotalStudents ; i++)
    {
        if(strcmp(arr[i].id,id)==0)
        {
            printf("Enter password : ");
            string_scan(arr[i].password,PASSWORDMAX);
            printf("\n");
        }
    }
    printf("\n\n\t\t\t Edit your password successfully! \n\n\n");
    writeToFile(*arr);
}
