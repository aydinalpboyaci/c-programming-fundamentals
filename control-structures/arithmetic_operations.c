#include <stdio.h>
#include <stdbool.h>

int main() {
    int choice;
    float num, result = 0;
    bool isItFirst = true;
    bool itIsInvalid = false;

    printf("--- Multi-Number Calculator ---\n");
    printf("1-Sum\n2-Subtraction\n3-Multiplication\n4-Division\nSelection: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 4) {
        itIsInvalid = true;
    }

    if (!itIsInvalid) {
        printf("Enter numbers (Enter 0 to see the result):\n");

        while(true){
            printf("Number: ");
            scanf("%f", &num);

            if (num == 0) break;

            if(isItFirst){
                result = num;
                isItFirst = false;
                continue;
            }

            switch(choice){
                case 1: result += num; break;
                case 2: result -= num; break;
                case 3: result *= num; break;
                case 4:
                    if (num != 0) {
                        result /= num;
                    } else {
                        printf("Cannot divide by zero!\n");
                    }
                break;
            }
        }

        printf("\nFinal Result: %.2f \n", result);
    }
    else {
        printf("\nInvalid selection!\n");
    }

    return itIsInvalid;
}