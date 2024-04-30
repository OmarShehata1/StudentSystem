#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "admin.h"
#include "user.h"
#include "list.h"
int TotalStudents=5;


struct student school[MAXSTUDENTS]= {{"1005","omar","123456","3.5",20,2},
    {"1002","mohamed","98765","3.8",21,3},
    {"1003","ahmed","25895","3.4",22,4},
    {"1004","nada","963258","3.2",20,2},
    {"1005","layla","741252","3.6",23,5}
};

int main() {
    int mode;

    printf("---->Welcome to Student Record System<----\n");
    printf("[1]. Admin Mode\n");
    printf("[2]. User Mode\n");
    scanf("%d", &mode);

    if (mode == 1) {
       passcheck();
    } else if (mode == 2) {
     studentMode();
         } else {
        printf("Invalid choice. Exiting program.\n");
    }

    return 0;
}



