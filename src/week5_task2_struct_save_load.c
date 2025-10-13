// week5_task2_struct_save_load.c
// Task 2: Save and load structured records from a file
// Week 5 – Files & Modular Programming
// TODO: Complete function implementations and file handling logic.

// Student Name: Ayma Rehman
// Student ID: 241ADB165

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
} Student;

// Function prototypes
void save_student(Student s, const char *filename);
Student load_student(const char *filename);

int main(void) {
    Student s1;
    strcpy(s1.name, "Alice");
    s1.age = 21;
    s1.gpa = 3.75f;

    const char *filename = "student.txt";

    printf("Saving student to file...\n");
    save_student(s1, filename);

    printf("Loading student from file...\n");
    Student s2 = load_student(filename);

    printf("Loaded student: %s, %d, GPA %.2f\n", s2.name, s2.age, s2.gpa);

    return 0;
}

// TODO: Implement save_student()
// Open file for writing, check errors, write fields, then close file
void save_student(Student s, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        exit(1);
    }

    // Save in simple text format: name age gpa
    fprintf(fp, "%s %d %.2f\n", s.name, s.age, s.gpa);

    fclose(fp);
}

// TODO: Implement load_student()
// Open file for reading, check errors, read fields, then close file
Student load_student(const char *filename) {
    Student s;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        exit(1);
    }

    // Read data in same order: name age gpa
    if (fscanf(fp, "%49s %d %f", s.name, &s.age, &s.gpa) != 3) {
        fprintf(stderr, "Error reading data from file.\n");
        fclose(fp);
        exit(1);
    }

    fclose(fp);
    return s;
}
