

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

#endif
