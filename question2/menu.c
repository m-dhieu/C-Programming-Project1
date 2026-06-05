#include <stdio.h>

/*
Menu-driven calculator using loops, conditionals, and functions.
Allows user to perform basic arithmetic until they choose to exit.
*/

// function declarations
void menu();
int getChoice();
int getNumber(char* prompt);
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
int validChoice(int choice);
void displayResult(char* operation, float result);

int main() {
    int choice;
    int num1, num2;
    float res;

    while (1) {
        menu();
        choice = getChoice();

        if (choice == 5) {
            printf("Exiting ...\n");
            break;
        }

        if (!validChoice(choice)) {
            printf("Invalid choice! Please select 1-5.\n");
            continue;
        }

        num1 = getNumber("Enter first number:");
        num2 = getNumber("Enter second number:");

        switch (choice) {
            case 1:
                res = add(num1, num2);
                displayResult("Sum", res);
                break;

            case 2:
                res = subtract(num1, num2);
                displayResult("Difference", res);
                break;

            case 3:
                res = multiply(num1, num2);
                displayResult("Product", res);
                break;

            case 4:
                if (num2 == 0) {
                    printf("Error: Cannot divide by zero!\n");
                    continue;
                }
                res = divide(num1, num2);
                displayResult("Quotient", res);
                break;
        }
    }

    return 0;
}

// menu options
void menu() {
    printf("\nCalculator Menu :)\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Exit\n");
}

int getChoice() {
    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);
    return choice;
}

int getNumber(char* prompt) {
    int num;
    printf("%s ", prompt);
    scanf("%d", &num);
    return num;
}

// operations
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    return (float)a / b;
}

// validate input
int validChoice(int choice) {
    return (choice >= 1 && choice <= 5);
}

// display result
void displayResult(char* operation, float result) {
    printf("Result: %s = %.2f\n", operation, result);
}

