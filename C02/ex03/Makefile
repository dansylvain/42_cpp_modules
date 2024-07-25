TARGET = bsp

CXX = g++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp Fixed.hpp Fixed.cpp Point.hpp Point.cpp bsp.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

all: $(TARGET)

fclean: clean
	rm	-f	$(TARGET) 

re:	fclean	all

.PHONY: all clean