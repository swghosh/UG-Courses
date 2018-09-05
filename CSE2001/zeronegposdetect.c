#include <stdio.h>

int main() {
    int number;
    printf("Specify a number. (integer expected) > ");
    scanf("%d", &number);
    if(number > 0) {
        puts("Positive number found.");
    }
    else if(number < 0) {
        puts("Negative number found.");
    }
    else {
        puts("Zero found.");
    }
    return 0;
}