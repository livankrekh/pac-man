#include "pac.hpp"

Ghost::Ghost(int x0, int y0, int ide)
{
	this->x = x0;
	this->y = y0;
	this->id = ide;
	this->prev = 1;
}
