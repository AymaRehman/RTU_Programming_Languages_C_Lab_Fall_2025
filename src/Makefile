# Makefile for Week 5 - Files & Modular Programming
CC = gcc
CFLAGS = -Wall

# Task executables
TASK1 = week5_task1_file_io
TASK2 = week5_task2_struct_save_load
TASK3 = week5_task3_student_management_system
TASK4 = week5_task4_struct_binary_io

all: $(TASK1) $(TASK2) $(TASK3) $(TASK4)

$(TASK1): $(TASK1).c
	$(CC) $(CFLAGS) $< -o $@

$(TASK2): $(TASK2).c
	$(CC) $(CFLAGS) $< -o $@

$(TASK3): $(TASK3).c
	$(CC) $(CFLAGS) $< -o $@

$(TASK4): $(TASK4).c
	$(CC) $(CFLAGS) $< -o $@

run1: $(TASK1)
	./$(TASK1)

run2: $(TASK2)
	./$(TASK2)

run3: $(TASK3)
	./$(TASK3)

run4: $(TASK4)
	./$(TASK4)

clean:
	rm -f $(TASK1) $(TASK2) $(TASK3) $(TASK4)
