#include <stdio.h>

int hcf(int a, int b) {
    if (b < a) return hcf(b, a);
    int remainder = b % a;
    if(remainder == 0) {
        return a;
    }
    else {
        return hcf(b % a, a);
    }
}

int lcm(int a, int b) {
    return (a * b) / hcf(a, b);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int hVal = hcf(a, b);
    int lVal = lcm(a, b);
    printf("HCF %d\nLCM %d\n", hVal, lVal);
    return 0;
}

