#include "pac.hpp"

void	vizualize(std::vector<std::vector<int> > map, int gh)
{
	Pac 				*pacman = new Pac(map);
	std::vector<Ghost>	ghosts;
	std::thread	pac_thread;
	std::thread	ghosts_thread;

	gh = 0;
	ghosts.reserve(gh);
	for (int i = 0; i < (int)map.size(); i++)
	{
		for (int j = 0; j < (int)map[i].size(); j++)
			if (map[i][j] == 3)
				gh++;
	};
	gh = 0;
	for (int i = 0; i < (int)map.size(); i++)
	{
		for (int j = 0; j < (int)map[i].size(); j++)
			if (map[i][j] == 3)
				ghosts.push_back(Ghost(j, i, gh++));
	}
	delete pacman;
}