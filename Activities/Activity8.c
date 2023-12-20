#include <stdio.h>

// Pseudocode:
// 1. Prompt and input 3 values from the user
// 2. if num1 is greater than or equal to num2 or num3, set max to num1
// 3. if num2 is greater than num3, set max to num2
// 4. else set max to num3
// 5. print out max to user

int main() {
	double num1, num2, num3, max;

	//ask user for input
	printf("Enter the first number: ");
	scanf("%lf", &num1);

	printf("Enter the second number: ");
	scanf("%lf", &num2);

	printf("Enter the third number: ");
	scanf("%lf", &num3);

	//calculate the max
    if (num1 >= num2) {
        if (num1 >= num3) {
            max = num1;
        }
    } else if (num2 >= num3) {
        max = num2;
    } else {
        max =  num3;
    }

    printf("The max number is: %g\n", max);

	return 0;
}