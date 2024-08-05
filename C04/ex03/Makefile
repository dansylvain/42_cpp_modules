NAME_INTERFACE = interface
NAME_EXEC = exec

CXX = g++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -g -Iinc

SRC_INTERFACE =	src/main.cpp \
				src/Terminal.cpp \
	   			

SRC_EXEC =	src/exec.cpp \
			src/utils.cpp \
			src/AMateria.cpp \
			src/Ice.cpp \
			src/Cure.cpp \
			src/Character.cpp \
			src/MateriaSource.cpp \
			src/test_three.cpp \
			src/Terminal.cpp 

OBJS_INTERFACE = $(SRC_INTERFACE:.cpp=.o)
OBJS_EXEC = $(SRC_EXEC:.cpp=.o)

# Fichier marqueur pour l'animation
DESIGN_MARKER = .design_running

# Règle principale
all: $(NAME_EXEC) $(NAME_INTERFACE)

# Règle pour afficher le motif en arrière-plan, si nécessaire
$(DESIGN_MARKER):
	clear
	@bash src/generateGradient.cpp &
	@touch $(DESIGN_MARKER)

# Règle pour compiler le projet
$(NAME_EXEC): $(SRC_EXEC) $(DESIGN_MARKER)
	@$(CXX) $(CXXFLAGS) $(SRC_EXEC) -o $(NAME_EXEC)

$(NAME_INTERFACE): $(SRC_INTERFACE) $(DESIGN_MARKER)
	@$(CXX) $(CXXFLAGS) $(SRC_INTERFACE) -o $(NAME_INTERFACE)
# Nettoyage
fclean: clean
	@rm -f $(NAME_EXEC)
	@rm -f $(DESIGN_MARKER)  # Supprimer le fichier marqueur après compilation

# Recompile tout après nettoyage
re: fclean all

# Dépendances pour les cibles
.PHONY: all clean re
