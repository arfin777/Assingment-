#include <stdio.h>

 

int checkBalance(double balance, double amount) {

    return balance >= amount;

}

 

int validateWithdrawal(int amount) {

    return amount > 0 && amount % 500 == 0;

}

 

double withdrawMoney(double balance, double amount) {

    return balance - amount;

}

 

void displayTransaction(int success, double amount, double balance) {

    if (success) {

        printf("\nTransaction Status : Successful\n");

        printf("Amount Withdrawn   : Tk %.0f\n", amount);

        printf("Remaining Balance  : Tk %.0f\n", balance);

    } else {

        printf("\nTransaction Status : Failed\n");

        printf("No money was deducted.\n");

        printf("Available Balance  : Tk %.2f\n", balance);

    }

}

 

int main(void) {

    double balance, amount;

    int success;

 

    printf("Enter account balance: ");

    if (scanf("%lf", &balance) != 1 || balance < 0) {
        printf("Invalid account balance.\n");
        return 1;
    }

    printf("Enter withdrawal amount: ");

    if (scanf("%lf", &amount) != 1 || amount <= 0 ||
        amount > 2147483647.0 || amount != (int)amount) {
        printf("Invalid withdrawal amount.\n");
        return 1;
    }

 

    success = validateWithdrawal((int)amount) &&

              amount == (int)amount &&

              checkBalance(balance, amount);

 

    if (success)

        balance = withdrawMoney(balance, amount);

 

    displayTransaction(success, amount, balance);

    return 0;

}
