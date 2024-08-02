TARGET = interface

CXX = g++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -g

SRC = main.cpp \
	AMateria.cpp \
	Ice.cpp Cure.cpp \
	Character.cpp \
	MateriaSource.cpp \
	test_one.cpp \
	test_two.cpp

# Fichier marqueur pour l'animation
DESIGN_MARKER = .design_running

# Règle principale
all: $(TARGET)

# Règle pour afficher le motif en arrière-plan, si nécessaire
$(DESIGN_MARKER):
	clear
	@bash generateGradient.cpp &
	@touch $(DESIGN_MARKER)

# Règle pour compiler le projet
$(TARGET): $(SRC) $(DESIGN_MARKER)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Nettoyage
fclean: clean
	rm -f $(TARGET)
	@rm -f $(DESIGN_MARKER)  # Supprimer le fichier marqueur après compilation

# Recompile tout après nettoyage
re: fclean all

# Dépendances pour les cibles
.PHONY: all clean re
