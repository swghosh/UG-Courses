#include<stdio.h>
int main() {
	float n1;
	float n2;
	printf("Enter two numbers: ");
	scanf("%f %f", &n1, &n2);
	float sum = n1 + n2;
	float difference = n1 - n2;
	float product = n1 * n2;
	float quotient = n1 / n2;
	printf(" Sum = %f,\n Difference = %f,\n Product = %f,\n Quotient = %f\n", sum, difference, product, quotient);
	return 0;
}
