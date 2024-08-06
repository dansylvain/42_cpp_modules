NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc #-g
RM = rm -rf

OBJDIR = obj

SRC = megaphone.cpp

OBJS = $(patsubst /%, $(OBJDIR)/%, $(SRC:.cpp=.o))

DESIGN_MARKER = .design_running

all: $(NAME)

$(DESIGN_MARKER):
	clear
	@bash generateGradient.cpp &
	@touch $(DESIGN_MARKER)

$(NAME): $(DESIGN_MARKER) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean 
	@$(RM) $(NAME) $(DESIGN_MARKER)

re: fclean all

.PHONY: all clean fclean re
