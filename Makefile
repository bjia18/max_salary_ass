CC = gcc
CFLAGS = -Wall -std=c99

all: test

max_salary_naive.o: max_salary_naive.c max_salary.h
	$(CC) $(CFLAGS) -c max_salary_naive.c

stress_test.o: stress_test.c max_salary.h
	$(CC) $(CFLAGS) -c stress_test.c

test: max_salary_naive.o stress_test.o
	$(CC) $(CFLAGS) -o test max_salary_naive.o stress_test.o

#test: max_salary_naive.c max_salary.h\
	$(CC) $(CFLAGS) max_salary_naive.c max_salary.h -o test

clean:
	rm *.o test