#include "pac.hpp"


Pac::Pac(std::vector<std::vector<int> > map)
{
	int		j;

	for (int i = 0; i < (int)map.size(); i++)
	{
		for (j = 0; j < (int)map[i].size(); j++)
		{
			if (map[i][j] == 2)
			{
				this->x = j;
				this->y = i;
				this->points = 0;
				break;
			}
		}
		if (map[i][j] == 2)
			break;
	}
}

void	Pac::go_away(std::vector<std::vector<int> > map, char flag)
{
	if (flag == 'r')
	{
		if (this->x < (int)map[this->y].size())
		{
			map[this->y][this->x] = 1;
			this->x++;
		}
	}
	else if (flag == 'l')
	{
		if (this->x > 0)
		{
			map[this->y][this->x] = 1;
			this->x--;
		}
	}
	else if (flag == 'u')
	{
		if (this->y > 0)
		{
			map[this->y][this->x] = 1;
			this->y--;
		}
	}
	else if (flag == 'd')
	{
		if (this->y < (int)map.size())
		{
			map[this->y][this->x] = 1;
			this->y--;
		}
	}
	if (map[this->y][this->x] == 5)
		this->points++;
	map[this->y][this->x] = 2;
}

Pac::~Pac()
{
	std::cout << "Pac-man is dead :(" << std::endl;
}