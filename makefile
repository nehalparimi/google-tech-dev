CC = g++
CFLAGS = -Wall

CUR = sum_numbers.cpp

main: $(CUR)
	$(CC) $(CUR) -o main -std=c++11 $(CFLAGS)
