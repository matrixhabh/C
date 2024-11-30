#include <stdio.h>

int main() {
    int num, i, factorial;

    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Error: Factorial of a negative number doesn't exist.\n");
        return 1;
    }

    factorial = 1;
    for (i = 1; i <= num; ++i) {
        factorial *= i;
    }
    printf("Factorial of %d (using for loop): %d\n", num, factorial);

    factorial = 1;
    i = 1;
    while (i <= num) {
        factorial *= i;
        ++i;
    }
    printf("Factorial of %d (using while loop): %d\n", num, factorial);

    factorial = 1;
    i = 1;
    do {
        factorial *= i;
        ++i;
    } while (i <= num);
    printf("Factorial of %d (using do-while loop): %d\n", num, factorial);

    return 0;
}