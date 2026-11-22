#include <stdio.h>

double calculateBill(double units) {
    if (units <= 100)
        return units * 5.0;
    else if (units <= 200)
        return 100 * 5.0 + (units - 100) * 6.0;
    else
        return 100 * 5.0 + 100 * 6.0 + (units - 200) * 8.0;
}

double calculateVAT(double charge) {
    return charge * 0.05;
}

void displayBill(int id, char name[], double units, double charge, double vat) {
    printf("\n------ Electricity Bill ------\n");
    printf("Customer ID       : %d\n", id);
    printf("Customer Name     : %s\n", name);
    printf("Units Consumed    : %.0f\n", units);
    printf("Electricity Charge: Tk %.2f\n", charge);
    printf("VAT (5%%)          : Tk %.2f\n", vat);
    printf("Final Bill        : Tk %.2f\n", charge + vat);
}

int main(void) {
    int id;
    char name[100];
    double units, charge, vat;

    printf("Enter customer ID: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid customer ID.\n");
        return 1;
    }

    printf("Enter customer name: ");
    if (scanf(" %99[^\n]", name) != 1) {
        printf("Invalid customer name.\n");
        return 1;
    }

    printf("Enter units consumed: ");
    if (scanf("%lf", &units) != 1) {
        printf("Invalid unit consumption.\n");
        return 1;
    }

    if (units < 0) {
        printf("Invalid unit consumption.\n");
        return 1;
    }

    charge = calculateBill(units);
    vat = calculateVAT(charge);
    displayBill(id, name, units, charge, vat);
    return 0;
}
