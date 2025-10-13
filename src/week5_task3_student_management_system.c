// week5_task3_student_management_system.c
// Task 3: Mini-project – Student management system with file persistence
// Week 5 – Files & Modular Programming
// TODO: Implement functions to load, save, add, and list students.

// Student Name: Ayma Rehman
// Student ID: 241ADB165

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define DATA_FILE "students.txt"

typedef struct {
    char name[NAME_LEN];
    int id;
    float gpa;
} Student;

// Function prototypes
int load_students(Student arr[]);
void save_students(Student arr[], int count);
void add_student(Student arr[], int *count);
void list_students(Student arr[], int count);

int main(void) {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    // Load existing data from file using load_students()
    count = load_students(students);

    do {
        printf("\n=== Student Management System ===\n");
        printf("1. List students\n");
        printf("2. Add student\n");
        printf("3. Save and Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                // Call list_students()
                list_students(students, count);
                break;
            case 2:
                // Call add_student()
                add_student(students, &count);
                break;
            case 3:
                // Call save_students() and exit loop
                save_students(students, count);
                printf("Data saved. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Implement load_students()
// Open DATA_FILE, read records until EOF, return number of records loaded
int load_students(Student arr[]) {
    FILE *fp = fopen(DATA_FILE, "r");
    if (fp == NULL) {
        printf("No existing data found. Starting fresh.\n");
        return 0;
    }

    int count = 0;
    while (fscanf(fp, "%49s %d %f", arr[count].name, &arr[count].id, &arr[count].gpa) == 3) {
        count++;
        if (count >= MAX_STUDENTS) break;
    }

    fclose(fp);
    printf("%d student(s) loaded from file.\n", count);
    return count; 
}
// Implement save_students()
// Write all students to DATA_FILE
void save_students(Student arr[], int count) {
    FILE *fp = fopen(DATA_FILE, "w");
    if (fp == NULL) {
        perror("Error saving data");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %d %.2f\n", arr[i].name, arr[i].id, arr[i].gpa);
    }

    fclose(fp);
}

// Implement add_student()
// Read input from user and append to array
void add_student(Student arr[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students. Array full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%49s", arr[*count].name);
    printf("Enter ID: ");
    scanf("%d", &arr[*count].id);
    printf("Enter GPA: ");
    scanf("%f", &arr[*count].gpa);

    (*count)++;
    printf("Student added successfully!\n");
}

// Implement list_students()
// Print all students in readable format
void list_students(Student arr[], int count) {
    if (count == 0) {
        printf("No students found.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (ID: %d, GPA: %.2f)\n", i + 1, arr[i].name, arr[i].id, arr[i].gpa);
    }
}