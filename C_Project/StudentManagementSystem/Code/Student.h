#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

/*********************Includes**********************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/***************************************************************/

#define MAX_ACADEMIC_YEAR    5UL

typedef struct
{
    char id[4];
    char name[10];
    int Credit_Hours;
    float grade;

}Course;

typedef struct st
{
  char Name[40];
  unsigned int id;
  int year;
  Course Courses[3];
   struct st* next;
   float GPA;
   int Num_Courses;
   char gender;

}student;

typedef enum
{
    UNVALID,
    VALID,
}ValidType_t;


/*******************************Functions to App************************************************/
void Add_Student (void);
void Remove_Student (void);
void search_Student (void);
void Add_Courses (void);
void menu (void);
/***********************************************************************************************/

#endif // STUDENT_H_INCLUDED
