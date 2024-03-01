@echo off
REM Usage: bmake.bat <path>

set "path=%1"

REM Generate Makefile
    echo CC = g++ > Makefile
    echo CFLAGS = -std=c++11 -Wall >> Makefile
    echo. >> Makefile
    echo SRCS =$(wildcard *.cpp) >> Makefile
    echo. >> Makefile
    echo OBJS = $(SRCS:.cpp=.o) >> Makefile
    echo. >> Makefile
    echo TARGET = output.exe >> Makefile
    echo. >> Makefile
    echo all: $(TARGET) >> Makefile
    echo. >> Makefile
    echo $(TARGET): $(OBJS) >> Makefile
    echo.	$(CC) $(CFLAGS) -o $@ $^^ >> Makefile
    echo. >> Makefile
    echo %%.o: %%.cpp >> Makefile
    echo.	$(CC) $(CFLAGS) -c -o $@ $^< >> Makefile
    echo. >> Makefile
    echo clean: >> Makefile
    echo.	del $(OBJS) $(TARGET) >> Makefile


echo Makefile generated successfully!