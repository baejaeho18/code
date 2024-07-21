CC = gcc
TARGET = myprog
OBJS = main.o foo.o bar.o

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^

.c.o :
	$(CC) -c -o $@ $<

clean : 
	rm -f myprog *.o *~

test: $(TARGET)
	./$(TARGET)
