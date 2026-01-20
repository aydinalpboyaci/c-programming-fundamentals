#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void printDivisors(int value);

int main() {
    int number;
    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input!\n");
        return 1;
    }
    printDivisors(number);
    return 0;
}

void printDivisors(int value) {
    if(value == 0){
        printf("Every integer can divide 0\n");
        return;
    }

    int absValue = abs(value);
    int limit = (int)sqrt(absValue);

    printf("All divisors: \n");

    printf("Positive: ");

    for(int i = 1; i <= limit; i++){
        if(absValue % i == 0) printf("%d ", i);
    }

    for(int i = limit; i >= 1; i--){
        if(absValue % i == 0 && (absValue / i) != i){
            printf("%d ", absValue / i);
        }
    }

    printf("\nNegative: ");

    for(int i = 1; i <= limit; i++){
        if (absValue % i == 0) printf("%d ", -i);
    }
    for(int i = limit; i >= 1; i--){
        if(absValue % i == 0 && (absValue / i) != i){
            printf("%d ", -(absValue / i));
        }
    }
    printf("\n");
}