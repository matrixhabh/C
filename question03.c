#include <stdio.h>

int main() {
    float percentage;

    printf("Enter the percentage: ");
    scanf("%f", &percentage);

    if (percentage >= 70) {
        printf("Class: Distinction\n");
    } else if (percentage >= 60 && percentage < 70) {
        printf("Class: First Class\n");
    } else if (percentage >= 50 && percentage < 60) {
        printf("Class: Second Class\n");
    } else {
        printf("Class: Fail\n");
    }

    return 0;
}