TARGET = interface

CXX = g++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

all: $(TARGET)

fclean: clean
	rm	-f	$(TARGET) 

re:	fclean	all

.PHONY: all clean