
#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED




#define IDMAX        10
#define NAMEMAX      30
#define GRADEMAX     5
#define PASSWORDMAX  10
#define COURSESMAX   15
#define MAXSTUDENTS 100


typedef struct student
{
    char id[IDMAX];
    char name[NAMEMAX];
    char password[PASSWORDMAX];
    char grade[GRADEMAX];
    int age;
    int NumberOfCourse;

} s_t;



#endif // LIST_H_INCLUDED
