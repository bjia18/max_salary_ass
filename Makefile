CC = gcc
CFLAGS = -Wall -std=c99

all: test

max_salary_naive.o: max_salary_naive.c max_salary.h
	$(CC) $(CFLAGS) -c max_salary_naive.c

max_salary_fast.o: max_salary_fast.c max_salary.h
	$(CC) $(CFLAGS) -c max_salary_fast.c

test: max_salary_naive.o max_salary_fast.o
	$(CC) $(CFLAGS) -o test max_salary_naive.o max_salary_fast.o

clean:
	rm *.o test