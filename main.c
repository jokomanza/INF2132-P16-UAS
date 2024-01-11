#include <stdio.h>
#include <stdbool.h>
#include "Student.h"
#include "Course.h"

void divider() {
    printf("=======================================================\n");
};


bool isGradeValid(char grade) {
    return grade == 'A' || grade == 'B' || grade == 'C' || grade == 'D' || grade == 'E';
}

int convertToGradeWeight(char grade) {
    switch (grade) {
        case 'A':
            return 4;
        case 'B':
            return 3;
        case 'C':
            return 2;
        case 'D':
            return 1;
        case 'E':
            return 0;
        default:
            return -1;
    }
}

void inputGrades(struct Course (*courses)[]) {
    for (int courseIndex = 0; courseIndex < 9; ++courseIndex) {
        struct Course course = (*courses)[courseIndex];
        char grade;

        divider();
        printf("| %s - %s\n", course.courseCode, course.courseName);
        divider();
        while (true) {
            printf("| Please input course of this course: ");
            scanf(" %c", &grade);

            if (!isGradeValid(grade)) {
                printf("| - [WARNING] Inputted grade %c is not valid, please try again\n", grade);
                continue;
            }

            (*courses)[courseIndex].grade = grade;
            divider();

            printf("\n");
            break;
        }
    }
}


void calculateCoursesGrade(struct Course (*courses)[]) {
    for (int courseIndex = 0; courseIndex < 9; ++courseIndex) {
        struct Course course = (*courses)[courseIndex];

        (*courses)[courseIndex].gradeWeight = convertToGradeWeight(course.grade);
        (*courses)[courseIndex].actualGrade = course.credits * (*courses)[courseIndex].gradeWeight;
    }
}

void printStudentCourses(struct Student student, struct Course courses[]) {
    printf("========================================================================================================================\n");
    printf("NIM\t\t\t\t: %d\n", student.idNumber);
    printf("Name\t\t\t: %s\n", student.name);
    printf("Study Program\t: %s\n", student.studyProgram);
    printf("Semester\t\t: %d\n", student.semester);
    printf("\n");

    printf("========================================================================================================================\n");
    printf("| No\t| Code\t\t| Name\t\t\t\t\t\t\t\t| Credits\t\t| Course\t\t| Course Weight\t| Actual Grade |\n");
    printf("========================================================================================================================\n");

    int totalCredits = 0;
    int totalActualGrades = 0;
    float sks;

    for (int i = 0; i < 8; ++i) {
        struct Course grade = courses[i];
        totalCredits += grade.credits;
        totalActualGrades += grade.actualGrade;

        printf("| %-6d", i + 1);
        printf("| %-10s", grade.courseCode);
        printf("| %-34s", grade.courseName);
        printf("| %-14d", grade.credits);
        printf("| %-14c", grade.grade);
        printf("| %-14d", grade.gradeWeight);
        printf("| %-13d|", grade.actualGrade);
        printf("\n");
    }

    sks = (float) totalActualGrades / (float) totalCredits;

    printf("========================================================================================================================\n");
    printf("|%49s\t\t| %-45d | %-13d|\n", "Total", totalCredits, totalActualGrades);
    printf("|%49s\t\t| %-45s | %-13.2f|\n", "IP Semester", " ", sks);
    printf("========================================================================================================================\n");
}

int main() {
    struct Student student = {
            .idNumber = 231110062,
            .name = "Joko Supriyanto",
            .studyProgram = "Computer Science",
            .semester = 1
    };

    struct Course grades[9] = {
            {
                    .courseCode = "MBY01",
                    .courseName = "Pendidikan Agama Islam",
                    .credits = 2,
            },
            {
                    .courseCode = "MBY07",
                    .courseName = "Pancasila",
                    .credits = 2,
            },
            {
                    .courseCode = "FTI2120",
                    .courseName = "Etika",
                    .credits = 2,
            },
            {
                    .courseCode = "FTI2130",
                    .courseName = "Pengantar Informatika",
                    .credits = 2,
            },
            {
                    .courseCode = "INF2131",
                    .courseName = "Konsep Sistem Informasi",
                    .credits = 2,
            },
            {
                    .courseCode = "INF2132",
                    .courseName = "Algoritma & Pemrograman",
                    .credits = 2,
            },
            {
                    .courseCode = "INF2132P",
                    .courseName = "Praktikum Algoritma & Pemrograman",
                    .credits = 1,
            },
            {
                    .courseCode = "INF2133",
                    .courseName = "Fisika Optis & Gelombang",
                    .credits = 2,
            },
            {
                    .courseCode = "INF2134",
                    .courseName = "Kalkulus",
                    .credits = 3,
            }
    };

    inputGrades(&grades);
    calculateCoursesGrade(&grades);
    printStudentCourses(student, grades);

    return 0;
}
