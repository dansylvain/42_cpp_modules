TARGET = interface

CXX = g++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror \
			-g

SRC =	main.cpp \
		AMateria.cpp \
		Ice.cpp Cure.cpp \
		Character.cpp \
		MateriaSource.cpp \
		Ground.cpp \
		test_one.cpp \
		test_two.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

all: design $(TARGET)

design:
	@echo "\033[0;32m"
	@cat mfile_design
	@echo "\033[0m"

fclean: clean
	rm	-f	$(TARGET) 

re:	fclean	all

.PHONY: all clean