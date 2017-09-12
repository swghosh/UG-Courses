#include<stdio.h>
int main() {
	int principal, time;
	float rate;
	printf("Enter principal amount: Rs.");
	scanf("%d", &principal);
	printf("Enter rate percentage: ");
	scanf("%f", &rate);
	printf("Enter time in years: ");
	scanf("%d", &time);
	float simpleInterest = (principal * rate * time) / 100;
	printf("Simple interest is %f.\n", simpleInterest);
}
