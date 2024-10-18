#include<stdio.h>
int main() {
    char operator;
    double num1, num2;
    
    // Display the operation options
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);
    
    // Input numbers for the operation
    printf("Enter two operands: ");
    scanf("%lf %lf", &num1, &num2);
    
    switch (operator) {
        case '+':
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 != 0)
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
            else
                printf("Error! Division by zero.\n");
            break;
        default:
            printf("Error! Operator is not correct.\n");
            break;
    }

    return 0;
}
