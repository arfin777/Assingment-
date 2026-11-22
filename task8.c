#include <stdio.h>

 

struct Employee {

    int id;

    char name[50];

    double basic, houseRent, medical, gross;

};

 

int main(void) {

    struct Employee e[100];

    int n;

 

    printf("Enter number of employees: ");

    scanf("%d", &n);

    if (n < 1 || n > 100) {

        printf("Enter employee count from 1 to 100.\n");

        return 1;

    }

 

    for (int i = 0; i < n; i++) {

        printf("Employee %d (ID name basic house-rent medical): ", i + 1);

        scanf("%d %49s %lf %lf %lf",

              &e[i].id, e[i].name, &e[i].basic,

              &e[i].houseRent, &e[i].medical);

        e[i].gross = e[i].basic + e[i].houseRent + e[i].medical;

    }

 

    printf("\n%-6s %-10s %12s %12s %10s %12s\n",

           "ID", "Name", "Basic", "HouseRent", "Medical", "Gross");

    for (int i = 0; i < n; i++) {

        printf("%-6d %-10s %12.2f %12.2f %10.2f %12.2f\n",

               e[i].id, e[i].name, e[i].basic,

               e[i].houseRent, e[i].medical, e[i].gross);

    }

    return 0;

}