#include <stdio.h>

void calculateEvenOddSum(int A, int B);

int main() {
    int num1,num2;
    printf("Enter 2 positive integers for process: \n");
    if( (scanf("%d %d", &num1,&num2) !=2 ) || num1 <= 0 || num2<=0) { // !=2 stands for 2 valid inputs
        printf("Invalid Input!\n");
        return 1;
    }
    calculateEvenOddSum(num1,num2);
    return 0;
}

void calculateEvenOddSum(int A, int B) {
    if (A > B) {
        int temp = A;
        A = B;
        B = temp;
    }
    int evenSum = 0, oddSum = 0;
    for (int i = A; i <= B; i++) {
        if (i % 2 == 0) evenSum += i;
        else oddSum += i;
    }
    printf("\n--- Results ---\n");
    printf("Range: [%d, %d]\n", A, B);
    printf("Sum of Evens: %d\n", evenSum);
    printf("Sum of Odds:  %d\n", oddSum);
}