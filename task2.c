#include <stdio.h>

 

int calculateTotal(int marks[], int n) {

    int total = 0;

    for (int i = 0; i < n; i++)

        total += marks[i];

    return total;

}

 

double calculateAverage(int total, int n) {

    return (double) total / n;

}

 

void calculateGrade(double avg, char grade[], double *gpa) {

    if (avg >= 80)      { grade[0] = 'A'; grade[1] = '+'; *gpa = 4.00; }

    else if (avg >= 70) { grade[0] = 'A'; grade[1] = ' '; *gpa = 3.50; }

    else if (avg >= 60) { grade[0] = 'A'; grade[1] = '-'; *gpa = 3.00; }

    else if (avg >= 50) { grade[0] = 'B'; grade[1] = ' '; *gpa = 2.50; }

    else if (avg >= 40) { grade[0] = 'C'; grade[1] = ' '; *gpa = 2.00; }

    else                { grade[0] = 'F'; grade[1] = ' '; *gpa = 0.00; }

    grade[2] = '\0';

}

 

void displayResult(char name[], int id, int total, double avg,

                   char grade[], double gpa, int fail) {

    printf("\n------ Student Result ------\n");

    printf("Name    : %s\nID      : %d\n", name, id);

    printf("Total   : %d\nAverage : %.2f\n", total, avg);

    printf("Grade   : %s\nGPA     : %.2f\n", grade, gpa);

    printf("Result  : %s\n", fail ? "Fail" : "Pass");

}

 

int main(void) {

    char name[100], grade[3];

    int id, marks[5], fail = 0;

    int total;

    double avg, gpa;

 

    printf("Enter student name: ");

    scanf(" %99[^\n]", name);

    printf("Enter student ID: ");

    scanf("%d", &id);

    printf("Enter marks of 5 subjects: ");

    for (int i = 0; i < 5; i++) {

        scanf("%d", &marks[i]);

        if (marks[i] < 0 || marks[i] > 100) {

            printf("Invalid mark. Marks must be 0 to 100.\n");

            return 1;

        }

        if (marks[i] < 40) fail = 1;

    }

 

    total = calculateTotal(marks, 5);

    avg = calculateAverage(total, 5);

    calculateGrade(avg, grade, &gpa);

    displayResult(name, id, total, avg, grade, gpa, fail);

    return 0;

}