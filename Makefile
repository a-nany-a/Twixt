CC = gcc
CFLAGS = -Wall -Wextra -O2

OBJ = main.o board.o game.o handling.o

twixt: $(OBJ)
	$(CC) $(CFLAGS) -o course_project $(OBJ)

main.o: main.c board.h game.h handling.h
	$(CC) $(CFLAGS) -c main.c

board.o: board.c board.h
	$(CC) $(CFLAGS) -c board.c

game.o: game.c game.h board.h
	$(CC) $(CFLAGS) -c game.c

handling.o: handling.c handling.h board.h
	$(CC) $(CFLAGS) -c handling.c

clean:
	rm -f *.o course_project

