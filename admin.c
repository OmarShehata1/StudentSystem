#include <stdio.h>
#include "admin.h"
#include <string.h>
#include <windows.h>
#include "list.h"


extern int TotalStudents;
extern struct student school[MAXSTUDENTS];
static int password=1234;

void passcheck()
{
    int i,pass;
    printf("Please Enter The Password\n");
    for(i=0; i<3; i++)
    {
        scanf("%d",&pass);
        if(pass==password)
        {
            printf("---->Welcome To Admin Mode<----\n");
            system("cls");
            mainMenu();
            break;
        }
        else
        {
            if(i!=2)
                printf("Wrong Password !!,Try agian\n");
            else
                printf("Wrong Password !!,No more tries\n");
        }
    }
}

void student_add(struct student *ps)
{
    int checknumber;
    printf("Enter ID: ");
    string_scan(ps->id,IDMAX);
    do
    {
        checknumber=string_checkNumber(ps->id);
        if(checknumber)
        {
            break;
        }
        else
        {
            system("cls");
            printf("invalid id , Try Again!! \n");
            printf("Enter ID: ");
            string_scan(ps->id,IDMAX);

        }
    }
    while(1);




    int checkString;
    printf("Enter name: ");
    string_scan(ps->name,NAMEMAX);
    do
    {
        checkString=string_check(ps->name);
        if(checkString)
        {
            break;
        }
        else
        {
            system("cls");
            printf("invalid name , Try Again!! \n\n");
            printf("Enter name: ");
            string_scan(ps->name,NAMEMAX);

        }
    }
    while(1);



    printf("Enter Password: ");
    string_scan(ps->password,PASSWORDMAX);

    printf("Enter Grade: ");
    string_scan(ps->grade,GRADEMAX);


    fflush(stdin);
    printf("Enter age: ");
    scanf("%d",&ps->age);
    do
    {
        if((ps->age)>25 ||(ps->age)<5)
        {
            system("cls");
            printf("Invalid Age, Try Again: \n\n");
            printf("Enter age: ");
            scanf("%d",&ps->age);
        }
        else
        {
            break;
        }

    }
    while(1);

    printf("Enter NumberOfCourse: ");
    scanf("%d",&ps->NumberOfCourse);
    do
    {
        if((ps->NumberOfCourse) < COURSESMAX)
        {
            break;
        }
        else
        {
            system("cls");
            printf("Invalid Number, Try Again: \n\n");
            printf("Enter NumberOfCourse: ");
            scanf("%d",&ps->NumberOfCourse);
        }

    }
    while(1);


    TotalStudents++;
    system("cls");
    printf("\n\n\t\t\t student added successfully! \n\n\n");
}

void mainMenu()
{

    char name[20];
    int found_Student;
    char key;
    do
    {

        int choice;
        printf("\n\t\t\t  Main Menu\t\t\n");
        printf("\t\t==================================\n\n");
        printf("\t\t[1]Add Student\n");
        printf("\t\t[2]Edit student\n");
        printf("\t\t[3]Remove student \n");
        //  printf("\t\t[4]Call student \n");
        printf("\t\t[4]search student\n");
        printf("\t\t[5]Sort school \n");
        printf("\t\t[6]Print school\n\n\n");


        printf("Enter your choice :");
        scanf("%d",&choice);
        system("cls");


        switch(choice)
        {
        case 1:
            if(TotalStudents<100)
            {
                student_add(&school[TotalStudents]);
                //system("cls");
            }
            break;
        case 2:
            printf("Enter student name: ");
            string_scan(name,NAMEMAX);
            student_edit(school,name);
            system("cls");
            break;
        case 3:
            printf("Enter student name: ");
            string_scan(name,NAMEMAX);
            student_Remove(school,name);
            system("cls");
            break;
        /*  case 4:
              printf("Enter student name: ");
              string_scan(name,NAMEMAX);
              student_call(school,TotalStudents,name);
              break;*/
        case 4:
            printf("Enter student name: ");
            string_scan(name,NAMEMAX);
            found_Student=student_Search(school,name);
            printf("%d\n\n",found_Student);
            if(found_Student!=-1)
            {
                student_print(school[found_Student]);
            }
            else
            {
                printf("Not found Student!!\n");
            }
            break;
        case 5:
            student_sortByName(school);
            break;
        case 6:
            student_printAll(school);
            break;
        default:
            printf("Invalid Number.");
            break;

        }
        printf("Press any key to continue, Q to Quit ...");
        scanf(" %c",&key);
        system("cls");

    }
    while(key!='Q' && key!='q');
}
/*

void student_call(struct student *arr,int TotalStudents,char *name)
{
    int i,j=5;
    for(i=0; i<TotalStudents; i++)
    {
        if(strcmp(arr[i].name,name)==0)
        {
            while(j)
            {
                printf("%s",arr[i].phone);
                sleep(1);
                system("cls");
                printf("%s .",arr[i].phone);
                sleep(1);
                system("cls");
                printf("%s ..",arr[i].phone);
                sleep(1);
                system("cls");
                printf("%s ...",arr[i].phone);
                sleep(1);
                system("cls");
                j--;
            }
        }
    }
    printf("Number is busy!!\n");

}
*/



void student_printAll(struct student *arr)
{
    printf("|==========|====================|==============================|====================|=============|==========|\n");
    printf("|    ID    |        Name        |            Password          |       Grade        |  NO.Course  |    age   |\n");
    printf("|==========|====================|==============================|====================|=============|==========|\n");
    int i,j;

    for(i=0; i<TotalStudents; i++)
    {
        printf("|");
        printf("%s",arr[i].id);
        for( j=0; j < (10-strlen(arr[i].id)); j++)
        {
            printf(" ");
        }

        printf("|");
        printf("%s",arr[i].name);
        for(j=0; j < (20-strlen(arr[i].name)); j++)
        {
            printf(" ");
        }

        printf("|");
        printf("%s",arr[i].password);
        for(j=0; j < (30-strlen(arr[i].password)); j++)
        {
            printf(" ");
        }

        printf("|");
        printf("%s",arr[i].grade);
        for(j=0; j < (20-strlen(arr[i].grade)); j++)
        {
            printf(" ");
        }

        printf("|");
        printf("%d",arr[i].NumberOfCourse);
        for(j=0; j < 12; j++)
        {
            printf(" ");
        }

        printf("|");
        printf("%d",school[i].age);
        for(j=0; j < 10; j++)
        {
            printf(" ");
        }
        printf("\n");
        printf("|----------|--------------------|------------------------------|--------------------|-------------|----------|\n");
    }
    printf("\n");

}




void student_edit(struct student*arr,char*name )
{
    int i;
    for( i=0 ; i<TotalStudents ; i++)
    {
        if(strcmp(arr[i].name,name)==0)
        {
            int object;
            printf("\t\t\t[1] Name\n");
            printf("\t\t\t[2] ID\n");
            printf("\t\t\t[3] Password\n");
            printf("\t\t\t[4] Grade\n");
            printf("\t\t\t[5] Age\n");
            printf("\t\t\t[6] NumberOfCourses\n");
            printf("\n\nselect object you want to modify: ");
            scanf("%d",&object);
            switch(object)
            {
            case 1:
                printf("Enter name: ");
                string_scan(arr[i].name,25);
                printf("\n");
                break;
            case 2:
                printf("Enter id: ");
                string_scan(arr[i].id,10);
                printf("\n");
                break;
            case 3:
                printf("Enter an password: ");
                string_scan(arr[i].password,10);
                printf("\n");
                break;
            case 4:
                printf("Enter a Grade: ");
                string_scan(arr[i].grade,5);
                printf("\n");
                break;
            case 5:
                printf("Enter age: ");
                scanf("%d",&arr[i].age);
                break;
            case 6:
                printf("Enter NumberOfCourse: ");
                scanf("%d",&arr[i].NumberOfCourse);
                break;
            default:
                printf("Invalid Number.");
                break;
            }
        }

    }
}




void student_Remove(struct student *arr,char* name)
{
    int i,found_index=-1;
    for(i=0; i<TotalStudents; i++)
    {
        if(strcmp(arr[i].name,name)==0)
        {
            found_index=i;
            break;
        }
    }
    if(found_index==-1)
    {
        printf("name not found");
    }
    else
    {
        for(i=found_index; i<TotalStudents; i++)
        {
            arr[i]=arr[i+1];
        }
        TotalStudents--;
    }
}



void student_sortByName(struct student *arr)
{
    struct student temp;
    int i,j,sortedFlag=0;

    for(j=0; j<TotalStudents &&sortedFlag==0; j++)
    {
        sortedFlag=1;
        for(i=0; i<TotalStudents-1; i++)
        {
            if(arr[i].name[0]>arr[i+1].name[0])
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                sortedFlag=0;
            }
        }
    }

    system("cls");
    printf("\n\n\t\t\t students sorted successfully! \n\n\n");
}



int student_Search(struct student*arr,char*name)
{
    int i;
    for( i=0 ; i<TotalStudents ; i++)
    {
        if((strcmp(name,arr[i].name)==0))
        {
            return i;
        }
    }
    return -1;

}



void student_print(struct student s )
{
    printf("|==========|====================|==============================|====================|=============|==========|\n");
    printf("|    ID    |        Name        |            Password          |       Grade        |  NO.Course  |    age   |\n");
    printf("|==========|====================|==============================|====================|=============|==========|\n");


    int j;
    printf("|");
    printf("%s",s.id);
    for( j=0; j < (10-strlen(s.id)); j++)
    {
        printf(" ");
    }

    printf("|");
    printf("%s",s.name);
    for(j=0; j < (20-strlen(s.name)); j++)
    {
        printf(" ");
    }

    printf("|");
    printf("%s",s.password);
    for(j=0; j < (30-strlen(s.password)); j++)
    {
        printf(" ");
    }

    printf("|");
    printf("%s",s.grade);
    for(j=0; j < (20-strlen(s.grade)); j++)
    {
        printf(" ");
    }

    printf("|");
    printf("%d",s.NumberOfCourse);
    for(j=0; j < 12; j++)
    {
        printf(" ");
    }

    printf("|");
    printf("%d",s.age);
    for(j=0; j < 10; j++)
    {
        printf(" ");
    }
    printf("\n");
    printf("|----------|--------------------|------------------------------|--------------------|-------------|----------|\n");

    printf("\n");

}


void mode(void)
{
    int choice ;
    printf("\t\t\t----> Welcome to Student Record System <----\n\n");
    char key;
    do
    {
        printf("\n\t\t\t   main Mode \t\t\n");
        printf("\t\t==================================\n\n");
        printf("\t\t[1] Admin Mode\n");
        printf("\t\t[2] User Mode\n\n");

        printf("Select Mode :");
        scanf("%d",&choice);
        system("cls");

        switch(choice)
        {
        case 1:
            passcheck();
            system("cls");
            mainMenu();
            break;
        case 2:
            userMode();
            break;
        default:
            printf("Invalid Number\n");
            break;
        }
        printf("Press any key to continue, Q to Quit ...");
        scanf(" %c",&key);
        system("cls");

    }
    while(key!='Q' && key!='q');
}

