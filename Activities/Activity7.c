#include <stdio.h>

int main() {
	double num1, num2, num3, avg;

	//ask user for input
	printf("Enter the first number: ");
	scanf("%lf", &num1);

	printf("Enter the second number: ");
	scanf("%lf", &num2);

	printf("Enter the third number: ");
	scanf("%lf", &num3);

	//calculate the average
	avg = (num1 + num2 + num3) / 3;
	printf("The average is: %lf\n", avg);

	return 0;
}
