CC = g++
CFLAGS = -Wall

CUR = can-balance.cpp

main: $(CUR)
	$(CC) $(CUR) -o main -std=c++11 $(CFLAGS)
