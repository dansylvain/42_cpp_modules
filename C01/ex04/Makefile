NAME = sed
CC = c++
CFLAGS = 	-std=c++98 -Iinc \
			-Wall -Wextra -Werror 
RM = rm -rf

SRC =	main.cpp Utils.cpp
		
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re run