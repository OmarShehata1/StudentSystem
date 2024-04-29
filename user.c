#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "list.h"

extern int TotalStudents;
extern struct student school[MAXSTUDENTS];

void viewRecord(struct student *arr, int index) {
    if (index != -1) {
        student_print(arr[index]);
    } else {
        printf("Student record not found.\n");
    }
}

void editPassword(struct student *arr, int index) {
    if (index != -1) {
        printf("Enter new password: ");
        string_scan(arr[index].password, PASSWORDMAX);
        printf("Password updated successfully!\n");
    } else {
        printf("Student record not found.\n");
    }
}

void editName(struct student *arr, int index) {
    if (index != -1) {
        printf("Enter new name: ");
        string_scan(arr[index].name, NAMEMAX);
        printf("Name updated successfully!\n");
    } else {
        printf("Student record not found.\n");
    }
}

void studentMode(struct student *arr, int TotalStudents) {
    char id[IDMAX];
    char password[PASSWORDMAX];
    int index;
    int choice;

    printf("Enter your ID: ");
    string_scan(id, IDMAX);
    printf("Enter your password: ");
    string_scan(password, PASSWORDMAX);

    index = student_Search(arr, id);

    if (index != -1 && strcmp(arr[index].password, password) == 0) {
        do {
            printf("\n\t\t\t  Student Mode\n");
            printf("\t\t==================================\n\n");
            printf("\t\t[1] View your record\n");
            printf("\t\t[2] Edit your password\n");
            printf("\t\t[3] Edit your name\n");
            printf("\t\t[4] Exit Student Mode\n\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            system("cls");

            switch (choice) {
                case 1:
                    viewRecord(arr, index);
                    break;
                case 2:
                    editPassword(arr, index);
                    break;
                case 3:
                    editName(arr, index);
                    break;
                case 4:
                    printf("Exiting Student Mode...\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } while (choice != 4);
    } else {
        printf("Invalid ID or password. Access denied.\n");
    }
}

