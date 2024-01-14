#include <stdio.h>
#include "Student.h"
#include "Course.h"

void divider() {
    printf("=======================================================\n");
};

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

int inputNumberOfCourses() {
    int numberOfCourses;

    printf("Please input courses information:\n");
    printf("| Number of course\t\t\t: ");
    scanf("%d", &numberOfCourses);
    getchar();

    return numberOfCourses;
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

void inputCourses(struct Course (*courses)[], int numberOfCourses) {
    for (int n = 0; n < numberOfCourses; ++n) {
        struct Course course = {};

        divider();
        printf("| Course %d\n", n + 1);

        printf("| Code\t\t: ");
        scanf("%[^\n]%*c", course.courseCode);

        printf("| Name\t\t: ");
        scanf("%[^\n]%*c", course.courseName);

        printf("| Credits\t: ");
        scanf("%d", &course.credits);
        getchar();

        printf("| Grade\t\t: ");
        scanf("%[^\n]%*c", &course.grade);

        divider();
        printf("\n");

        (*courses)[n] = course;
    }
}


void calculateCoursesGrade(struct Course (*courses)[], int numberOfCourses) {
    for (int courseIndex = 0; courseIndex < numberOfCourses; ++courseIndex) {
        struct Course course = (*courses)[courseIndex];

        (*courses)[courseIndex].gradeWeight = convertToGradeWeight(course.grade);
        (*courses)[courseIndex].actualGrade = course.credits * (*courses)[courseIndex].gradeWeight;
    }
}

void printStudentCourses(struct Student student, struct Course courses[], int numberOfCourses) {
    printf("========================================================================================================================\n");
    printf("NIM\t\t\t\t: %d\n", student.idNumber);
    printf("Name\t\t\t: %s\n", student.name);
    printf("Study Program\t: %s\n", student.studyProgram);
    printf("Semester\t\t: %d\n", student.semester);
    printf("\n");

    printf("========================================================================================================================\n");
    printf("| No\t| Code\t\t| Name\t\t\t\t\t\t\t\t| Credits\t\t| Grade\t\t| Grade Weight\t| Actual Grade |\n");
    printf("========================================================================================================================\n");

    int totalCredits = 0;
    int totalActualGrades = 0;
    float sks;

    for (int i = 0; i < numberOfCourses; ++i) {
        struct Course course = courses[i];
        totalCredits += course.credits;
        totalActualGrades += course.actualGrade;

        printf("| %-6d", i + 1);
        printf("| %-10s", course.courseCode);
        printf("| %-34s", course.courseName);
        printf("| %-14d", course.credits);
        printf("| %-14c", course.grade);
        printf("| %-14d", course.gradeWeight);
        printf("| %-13d|", course.actualGrade);
        printf("\n");
    }

    sks = (float) totalActualGrades / (float) totalCredits;

    printf("========================================================================================================================\n");
    printf("|%49s\t\t| %-45d | %-13d|\n", "Total", totalCredits, totalActualGrades);
    printf("|%49s\t\t| %-45s | %-13.2f|\n", "IP Semester", " ", sks);
    printf("========================================================================================================================\n");
}

int main() {
    struct Student student = {};
    inputStudent(&student);

    int numberOfCourses = inputNumberOfCourses();
    struct Course courses[numberOfCourses];
    inputCourses(&courses, numberOfCourses);

    calculateCoursesGrade(&courses, numberOfCourses);
    printStudentCourses(student, courses, numberOfCourses);

    return 0;
}

void other() {

    struct Student student = {
            .idNumber = 231110062,
            .name = "Joko Supriyanto",
            .studyProgram = "Computer Science",
            .semester = 1
    };

    struct Course courses[9] = {
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
}