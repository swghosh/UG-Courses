#include<stdio.h>
#include<math.h>
// program to print square, cube and square root of numbers upto user input N
int main() {
    int n, square, cube, index;
    float squareroot;
    // take user input
    printf("Enter the limit (input for N) -> ");
    scanf("%d", &n);
    // print square, cube, squareroot of numbers
    for(index = 1; index <= n; index++) {
        square = (int)pow(index, 2);
        cube = (int)pow(index, 3);
        squareroot = (float)sqrt(index);
        printf("%d square = %d, %d cube = %d, %d square root = %f.\n", index, square, index, cube, index, squareroot);
    }
    return 0;
}