#ifndef STUDENTS_H
#define STUDENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
   char * name;
   int id;
};

typedef struct student Student;

void printStudent(void * passedIn);
void * buildStudent(FILE *);
void * buildStudent_Prompt(FILE * fin);
int compareTwoStudents(const void * p1, const void * p2);
void cleanStudent(void *);


#endif // STUDENTS_H
