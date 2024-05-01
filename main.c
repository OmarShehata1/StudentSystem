#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "admin.h"
#include "user.h"
#include "list.h"
int TotalStudents=5;


struct student school[MAXSTUDENTS]= {{"1005","omar","123456","3.5",20,2},
    {"1004","mohamed","98765","3.8",21,3},
    {"1003","ahmed","25895","3.4",22,4},
    {"1002","nada","963258","3.2",20,2},
    {"1001","layla","741252","3.6",23,5}
};

int main() {
    mode();

    return 0;
}



