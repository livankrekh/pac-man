#ifndef PAC_HPP
# define PAC_HPP
# include <iostream>
# include <fstream>
# include <string>
# include <string.h>
# include <stdlib.h>
# include <vector>
# include <thread>
# include <SFML/System/Vector2.hpp>
# include <SFML/Graphics.hpp>
# include <SFML/Window.hpp>
# include <unistd.h>

class 			Pac
{
public:
	int		x;
	int		y;
	int		points;

			Pac(std::vector<std::vector<int> > map);
	void	go_away(std::vector<std::vector<int> > & map, char flag);
};

class 			Ghost
{
public:
	int		x;
	int		y;
	int		id;
	int		prev;

			Ghost(int x0, int y0, int ide);
};

char			**ft_strsplit(char const *s, char c);
void			delete_split(char **split);
int				split_size(char **split);
void			vizualize(std::vector<std::vector<int> > *map, int gh);
int 			get_w(std::vector<std::vector<int> > *map);
void			get_ghosts(std::vector<Ghost*> ghosts, std::vector<std::vector<int> > *map, std::vector<sf::Sprite*> & res, sf::Texture & tmp);
void			move_ghosts(std::vector<std::vector<int> > *map, std::vector<sf::Sprite*> & ghosts, sf::Clock clockS, Pac *pacman, std::vector<Ghost*> ghosts_obj);
void			draw_pacman(std::vector<std::vector<int> > *map, Pac *pacman, sf::Sprite *pacman_sprite, sf::Clock & clockS, float & current, float & current2, std::vector<Ghost*> & ghosts);

#endif