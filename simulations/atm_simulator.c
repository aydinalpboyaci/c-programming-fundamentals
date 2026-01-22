#include <stdio.h>

/* NOTE: Buffer is used with fgets and sscanf
to prevent infinite loops caused by invalid (non-integer) inputs.*/

int deposit(int currentBalance) {
    char buffer[100];
    int amount;
    printf("Enter an amount to deposit: ");
    fgets(buffer, sizeof(buffer), stdin);
    if (sscanf(buffer, "%d", &amount) != 1 || amount <= 0) {
        printf("Invalid amount to deposit! Please try again.\n");
        return currentBalance;
    }
    printf("Deposit successful! +%d $ added.\n", amount);
    return currentBalance + amount;
}


int withdraw(int currentBalance) {
    char buffer[100];
    int amount;
    printf("Enter amount for withdraw: ");
    fgets(buffer, sizeof(buffer), stdin);
    if (sscanf(buffer, "%d", &amount) != 1 || amount <= 0) {
        printf("Invalid amount for withdraw!\n");
    } else if (amount > currentBalance) {
        printf("Balance insufficiency! Your current balance: %d $\n", currentBalance);
    } else {
        currentBalance -= amount;
        printf("Withdraw process is done. -%d $ taken.\n", amount);
    }
    return currentBalance;
}


void atmSimulator() {
    int choice;
    int balance = 1000;
    char buffer[100];

    do {
        printf("\n--- ATM SIMULATOR ---\n");
        printf("--- MENU ---\n");
        printf(" 1-Check Balance\n 2-Deposit\n 3-Withdraw\n 4-Exit\n");
        printf("Welcome, what would you like to do? ");

        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d", &choice) != 1) {
            printf("Error: Please choose a valid number (1-4).\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Your current balance: %d $\n", balance);
                break;
            case 2:
                balance = deposit(balance);
                break;
            case 3:
                balance = withdraw(balance);
                break;
            case 4:
                printf("See you again! \n");
                break;
            default:
                printf("You can only choose 1-2-3-4\n");
                break;
        }
    } while (choice != 4);
}

int main() {
    atmSimulator();
    return 0;
}