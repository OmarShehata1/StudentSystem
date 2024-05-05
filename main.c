#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "admin.h"
#include "user.h"
#include "list.h"
#include "file_access.h"

int TotalStudents=5;

struct student school[MAXSTUDENTS]= {{"1005","omar","123456","95",20,2},
    {"1004","mohamed","98765","88",21,3},
    {"1003","ahmed","25895","90",22,4},
    {"1002","nada","963258","93",20,2},
    {"1001","layla","741252","80",23,5}
};

int main()
{

readFromFile(school, "student_file");
    mode();


    return 0;
}


