#include <stdio.h>

/*
Demonstrates functions and recursion using factorial,
fibonacci, & power calculations.
*/

void menu();
int getChoice();
int getNumber(char* prompt);
int factorial(int n);
int fibonacci(int n);
int power(int base, int exponent);
void displayResult(char* operation, int number, int result);
int validChoice(int choice);

int main() {
    int choice, number, result;

    menu();
    choice = getChoice();

    // validate menu choice
    if (!validChoice(choice)) {
        printf("Invalid choice!\n");
        return 1;
    }

    number = getNumber("Enter a positive number: ");

    // operation
    if (choice == 1) {
        result = factorial(number);
        displayResult("Factorial", number, result);
    }
    else if (choice == 2) {
        result = fibonacci(number);
        displayResult("Fibonacci", number, result);
    }
    else if (choice == 3) {
        int exponent = getNumber("Enter exponent: ");
        result = power(number, exponent);
        displayResult("Power", number, result);
    }

    return 0;
}

// menu options
void menu() {
    printf("\nMath Functions Menu :)\n");
    printf("1. Factorial\n");
    printf("2. Fibonacci\n");
    printf("3. Power\n");
    printf("Enter choice: ");
}

int getChoice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

// ensure +ve
int getNumber(char* prompt) {
    int num;

    printf("%s ", prompt);
    scanf("%d", &num);

    while (num < 0) {
        printf("Number must be positive. Try again: ");
        scanf("%d", &num);
    }

    return num;
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int power(int base, int exponent) {
    int result = 1;

    for (int i = 0; i < exponent; i++) {
        result = result * base;
    }

    return result;
}

// display result
void displayResult(char* operation, int number, int result) {
    printf("\nResult:\n");
    printf("%s of %d = %d\n", operation, number, result);
}

// validate choice
int validChoice(int choice) {
    return (choice >= 1 && choice <= 3);
}

