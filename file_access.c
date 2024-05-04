#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "list.h"
void readFromFile(struct student *arr, char *myfile) {
FILE *my_file=NULL;
my_file=fopen("student_file","r");
if(NULL!=my_file){

    int i = 0;
    while (fscanf(my_file, "%s %s %s %s %d %d", arr[i].id, arr[i].name, arr[i].password, arr[i].grade, &arr[i].age, &arr[i].NumberOfCourse) == 6) {
        i++;

}
}
else{
    printf("Error\n");
}
    fclose(my_file);

}

void writeToFile(struct student *arr, int TotalStudents, char *myfile) {
FILE *my_file=NULL;
my_file=fopen("student_file","w");
if(NULL!=my_file){
    for(int i=1;i<TotalStudents;i++){
        fprintf(my_file,"%i.Id:[%i]\n%i.Name:[%s]\n%i.Password:[%i]\n%i.Grade:[%i]\n%i.age:[%i]\n%i.NumberOfCourse:[%i]\n"
                ,i,arr[i].id,i,arr[i].name,i,arr[i].password,i,arr[i].grade,i,arr[i].age,i,arr[i].NumberOfCourse);
    }
}
else{
    printf("Error\n");
}
    fclose(my_file);

}


