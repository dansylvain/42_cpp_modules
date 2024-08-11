NAME = identifyRealType
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc -g
RM = rm -rf

OBJDIR = obj

SRC = 	src/main.cpp \
		src/Base.cpp \
		src/A.cpp \
		src/B.cpp \
		src/C.cpp \

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
	$(RM) $(OBJDIR)

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re