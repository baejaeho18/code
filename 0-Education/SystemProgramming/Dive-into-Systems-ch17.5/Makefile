
CC = gcc # defines the compiler
TARGET = myprog
OBJS = main.o foo.o bar.o
CFLAGS = -g -Wall # defines compiler flags
#CPPFLAGS = # defines preprocessor flags

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o : foo.h bar.h main.c
	$(CC) -c main.c

foo.o : foo.h foo.c
	$(CC) -c foo.c

bar.o : bar.h bar.c
	$(CC) -c bar.c

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files
clean : 
	rm -f myprog *.o *~

