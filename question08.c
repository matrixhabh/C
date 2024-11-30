#include <stdio.h>

int main() {
    int i = 1;

    printf("Squares of numbers from 1 to 50:\n");
    while (i <= 50) {
        printf("%d^2 = %d\n", i, i * i);
        i++;
    }

    return 0;
}