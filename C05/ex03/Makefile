NAME = atLeastThisBeatsCoffee-making
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc -g
RM = rm -rf

OBJDIR = obj

SRC = 	src/main.cpp \
		src/Bureaucrat.cpp \
		src/AForm.cpp \
		src/ShrubberyCreationForm.cpp \
		src/RobotomyRequestForm.cpp \
		src/PresidentialPardonForm.cpp \
		src/Intern.cpp \
		src/utils.cpp

OBJS = $(patsubst src/%, $(OBJDIR)/%, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: src/%.cpp
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

wno: CFLAGS = -std=c++98 -Iinc -g
wno: $(NAME)

clean:
	$(RM) $(OBJDIR) *_shrubbery

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re