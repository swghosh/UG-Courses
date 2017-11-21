#include <stdio.h>
#include <stddef.h>

int main(void) {

    struct student {
        char *name;
        long int enrollNum;
        long int phoneNum;
    };
    typedef struct student Student;
    
    size_t studentsCount, index;
    printf("Specify number of students (integer expected)... ");
    scanf("%lu", &studentsCount);

    Student students[studentsCount];

    for(index = 0; index < studentsCount; index++) {
        printf("Specify student name, enrollment number and phone number for student %lu (string, number, number expected; seperated by spaces)...", index + 1);
        scanf("%s %ld %ld", students[index].name, &students[index].enrollNum, &students[index].phoneNum);
    }

    puts("\nGenerating list of students...\n");

    for(index = 0; index < studentsCount; index++) {
        printf("|%s|%ld|%ld|", students[index].name, students[index].enrollNum, students[index].phoneNum);
    }

    return 0;
}