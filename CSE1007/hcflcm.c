#include <stdio.h>

/* function to get the hcf of two numbers */
int hcf(int a, int b) {
    // if b is greater than a hcf b, a is found instead of a, b for correct division
    if (b < a) return hcf(b, a);
    // find the remainder found by dividing b / a
    int remainder = b % a;
    // if b is completely divisible by a, a is returned as hcf
    if(remainder == 0) {
        return a;
    }
    // else the hcf of remainder and a is to be found (recursion)
    else {
        return hcf(remainder, a);
    }
}

/* function to get the lcm of two numbers */
int lcm(int a, int b) {
    // lcm is product of a, b divided by hcf of the two numbers
    return (a * b) / hcf(a, b);
}

/* main method that is to be executed at runtime */
int main() {
    int a, b;
    // take user input
    scanf("%d %d", &a, &b);
    // calculate hcf, lcm
    int hVal = hcf(a, b);
    int lVal = lcm(a, b);
    // print hcf, lcm
    printf("HCF %d\nLCM %d\n", hVal, lVal);
    return 0;
}

