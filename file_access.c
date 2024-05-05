#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "list.h"


void readFromFile(struct student *arr, char *myfile) {
FILE *my_file=NULL;
my_file=fopen("student_file","rb");
if(NULL!=my_file){

    int i = 0;
    while (fscanf(my_file, "%s %s %s %s %d %d", arr[i].id, arr[i].name, arr[i].password, arr[i].grade, &arr[i].age, &arr[i].NumberOfCourse) !=EOF) {
        i++;

}
}
else{
    printf("Error\n");
}
    fclose(my_file);

}

void writeToFile(struct student s) {
FILE *my_file=NULL;
my_file=fopen("student_file","a");
if(NULL!=my_file){
   fprintf(my_file," %s %s %s %s %d %d",s.id,s.name,s.password,s.grade,s.age,s.NumberOfCourse);
}
else{
    printf("Error\n");
}
    fclose(my_file);

}

