#include "pac.hpp"

void	going(Pac *pacman, std::vector<std::vector<int> > *map, sf::Sprite *pacman_sprite, std::vector<Ghost*> & ghosts)
{
	float	x_loc;
	float	y_loc;
	int 	w;
	int 	h;
	int 	new_x;
	int 	new_y;

	w = get_w(map);
	h = 540 / map->size();
	x_loc = pacman_sprite->getPosition().x + (w / 2);
	y_loc = pacman_sprite->getPosition().y + (h / 2);
	new_x = (x_loc - 30) / w;
	new_y = (y_loc - 30) / h;
	if ((*map)[new_y][new_x] == 5)
		pacman->points++;
	if ((*map)[new_y][new_x] == 4)
	{
		delete pacman;
		for (int i = 0; i < ghosts.size(); i++)
			delete ghosts[i];
		std::cout << "Pac-man found exit! You won with " << pacman->points << " points!" << std::endl;
		exit(1);
	}
	if ((*map)[new_y][new_x] == 3)
	{
		delete pacman;
		for (int i = 0; i < ghosts.size(); i++)
			delete ghosts[i];
		std::cout << "Pac-man dead! You lose!" << std::endl;
		exit(2);
	}
	(*map)[new_y][new_x] = 2;
	(*map)[pacman->y][pacman->x] = 1;
	pacman->x = new_x;
	pacman->y = new_y;
}

void	draw_pacman(std::vector<std::vector<int> > *map, Pac *pacman, sf::Sprite *pacman_sprite, sf::Clock & clockS, float & current, float & current2, std::vector<Ghost*> & ghosts)
{
	float			sec;

	sec = clockS.getElapsedTime().asMicroseconds();
	pacman_sprite->setScale((float)get_w(map) / 32.0, (float)(540 / map->size()) / 32.0);
	clockS.restart();
	sec = sec / 800;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
		&& (pacman->x < (*map)[pacman->y].size() && (*map)[pacman->y][pacman->x + 1] != 0))
	{
		current += 0.005 * sec;
		current2 += 0.005 * sec;
		if (current > 2)
			current -= 2;
		if (current2 >= 1)
		{
			going(pacman, map, pacman_sprite, ghosts);
			current2 = 0;
		}
		pacman_sprite->setTextureRect(sf::IntRect(320 + (32 * (int)current), 0, 32, 32));
		pacman_sprite->move(0.1 * sec, 0);
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
		&& (pacman->x != 0 && (*map)[pacman->y][pacman->x - 1] != 0))
	{
		current += 0.005 * sec;
		current2 += 0.005 * sec;
		if (current > 2)
			current -= 2;
		if (current2 >= 1)
		{
			going(pacman, map, pacman_sprite, ghosts);
			current2 = 0;
		}
		pacman_sprite->setTextureRect(sf::IntRect(320 + (32 * (int)current), 64, 32, 32));
		pacman_sprite->move(-0.1 * sec, 0);
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
		&& (pacman->y != 0 && (*map)[pacman->y - 1][pacman->x] != 0))
	{
		current += 0.005 * sec;
		current2 += 0.005 * sec;
		if (current > 2)
			current -= 2;
		if (current2 >= 1)
		{
			going(pacman, map, pacman_sprite, ghosts);
			current2 = 0;
		}
		pacman_sprite->setTextureRect(sf::IntRect(320 + (32 * (int)current), 96, 32, 32));
		pacman_sprite->move(0, -0.1 * sec);
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
		&& (pacman->y < map->size() - 1 && (*map)[pacman->y + 1][pacman->x] != 0))
	{
		current += 0.005 * sec;
		current2 += 0.005 * sec;
		if (current > 2)
			current -= 2;
		if (current2 >= 1)
		{
			going(pacman, map, pacman_sprite, ghosts);
			current2 = 0;
		}
		pacman_sprite->setTextureRect(sf::IntRect(320 + (32 * (int)current), 32, 32, 32));
		pacman_sprite->move(0, 0.1 * sec);
	}
}
