#ifndef INF2132_P16_UAS_COURSE_H
#define INF2132_P16_UAS_COURSE_H

struct Course {
    char courseCode[10];
    char courseName[50];
    int credits;
    char grade;
    int gradeWeight;
    int actualGrade;
};

int inputNumberOfCourses();

int convertToGradeWeight(char grade);

void inputCourses(struct Course (*courses)[], int numberOfCourses);

void calculateCoursesGrade(struct Course (*courses)[], int numberOfCourses);

void printStudentCourses(struct Student student, struct Course courses[], int numberOfCourses);

#endif


