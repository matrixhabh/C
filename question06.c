#include <stdio.h>

int main() {
    int i;

    printf("Odd numbers between 20 and 40 are:\n");
    for (i = 21; i <= 39; i += 2) {
        printf("%d ", i);
    }

    return 0;
}