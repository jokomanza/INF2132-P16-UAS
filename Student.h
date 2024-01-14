#ifndef INF2132_P16_UAS_STUDENT_H
#define INF2132_P16_UAS_STUDENT_H

struct Student {
    int idNumber;
    char name[30];
    char studyProgram[30];
    int semester;
};

void inputStudent(struct Student *student);

#endif
