#ifndef PAC_HPP
# define PAC_HPP
# include <iostream>
# include <fstream>
# include <string>
# include <string.h>
# include <stdlib.h>
# include <vector>
# include <thread>
# include <SFML/Graphics.hpp>
# include <SFML/Window.hpp>

class 			Pac
{
public:
	int		x;
	int		y;
	int		points;

	Pac(std::vector<std::vector<int> > map);
	~Pac();
	void	go_away(std::vector<std::vector<int> > map, char flag);
};

class 			Ghost
{
public:
	int		x;
	int		y;
	int		id;

	Ghost(int x0, int y0, int ide);
	~Ghost();
};

char			**ft_strsplit(char const *s, char c);
void			delete_split(char **split);
int				split_size(char **split);
void			vizualize(std::vector<std::vector<int> > map, int gh);	

#endif