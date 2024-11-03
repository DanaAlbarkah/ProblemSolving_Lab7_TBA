#include <stdio.h>
#include <string.h>

struct Students {
    int id;
    char name[50];
    float gpa;
};

int main() {
    int N;
    printf("Enter the number of students: ");
    scanf("%d", &N);
    struct Students student1[N];
    for (int i = 0; i < N; i++) {
        printf("Enter ID for student %d: ", i + 1);
        scanf("%d", &student1[i].id);
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", student1[i].name);
        printf("Enter GPA for student %d: ", i + 1);
        scanf("%f", &student1[i].gpa); 
    }
	printf("Student Records: ");
    for (int i = 0; i < N; i++) {
        printf("ID: %d  Name: %s   GPA: %.2f\n", student1[i].id, student1[i].name, student1[i].gpa); 
    }

    return 0;
}

