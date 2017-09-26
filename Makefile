NAME1 = pac-man
SYSTEM = LINUX
CC = g++
SRC = src/main.cpp src/ft_strsplit.cpp src/viz.cpp src/pac.cpp src/ghost.cpp
FLAGS = -Wno-deprecated-declarations-g -std=c++11 -O3
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

ifeq ($(SYSTEM), LINUX)
	INCLUDE_SFML = -I SFML-LINUX/include
else
	INCLUDE_SFML = -I SFML-OSX/include
endif

.PHONY: all re clean fclean

all: $(NAME1)

$(NAME1): $(SRC:.cpp=.o)
	$(CC) -o $(NAME1) $(SRC:.cpp=.o) $(FLAGS) $(SFML_FLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(FLAGS) $(INCLUDE_SFML)

clean:
	rm -f $(SRC:.cpp=.o)

fclean: clean
	rm -f $(NAME1)
	
re: fclean all