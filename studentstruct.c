#include <stdio.h>
#include <stddef.h>

int main(void) {
    // make a struct for students
    struct student {
        char name[10];
        long enrolNum;
        struct marks {
            int cs, cfe, hve, comn, fpd, ec, max;
        } marks;
    };
    #define STUDENT struct student

    // user input and array of students
    size_t studentsNum;
    printf("Specify how many student\'s details you want to enter? ... ");
    scanf("%lu", &studentsNum);
    STUDENT students[studentsNum];

    // user input of details
    puts("\nTaking students details...");
    size_t index;
    for(index = 0; index < studentsNum; index++) {
        printf("Specify name, enrolment number, marks - (ICS, CFE, HVE, COMN, FPD, EC), maximum marks for student number %lu (seperated by spaces; string, integer, integer, integer, integer, integer, integer, integer, integer expected)... ", index + 1);
        scanf("%s %12ld %d %d %d %d %d %d %d", students[index].name, &students[index].enrolNum, &students[index].marks.cs, &students[index].marks.cfe, &students[index].marks.hve, &students[index].marks.comn, &students[index].marks.fpd, &students[index].marks.ec, &students[index].marks.max);
    }

    // display student records
    printf("\nGenerating student records...\n|%12s|%12s|%7s|%7s|%7s|%7s|%7s|%7s|\n", "Enrol Number", "Name", "CS", "CFE", "HVE", "COMN", "FPD", "EC");
    for(index = 0; index < studentsNum; index++) {
        printf("|%12ld|%12s|%d / %d|%d / %d|%d / %d|%d / %d|%d / %d|%d / %d|\n", students[index].enrolNum, students[index].name, students[index].marks.cs, students[index].marks.max, students[index].marks.cfe, students[index].marks.max, students[index].marks.hve, students[index].marks.max, students[index].marks.comn, students[index].marks.max, students[index].marks.fpd, students[index].marks.max, students[index].marks.ec, students[index].marks.max);
    }

    return 0;
}