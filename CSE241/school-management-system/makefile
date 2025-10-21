# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Source files
SRCS = main.cpp SchoolManagerSystem.cpp Student.cpp Course.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = main.out

# Default target
all: $(EXEC)

# Link object files to create executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the executable
run: $(EXEC)
	./$(EXEC)

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(EXEC)
