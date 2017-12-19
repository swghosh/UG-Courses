//  Pythagorean Triplets

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// function to check whether three side lengths of a triangle form a pythagorean triplet or not
bool isPythagoreanTriplet(int, int, int);
bool isPythagoreanTriplet(int a, int b, int c) {
    /* keep the third argument i.e. c to be highest
     * find the greatest and proceed recursively
     */
    if(a > c && a > b) return isPythagoreanTriplet(c, b, a);
    else if(b > c && b > a) return isPythagoreanTriplet(a, c, b);
    /* for three numbers [a, b, c] to be pythagorean triplets
     * c^2 = a^2 + b^2 should be true
     */
    else return (pow(c, 2) == (pow(a, 2) + pow(b, 2)));
}

int main(void) {
    // initialisations and user input
    int a, b, c;
    printf("Specify three sides of a triangle. (3 integers expected, seperated by spaces)... ");
    scanf("%d %d %d", &a, &b, &c);
    // test for pythogorean triplet and print appropriate message
    if(isPythagoreanTriplet(a, b, c)) {
        printf("%d, %d, %d form a pythagorean triplet. \n", a, b, c);
    }
    else {
        printf("%d, %d, %d does not form a pythagorean triplet. \n", a, b, c);
    }
    return 0;
}
