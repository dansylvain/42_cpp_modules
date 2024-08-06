NAME = sed
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc #-g
RM = rm -rf
OBJDIR = obj
SRC =	src/main.cpp \
		src/Utils.cpp
		
OBJS = $(patsubst src/%, $(OBJDIR)/%, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR) *.replace

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re run