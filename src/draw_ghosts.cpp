#include "pac.hpp"

void	going_gh(Ghost *ghost, std::vector<std::vector<int> > *map, sf::Sprite *gh_sprite, std::vector<Ghost*> ghosts, Pac *pacman)
{
	float	x_loc;
	float	y_loc;
	int 	w;
	int 	h;
	int 	new_x;
	int 	new_y;

	w = get_w(map);
	h = 540 / map->size();
	x_loc = gh_sprite->getPosition().x + (w / 2);
	y_loc = gh_sprite->getPosition().y + (h / 2);
	new_x = (x_loc - 30) / w;
	new_y = (y_loc - 30) / h;
	if ((*map)[new_y][new_x] == 2)
	{
		delete pacman;
		for (int i = 0; i < ghosts.size(); i++)
			delete ghosts[i];
		std::cout << "Pac-man dead! You lose!" << std::endl;
		exit(2);
	}
	(*map)[ghost->y][ghost->x] = ghost->prev;
	ghost->prev = (*map)[new_y][new_x];
	(*map)[new_y][new_x] = 3;
	ghost->x = new_x;
	ghost->y = new_y;
}

void	move_ghosts(std::vector<std::vector<int> > *map, std::vector<sf::Sprite*> & ghosts, sf::Clock clockS, Pac *pacman, std::vector<Ghost*> ghosts_obj)
{
	float	sec;
	int 	deltaX;
	int 	deltaY;

	sec = clockS.getElapsedTime().asMicroseconds();
	clockS.restart();
	sec = sec / 800;
	for (int i = 0; i < ghosts.size(); i++)
	{
		deltaX = pacman->x - ghosts_obj[i]->x;
		deltaY = pacman->y - ghosts_obj[i]->y;
		if (deltaX == 0)
			ghosts[i]->move(0, 0.7 * sec * (deltaY > 0 ? 1 : -1));
		else if (deltaY == 0)
			ghosts[i]->move(0.7 * sec * (deltaX > 0 ? 1 : -1), 0);
		else if ((deltaX > 0 ? deltaX : deltaX * -1) >= (deltaY > 0 ? deltaY : deltaY * -1) && deltaY != 0)
			ghosts[i]->move(0, 0.7 * sec * (deltaY > 0 ? 1 : -1));
		else if ((deltaX > 0 ? deltaX : deltaX * -1) < (deltaY > 0 ? deltaY : deltaY * -1) && deltaX != 0)
			ghosts[i]->move(0.7 * sec * (deltaX > 0 ? 1 : -1), 0);
		going_gh(ghosts_obj[i], map, ghosts[i], ghosts_obj, pacman);
	}
}

void	get_ghosts(std::vector<Ghost*> ghosts, std::vector<std::vector<int> > *map, std::vector<sf::Sprite*> & res, sf::Texture & tmp)
{
	int 						w;
	int 						h;
	char						path[2048];

	h = 540 / map->size();
	w = get_w(map);
	res.reserve(ghosts.size());
	for (int i = 0; i < ghosts.size(); i++)
	{
		res.push_back(new sf::Sprite);
		res[i]->setTexture(tmp);
		res[i]->setTextureRect(sf::IntRect(0 + (64 * (i % 6)), 0, 32, 32));
		res[i]->setPosition(ghosts[i]->x * w + 30, ghosts[i]->y * h + 30);
		res[i]->setScale((float)w / 32.0, (float)h / 32.0);
	}
}