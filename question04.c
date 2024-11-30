#include <stdio.h>

int main() {
    float length, breadth;

    printf("Enter the length of the rectangle: ");
    scanf("%f", &length);

    printf("Enter the breadth of the rectangle: ");
    scanf("%f", &breadth);

    if (length == breadth) {
        printf("It is a square.\n");
    } else {
        printf("It is not a square.\n");
    }

    return 0;
}