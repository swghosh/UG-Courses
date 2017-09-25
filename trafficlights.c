#include<stdio.h>

// program to take user input of traffic light colour and print signal name
int main() {
	char color;
	// take user input
	printf("Enter traffic light color (r | g | y): ");
	scanf("%c", &color);
	// print signal name
	switch(color) {
		case 'r':
			printf("Stop\n");
			break;
		case 'g':
			printf("Go\n");
			break;
		case 'y':
			printf("Wait\n");
			break;
		default:
			printf("Invalid color\n");
	}
	return 0;
}

