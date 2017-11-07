#include <stdio.h>
#include <stddef.h>

#define NUMBER_OF_EMPLOYEES 5

int main(void) {
	int salaries[NUMBER_OF_EMPLOYEES],  salarySum;
	float averageSalary;
	salarySum = 0,  averageSalary = 0.0;
	// input salary of employees
	for(size_t index = 0; index < NUMBER_OF_EMPLOYEES; index++) {
		printf("Enter salary for employee number %lu: Rs.", (index + 1));
		scanf("%d", &salaries[index]);
		salarySum = salarySum + salaries[index];
	}
	// calculate salary sum
	averageSalary = salarySum / NUMBER_OF_EMPLOYEES;
	printf("Average salary of  Employees is Rs.%f.\n", averageSalary);
	return 0;
}
