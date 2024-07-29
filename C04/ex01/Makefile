TARGET = burn

CXX = g++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp Dog.cpp Cat.cpp Animal.cpp WrongCat.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

all: $(TARGET)

fclean: clean
	rm	-f	$(TARGET) 

re:	fclean	all

.PHONY: all clean