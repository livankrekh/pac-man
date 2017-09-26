NAME1 = pac-man
CC = g++
SRC = src/main.cpp src/ft_strsplit.c src/viz.cpp src/pac.cpp src/ghost.cpp
FLAGS = -Wno-deprecated-declarations -Wall -Wextra -Werror -g -std=c++11 -O3
# SDL_FLAG = -I /Library/Frameworks/SDL2.framework/Versions/A/Headers \
# 			-F /Library/Frameworks/ -framework SDL2
# SDL_ttf = -I /vm/SDL2_ttf.framework/Versions/A/Headers \
# 			-F ./ -framework SDL2_ttf


.PHONY: all re clean fclean

all: $(NAME1)

$(NAME1): $(SRC:.c=.o) $(SRC:.cpp=.o)
	$(CC) -o $(NAME1) $(SRC:.c=.o) $(FLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(FLAGS)

clean:
	rm -f $(SRC:.c=.o) $(SRC:.cpp=.o)

fclean: clean
	rm -f $(NAME1)
	
re: fclean all