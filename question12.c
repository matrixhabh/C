#include <stdio.h>

int main() {
    int i;

    for (i = 1; i <= 100; i++) {
        if (i == 47 || i == 79) {
            continue; // Skip these numbers
        }
        printf("%d ", i);
    }

    return 0;
}