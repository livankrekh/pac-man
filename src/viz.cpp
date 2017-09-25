#include "pac.hpp"

void	vizualize(std::vector<std::vector<int> > map)
{
	Pac 	*pacman = new Pac(map);
	Ghost	*ghosts;
	int		gh;

	gh = 0;
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
			if (map[i][j] == 3)
				gh++;
	}
	ghosts = new Ghost[gh + 1];
	gh = 0;
	for (i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
			if (map[i][j] == 3)
				ghosts[gh] = new Ghost(j, i, gh++);
	}
}