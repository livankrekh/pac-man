#include "pac.hpp"

class 			Ghost
{
public:
	int		x;
	int		y;
	int		id;

	void	Ghost(int x0, int y0, int ide)
	{
		this->x = x0;
		this->y = y0;
		this->id = ide;
	}

	void	~Ghost()
	{
		std::cout << "Ghost #" << this->id << " is dead :)" << endl;
	}
};