#include <stdio.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base case: factorial of 0 or 1 is 1
    } else {
        return n * factorial(n - 1); // Recursive call to calculate factorial
    }
}

int main() {
    int number;
    
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Please enter a positive integer.\n");
    } else {
        unsigned long long result = factorial(number);
        printf("Factorial of %d is: %llu\n", number, result);
    }

    return 0;
}
