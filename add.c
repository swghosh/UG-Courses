#include <stdio.h>

int main() {
	int intFno, intSno, intRes;
	printf("Please enter two integer numbers : \n");
	scanf("%d %d", &intFno, &intSno);
	intRes = intFno + intSno;
	printf("Sum of %d and %d is = %d \n", intFno, intSno, intRes);
	return 0;
}

