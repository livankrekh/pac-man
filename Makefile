NAME1 = pac-man
SYSTEM = LINUX
CC = g++
SRC = src/main.cpp src/ft_strsplit.cpp src/viz.cpp src/pac.cpp src/ghost.cpp
FLAGS = -g -std=c++11 -O3 -fno-strict-aliasing
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system 
INCLUDE_SFML = -I SFML/include
SFML = -L SFML/lib

.PHONY: all re clean fclean

all: $(NAME1)

$(NAME1): $(SRC:.cpp=.o)
	$(CC) -o $(NAME1) $(SRC:.cpp=.o) $(FLAGS) $(SFML_FLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(FLAGS)

clean:
	rm -f $(SRC:.cpp=.o)

fclean: clean
	rm -f $(NAME1)
	
re: fclean all