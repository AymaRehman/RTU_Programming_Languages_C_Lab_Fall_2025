// week5_task4_struct_binary_io.c
// Task 4: Binary file I/O for Student struct
// Week 5 – Files & Modular Programming
// Student Name: Ayma Rehman
// Student ID: 241ADB165

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define FILENAME "student.bin"

typedef struct {
  char name[MAX_NAME_LEN];
  int age;
  float gpa;
} Student;

// Function prototypes
void save_student_binary(Student s, const char *filename);
Student load_student_binary(const char *filename);

int main(void) {
  Student s1;
  strcpy(s1.name, "Alice");
  s1.age = 21;
  s1.gpa = 3.75f;

  printf("Saving student in binary format...\n");
  save_student_binary(s1, FILENAME);

  printf("Loading student from binary file...\n");
  Student s2 = load_student_binary(FILENAME);

  printf("Loaded student: %s, %d, GPA %.2f\n", s2.name, s2.age, s2.gpa);

  // Compare file sizes
  FILE *fp = fopen(FILENAME, "rb");
  if (fp) {
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fclose(fp);
    printf("Binary file size: %ld bytes\n", size);
  }

  return 0;
}

void save_student_binary(Student s, const char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (!fp) {
    perror("Error opening file for writing");
    exit(1);
  }

  fwrite(&s, sizeof(Student), 1, fp);
  fclose(fp);
}

Student load_student_binary(const char *filename) {
  Student s;
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    perror("Error opening file for reading");
    exit(1);
  }

  fread(&s, sizeof(Student), 1, fp);
  fclose(fp);
  return s;
}
