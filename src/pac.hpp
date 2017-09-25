#ifndef PAC_HPP
# define PAC_HPP
# include <iostream>
# include <fstream>
# include <string>
# include <string.h>
# include <stdlib.h>
# include <vector>
# include <thread>

class 			Pac
{
public:
	int		x;
	int		y;
	int		points;

	Pac(std::vector<std::vector<int> > map);
	go(std::vector<std::vector<int> > map, char flag);
	~Pac();
};

class 			Ghost
{
public:
	int		x;
	int		y;

	Ghost(int x0, int y0, int ide);
	~Ghost();
};

char			**ft_strsplit(char const *s, char c);
void			delete_split(char **split);
int				split_size(char **split);	

#endif