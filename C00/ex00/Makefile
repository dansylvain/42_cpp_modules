NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = megaphone.cpp

OBJS = $(SRC:.cpp=.o)

#DESIGN_MARKER = .design_running

all: $(NAME)

#$(DESIGN_MARKER):
	@#clear
	@#@bash generateGradient.cpp &
	@#@touch $(DESIGN_MARKER)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
