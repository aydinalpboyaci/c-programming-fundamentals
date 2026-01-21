#include <stdio.h>

void collatzSequence(int n);

int main() {
    int num;
    printf("Enter a positive integer to start the Collatz sequence: ");
    if (scanf("%d", &num) != 1 || num <= 0) {
        printf("Invalid input!\n");
        return 1;
    }
    collatzSequence(num);
    return 0;
}

void collatzSequence(int n) {
    int steps = 0;
    printf("Collatz sequence for %d:\n", n);

    while (n != 1) {
        if (n % 2 == 0) n = n / 2;
        else n = (n * 3) + 1;

        steps++;

        printf("%d", n);
        if (n != 1) {
            printf(" -> ");
        }
    }
    printf("\nNumber of steps: %d\n", steps);
}