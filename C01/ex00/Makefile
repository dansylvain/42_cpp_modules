NAME = brainzz
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc
RM = rm -rf

OBJDIR = obj

SRC = src/main.cpp \
	src/Zombie.cpp

OBJS = $(patsubst src/%, $(OBJDIR)/%, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(OBJDIR)  # Crée le répertoire obj s'il n'existe pas
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
