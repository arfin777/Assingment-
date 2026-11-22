#include <stdio.h>

 

struct Patient {

    int id;

    char name[50];

    int age;

    char disease[50];

    double fee;

};

 

int main(void) {

    struct Patient p[100];

    int n;

    double total = 0.0;

 

    printf("Enter number of patients: ");

    scanf("%d", &n);

    if (n < 1 || n > 100) {

        printf("Enter patient count from 1 to 100.\n");

        return 1;

    }

 

    for (int i = 0; i < n; i++) {

        printf("Patient %d (ID name age disease fee): ", i + 1);

        scanf("%d %49s %d %49s %lf",

              &p[i].id, p[i].name, &p[i].age,

              p[i].disease, &p[i].fee);

        total += p[i].fee;

    }

 

    printf("\n%-5s %-10s %-6s %-12s %10s\n",

           "ID", "Name", "Age", "Disease", "Fee");

    for (int i = 0; i < n; i++) {

        printf("%-5d %-10s %-6d %-12s %10.2f\n",

               p[i].id, p[i].name, p[i].age,

               p[i].disease, p[i].fee);

    }

 

    printf("\nTotal consultation fees collected = Tk %.2f\n", total);

    return 0;

}

