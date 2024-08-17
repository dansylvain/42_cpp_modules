NAME_INTERFACE = interface
NAME_EXEC = src/exec
CC = c++
OBJDIR = obj
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc
SRC_INTERFACE =	src/main.cpp \
				src/Terminal.cpp \
	   			src/utils.cpp \
				src/AMateria.cpp \
				src/Ice.cpp \
				src/Cure.cpp \
				src/Character.cpp \
				src/MateriaSource.cpp \
				src/test_three.cpp \

SRC_EXEC =	src/exec.cpp \
			src/utils.cpp \
			src/AMateria.cpp \
			src/Ice.cpp \
			src/Cure.cpp \
			src/Character.cpp \
			src/MateriaSource.cpp \
			src/test_three.cpp \
			src/Terminal.cpp 

OBJS_INTERFACE = $(patsubst src/%, $(OBJDIR)/%, $(SRC_INTERFACE:.cpp=.o))
OBJS_EXEC = $(patsubst src/%, $(OBJDIR)/%, $(SRC_EXEC:.cpp=.o))

DESIGN_MARKER = .design_running

all: $(NAME_EXEC) $(NAME_INTERFACE)

$(DESIGN_MARKER):
	clear
	@bash src/generateGradient.cpp &
	@touch $(DESIGN_MARKER)


$(NAME_INTERFACE): $(DESIGN_MARKER) $(OBJS_INTERFACE)
	@$(CC) $(CFLAGS) $(OBJS_INTERFACE) -o $(NAME_INTERFACE)

$(NAME_EXEC): $(DESIGN_MARKER) $(OBJS_EXEC)
	@$(CC) $(CFLAGS) $(OBJS_EXEC) -o $(NAME_EXEC)

$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME_EXEC) $(NAME_INTERFACE) $(DESIGN_MARKER)

re: fclean all

.PHONY: all clean fclean re
