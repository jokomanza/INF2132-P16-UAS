#include <printf.h>
#include "Student.h"
#include "utility.h"


void inputStudent(struct Student *student) {
    divider();
    printf("Please input student information:\n");

    printf("| Id\t\t\t: ");
    scanf("%d", &student->idNumber);
    getchar();

    printf("| Name\t\t\t: ");
    scanf("%[^\n]%*c", student->name);

    printf("| Study Program\t: ");
    scanf("%[^\n]%*c", student->studyProgram);

    printf("| Semester\t\t: ");
    scanf("%d", &student->semester);
    getchar();

    printf("\n");
}
