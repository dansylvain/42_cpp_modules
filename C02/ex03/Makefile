TARGET = bsp

CXX = g++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp bsp.cpp Fixed.cpp Point.cpp 

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

all: $(TARGET)

fclean: clean
	rm	-f	$(TARGET) 

re:	fclean	all

.PHONY: all clean