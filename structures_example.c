#include <stdio.h>
#include <string.h>

// Define a structure for student data 
typedef struct Student {
    int id;        // Stduent ID
    char name[50]; // Stduent name
    float gpa;     // Student GPA
} Student;

int main(){
    // creating an instance of the Student structure
    Student student1;

    // Assigning values to the field of stduent1
    student1.id = 101;
    strcpy(student1.name,"Alice");
    student1.gpa = 3.8;

    // Displaying the contents of student1
    printf("ID: %d\n",student1.id);
    printf("Name: %s\n",student1.name);
    printf("GPA: %f\n",student1.gpa);
    return 0;
}