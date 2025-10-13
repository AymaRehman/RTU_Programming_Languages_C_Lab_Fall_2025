// week5_task1_file_io.c
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
// TODO: Fill in the missing parts marked below.

// Student Name: Ayma Rehman
// Student ID: 241ADB165

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char filename[100] = "data.txt";
    char line[256];

   int line_count = 0;

    // TODO: 1. Open file for writing (mode = "w")
    fp = fopen(filename, "w");

    // TODO: 2. Check if file opened successfully
    if (fp == NULL) {
        perror("Error opening file for writing");
        return 1;  // Exit program if file can't be opened
    }

    printf("Writing lines to %s...\n", filename);

    // TODO: 3. Write 2–3 lines of text to the file using fprintf()
    fprintf(fp, "Hello, file I/O in C!\n");
    fprintf(fp, "This is another line.\n");
    fprintf(fp, "File handling is easy once you get used to it.\n");

    // TODO: 4. Close the file
    fclose(fp);

    // TODO: 5. Open file again for reading (mode = "r")
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    printf("Reading contents:\n");

    // TODO: 6. Use fgets() in a loop to read and print each line to the console
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        line_count++;
    }

    // TODO: 7. Close the file
    fclose(fp);

    // BONUS: count number of lines read
    printf("\nTotal lines read: %d\n", line_count);

    return 0;
}
