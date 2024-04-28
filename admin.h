
#include<stdio.h>
#include "list.h"

void mode(void);
void student_add(struct student *ps);
void mainMenu();
void student_call(struct student *arr,int TotalStudents,char *name);
void student_printAll(struct student *arr);
void student_edit(struct student*arr,char*name );
void student_Remove(struct student *arr,char* name);
void student_sortByName(struct student *arr);
void student_print(struct student s );
int student_Search(struct student*arr,char*name);

void string_scan(char* str,int maxSize);
int string_check(char*arr);
int string_checkNumber(char*arr);
int string_compare(char*str1,char*str2);




