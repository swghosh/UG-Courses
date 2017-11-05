#include<stdio.h>
#include<math.h>
// main method that is to be executed
int main() {
    int a, b, c;
    float determinant, root1, root2;
    /* for a quadratic equation a x² + b x + c = 0
     * root1 = [-b + √(b² - 4 a c)] / 2 a
     * root2 = [-b - √(b² - 4 a c)] / 2 a
     */
    // input a, b, c
    printf("Quadratic Equation: a x² + b x + c = 0.\n");
    printf("Enter value of a -> ");
    scanf("%d", &a);
    printf("Enter value of b -> ");
    scanf("%d", &b);
    printf("Enter value of c -> ");
    scanf("%d", &c);
    // calculate determinant
    determinant = (b * b) - (4 * a * c);
    // in case of no real roots
    if(determinant < 0) {
        puts("No real roots.");
    }
    // in case of roots
    else {
        root1 = (-b + sqrt(determinant)) / (2 * a);
        root2 = (-b - sqrt(determinant)) / (2 * a);
        printf("The roots are %f and %f.\n", root1, root2);
    }
    return 0;
}