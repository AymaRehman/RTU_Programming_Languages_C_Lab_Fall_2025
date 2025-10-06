/*
 * week4_3_struct_database.c
 * Author: Ayma Rehman
 * Student ID: 241ADB165
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Students will use malloc to allocate space for multiple Student records,
 *   then input, display, and possibly search the data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct Student with fields name, id, grade
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    int n;
    struct Student *students = NULL;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    // Allocate memory for n Student structs using malloc
    students = (struct Student *)malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read student data in a loop
    for (int i = 0; i < n; i++) {
        printf("\nEnter data for student %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", students[i].name); // Use fgets() if you want to allow spaces in names

        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("Grade: ");
        scanf("%f", &students[i].grade);
    }

    // Display all student records in formatted output
    printf("\n%-6s %-20s %-6s\n", "ID", "Name", "Grade");
    printf("----------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-6d %-20s %-6.2f\n", students[i].id, students[i].name, students[i].grade);
    }

    // Optional: Compute average grade
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += students[i].grade;
    }
    printf("\nAverage grade of class: %.2f\n", total / n);

    // Free allocated memory
    free(students);

    return 0;
}