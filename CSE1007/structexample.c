#include <stdio.h>
#include <stddef.h>

int main(void) {

    struct student {
        char name[10];
        long int enrollNum;
        long int phoneNum;
    };
    
    size_t studentsCount, index;
    printf("Specify number of students (integer expected)... ");
    scanf("%lu", &studentsCount);

    struct student students[studentsCount];

    for(index = 0; index < studentsCount; index++) {
        printf("Specify student name, enrolment number and phone number for student %lu (string, number, number expected; seperated by spaces)...", index + 1);
        scanf("%s %ld %ld", students[index].name, &students[index].enrollNum, &students[index].phoneNum);
    }

    puts("\nGenerating list of students...\n");

    printf("|%25s|%12s|%10s|\n", "Name", "Enrolment #", "Phone #");
    puts("");

    for(index = 0; index < studentsCount; index++) {
        printf("|%25s|%12ld|%10ld|\n", students[index].name, students[index].enrollNum, students[index].phoneNum);
    }

    puts("");

    return 0;
}