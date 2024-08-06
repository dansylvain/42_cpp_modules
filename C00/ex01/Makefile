NAME_PB = phonebook
NAME_EXEC = exec
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc
RM = rm -rf
OBJDIR = obj

SRC_PB =	src/Terminal.cpp \
	   		src/main.cpp \

SRC_EXEC =	src/Contact.cpp \
	   		src/PhoneBook.cpp \
	   		src/Terminal.cpp \
	   		src/exec.cpp \

OBJS_PB = $(patsubst src/%, $(OBJDIR)/%, $(SRC_PB:.cpp=.o))
OBJS_EXEC = $(patsubst src/%, $(OBJDIR)/%, $(SRC_EXEC:.cpp=.o))

DESIGN_MARKER = .design_running

all: $(NAME_PB) $(NAME_EXEC)

$(DESIGN_MARKER):
	@clear
	@bash src/generateGradient.cpp &
	@touch $(DESIGN_MARKER)

$(NAME_PB): $(DESIGN_MARKER) $(OBJS_PB)
	@$(CC) $(CFLAGS) $(OBJS_PB) -o $(NAME_PB)

$(NAME_EXEC):$(DESIGN_MARKER) $(OBJS_EXEC)
	@$(CC) $(CFLAGS) $(OBJS_EXEC) -o $(NAME_EXEC)

$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME_PB) $(NAME_EXEC) $(DESIGN_MARKER)


re: fclean all

.PHONY: all clean fclean re run