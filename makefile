# compilator
CXX = g++

# compile flags
CXXFLAGS = -std=c++11 -Wall

# filename
TARGET = program

# source files
SRCS = matrix.cpp

# header files
HDRS = matrix.header

# object files
OBJS = $(SRCS:.cpp=.o)

# deafault rule ("make")
all: $(TARGET)

# linking object files 
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule for each .o file that depends on .cpp and .h
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# cleaning project ('make clean')
clean:
	rm -f $(OBJS) $(TARGET)

# Mark "clean" and "all" rules as not creating files
.PHONY: all clean
