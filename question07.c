#include <stdio.h>

int main() {
    int i;

    printf("Numbers divisible by both 8 and 7 between 200 and 1500 are:\n");
    for (i = 200; i <= 1500; i++) {
        if (i % 8 == 0 && i % 7 == 0) {
            printf("%d ", i);
        }
    }

    return 0;
}