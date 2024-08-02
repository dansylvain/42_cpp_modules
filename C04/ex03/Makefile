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
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

all: design $(TARGET)

design:
	clear
	@bash generateGradient.sh &


fclean: clean
	rm	-f	$(TARGET) 

re:	fclean	all

.PHONY: all clean