# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11 -Wall -g
# Include directories
INCLUDES = -I.

# Source files
SRCS = AssassinDuck.cpp \
       Bird.cpp \
       BirdList.cpp \
       BirdNode.cpp \
       DetectiveGoose.cpp \
       DodoBird.cpp \
       Duck.cpp \
       Falcon.cpp \
       GGD.cpp \
       Goose.cpp \
       main.cpp \
       MorticianGoose.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable file
EXEC = Assignment5

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean up object files and executable
clean:
	del /Q $(OBJS) $(EXEC)

# Phony targets
.PHONY: all clean
