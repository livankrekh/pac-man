#include "pac.hpp"

Ghost::Ghost(int x0, int y0, int ide)
{
	this->x = x0;
	this->y = y0;
	this->id = ide;
}

Ghost::~Ghost()
{
	std::cout << "Ghost #" << this->id << " is dead :)" << std::endl;
}