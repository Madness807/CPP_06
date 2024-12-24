# Nom de l'exécutable
NAME = Serializer

# Compilateur
CC = g++

# Flags de compilation
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Fichiers sources
SRC = main.cpp Serializer.cpp

# Règle par défaut
all: $(NAME)

# Règle pour construire l'exécutable
$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

# Règle pour nettoyer les fichiers compilés
clean:
	rm -f $(NAME)

# Règle pour recompiler le projet
re: clean all

# Règle pour éviter certains conflits de noms
.PHONY: all clean re