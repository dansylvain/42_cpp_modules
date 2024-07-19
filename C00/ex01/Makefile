NAME_PB = phonebook
NAME_EXEC = exec
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc
RM = rm -rf

SRC_PB =	src/Terminal.cpp \
	   		main.cpp \

SRC_EXEC =	src/Contact.cpp \
	   		src/PhoneBook.cpp \
	   		src/Terminal.cpp \
	   		exec.cpp \

OBJS_PB = $(SRC_PB:.cpp=.o)
OBJS_EXEC = $(SRC_EXEC:.cpp=.o)

all: $(NAME_PB) $(NAME_EXEC)

$(NAME_PB): $(OBJS_PB)
	$(CC) $(CFLAGS) $(OBJS_PB) -o $(NAME_PB)

$(NAME_EXEC): $(OBJS_EXEC)
	$(CC) $(CFLAGS) $(OBJS_EXEC) -o $(NAME_EXEC)

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf $(OBJS_PB) $(OBJS_EXEC)

fclean: clean
	$(RM) $(NAME) $(NAME_EXEC)

re: fclean all

.PHONY: all clean fclean re run