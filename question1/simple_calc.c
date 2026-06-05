#include <stdio.h>

// ask user for 2 numbers & sum them to 2dp
int main() {
    float num1, num2, sum;

    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter second number: ");
    scanf("%f", &num2);

    sum = num1 + num2;

    printf("Sum: %.2f + %.2f = %.2f\n", num1, num2, sum);

    return 0;
}

