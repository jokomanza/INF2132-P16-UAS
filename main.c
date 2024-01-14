#include "Student.h"
#include "Course.h"

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