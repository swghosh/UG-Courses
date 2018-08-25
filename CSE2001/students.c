#include <stdio.h>
#include <string.h>

#define STUDENTS_COUNT 5

struct student {
    char name[30], branch[5];
    int age;
    long int rollNumber, dateOfBirth;
};

#define STUDENT struct student

#define SPECIFIC_BRANCH "CSE"

int main() {
    STUDENT students[STUDENTS_COUNT];
    int iterIndex;

    printf("Specify student details. (expected %d records). \n", STUDENTS_COUNT);
    for(iterIndex = 0; iterIndex < STUDENTS_COUNT; iterIndex++) {
        printf("%d. (name, age, roll number, branch, dob).\n", iterIndex+1);
        printf("(string, integer, long, string, long [YYYYMMDD] space-seperated expected) > ");
        scanf("%s %d %ld %s %ld", students[iterIndex].name, &students[iterIndex].age,
            &students[iterIndex].rollNumber, students[iterIndex].branch, &students[iterIndex].dateOfBirth);
    }

    printf("\nStudents with branch %s are: \n", SPECIFIC_BRANCH);
    for(iterIndex = 0; iterIndex < STUDENTS_COUNT; iterIndex++) {
        if(strcmp(students[iterIndex].branch, SPECIFIC_BRANCH) == 0) {
            printf("(name: %s, age: %d, roll number: %ld, dob: %ld)\n", students[iterIndex].name, students[iterIndex].age,
                students[iterIndex].rollNumber, students[iterIndex].dateOfBirth);
        }
    }
}