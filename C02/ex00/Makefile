NAME = canon
CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror -Iinc
RM = rm -rf
OBJDIR = obj

SRC = 	src/main.cpp \
		src/Fixed.cpp

OBJS = $(patsubst src/%, $(OBJDIR)/%, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR)

fclean: clean 
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
