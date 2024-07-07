# Example Makefile for a program with many .c modules
# make: build count executable program
# make clean: clean-up all built files

all : myprog

 To create the executable file count we need the object files
# main.o, foo.o, and bar.o:
myprog : main.o foo.o bar.o
	gcc -o myprog main.o foo.o bar.o

# To create the object file main.o, we need the source
# files main.c, foo.h, and bar.h:
main.o : foo.h bar.h main.c
	gcc -c main.c

foo.o : foo.h foo.c
	gcc -c foo.c

bar.o : bar.h bar.c
	gcc -c bar.c

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files
clean : 
	rm -f myprog *.o *~

