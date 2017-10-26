#include<stdio.h>
#include<math.h>

int main() {
	// take user input of 5 numbers
	int num;
	int index;
	int sum = 0, mean = 0, squaresum = 0;
	float sd = 0;
	for(index = 0; index < 5; index++) {
		printf("Enter number: ");
		scanf("%d", &num);
		sum = sum + num;
		squaresum = squaresum + (num * num);
	}
	// calculate mean
	mean = sum / 5;
	// print mean
	printf("Mean: %d\n", mean);
	// calculate standard deviation

	/* standard deviation for a set of values is:
		σ = √(Σ((x - mean) * (x - mean)) / (N - 1)) 
		therefore, by simplifying
		σ = √(Σ((x * x) + (mean * mean) - (2 * (x * mean)) / (N - 1))
		  = √((Σ(x * x) + Σ(mean * mean) - Σ(2 * (x * mean))) / (N - 1))
		  = √((squaresum + (N * (mean * mean)) - (2 * mean * Σx)) / (N - 1))
		  = √((squaresum + (N * (mean * mean)) - (2 * mean * sum)) / (N - 1))
		  = sqrt((squaresum + (N * (mean * mean)) - (2 * mean * sum)) / (N - 1))
		  where N = 5 as given
	*/

	sd = sqrt((squaresum + (5 * mean * mean) - (2 * mean * sum)) / 4);
	printf("Standard Deviation: %f\n", sd);
	return 0;
}
