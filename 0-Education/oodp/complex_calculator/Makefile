CC = g++ 
CFLAGS = -std=c++11 -Wall 
 
SRCS =$(wildcard *.cpp) 
 
OBJS = $(SRCS:.cpp=.o) 
 
TARGET = output.exe 
 
all: $(TARGET) 
 
$(TARGET): $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $^ 
 
%.o: %.cpp 
	$(CC) $(CFLAGS) -c -o $@ $< 
 
clean: 
	del $(OBJS) $(TARGET) 
