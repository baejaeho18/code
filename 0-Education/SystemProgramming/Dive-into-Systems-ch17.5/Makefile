all : myprog

myprog : main.o foo.o bar.o
	gcc -o myprog main.o foo.o bar.o

main.o : foo.h bar.h main.c
	gcc -c main.c

foo.o : foo.h foo.c
	gcc -c foo.c

bar.o : bar.h bar.c
	gcc -c bar.c

clean : 
	rm myprog *.o

