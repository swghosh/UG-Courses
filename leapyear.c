#include<stdio.h>

int main() {
	// take user input year
	int year;
	puts("Enter a year: ");
	scanf("%d", &year);
	// test for leap year
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		puts("Leap year detected.");
	}
	else {
		puts("Leap year not detected.");
	}
	return 0;
}
