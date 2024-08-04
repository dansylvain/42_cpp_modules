NAME_INTERFACE = interface
NAME_EXEC = exec

CXX = g++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -g

SRC_INTERFACE =	main.cpp \
				Terminal.cpp \
	   			

SRC_EXEC =	exec.cpp \
			utils.cpp \
			AMateria.cpp \
			Ice.cpp Cure.cpp \
			Character.cpp \
			ICharacter.cpp \
			MateriaSource.cpp \
			test_one.cpp \
			test_two.cpp \
			test_three.cpp \
			test_four.cpp \
			Terminal.cpp 

OBJS_INTERFACE = $(SRC_INTERFACE:.cpp=.o)
OBJS_EXEC = $(SRC_EXEC:.cpp=.o)

# Fichier marqueur pour l'animation
DESIGN_MARKER = .design_running

# Règle principale
all: $(NAME_EXEC) $(NAME_INTERFACE)

# Règle pour afficher le motif en arrière-plan, si nécessaire
$(DESIGN_MARKER):
	clear
	@bash generateGradient.cpp &
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
