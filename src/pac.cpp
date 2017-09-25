#include "pac.hpp"

class 			Pac(int x0, int y0)
{
	public:
		int		x;
		int		y;
		int		points;

	void	Pac(std::vector<std::vector<int> > map)
	{
		for (int i = 0; i < map.size(); i++)
		{
			for (int j = 0; j < map[i].size(); j++)
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

	void	go(std::vector<std::vector<int> > map, char flag)
	{
		if (flag == 'r')
		{
			if (this->x < map[this->y].size())
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
			if (this->y < map.size())
			{
				map[this->y][this->x] = 1;
				this->y--;
			}
		}
		if (map[this->y][this->x] == 5)
			this->points++;
		map[this->y][this->x] = 2;
	}

	void	~Pac()
	{
		std::cout << "Pac-man is dead :(" << endl;
	}
};