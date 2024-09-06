NAME = span
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc -Wconversion -g
RM = rm -rf

OBJDIR = obj
DEPDIR = deps

SRC =	src/main.cpp \
		src/Span.cpp \
		src/utils.cpp


OBJS = $(patsubst src/%, $(OBJDIR)/%, $(SRC:.cpp=.o))
DEPS = $(patsubst src/%, $(DEPDIR)/%, $(SRC:.cpp=.d))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: src/%.cpp $(DEPDIR)/%.d
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(DEPDIR)/%.d: src/%.cpp
	@mkdir -p $(DEPDIR)
	@$(CC) $(CFLAGS) -M $< > $@.$$$$; \
	sed 's,\($(notdir $*)\.o\)[ :]*,$(OBJDIR)/\1 $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

wno: CFLAGS = -std=c++98 -Iinc -g
wno: $(NAME)

clean:
	$(RM) $(OBJDIR) $(DEPDIR) largeVector smallVector

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 

-include $(DEPS)
