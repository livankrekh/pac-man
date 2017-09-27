#include "pac.hpp"

int 	get_w(std::vector<std::vector<int> > *map)
{
	int 	w;

	w = 0;
	for (int i = 0; i < map->size(); i++)
		if (w < (*map)[i].size())
			w = (*map)[i].size();
	return (740 / w);
}

void	draw_pacman(std::vector<std::vector<int> > *map, Pac *pacman, sf::Sprite *pacman_sprite, sf::Clock & clockS, float & current)
{
	float			sec;

	sec = clockS.getElapsedTime().asMicroseconds();
	pacman_sprite->setScale((float)get_w(map) / 32.0, (float)(540 / map->size()) / 32.0);
	clockS.restart();
	sec = sec / 800;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
		&& (*map)[pacman->y][pacman->x + 1] != 0)
	{
		current += 0.005 * sec;
		if (current > 2)
		{
			pacman->go_away(*map, 'r');
			current -= 2;
		}
		pacman_sprite->setTextureRect(sf::IntRect(320 + (32 * (int)current), 0, 32, 32));
		pacman_sprite->move(0.1 * sec, 0);
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
		&& (*map)[pacman->y][pacman->x - 1] != 0)
	{
		current += 0.005 * sec;
		if (current > 2)
		{
			pacman->go_away(*map, 'l');
			current -= 2;
		}
		pacman_sprite->setTextureRect(sf::IntRect(320 + (32 * (int)current), 64, 32, 32));
		pacman_sprite->move(-0.1 * sec, 0);
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
		&& (*map)[pacman->y - 1][pacman->x] != 0)
	{
		current += 0.005 * sec;
		if (current > 2)
		{
			pacman->go_away(*map, 'u');
			current -= 2;
		}
		pacman_sprite->setTextureRect(sf::IntRect(320 + (32 * (int)current), 96, 32, 32));
		pacman_sprite->move(0, -0.1 * sec);
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
		&& (*map)[pacman->y + 1][pacman->x] != 0)
	{
		current += 0.005 * sec;
		if (current )
		if (current > 2)
		{
			pacman->go_away(*map, 'd');
			current -= 2;
		}
		pacman_sprite->setTextureRect(sf::IntRect(320 + (32 * (int)current), 32, 32, 32));
		pacman_sprite->move(0, 0.1 * sec);
	}
}

void	draw_map(std::vector<std::vector<int> > *map, sf::RenderWindow *window)
{
	sf::Texture			wall_tmp;
	sf::Texture 		wall_back_tmp;
	sf::Sprite			wall_back;
	sf::Sprite			wall;
	sf::Image			ptr;
	sf::Texture 		ptr_tmp;
	sf::Sprite 			point;
	// sf::Texture 		ground_tmp;
	// sf::Sprite 			ground;
	int					w;
	int					h;
	int					x;
	int					y;

	y = 30;
	h = 540 / map->size();
	w = get_w(map);
	ptr.loadFromFile("/home/unit-hacker/pac-man/src/img/point.bmp");
	ptr.createMaskFromColor(sf::Color(255, 0, 255));
	ptr_tmp.loadFromImage(ptr);
	wall_tmp.loadFromFile("/home/unit-hacker/pac-man/src/img/wall.png");
	wall_back_tmp.loadFromFile("/home/unit-hacker/pac-man/src/img/wall_back.jpg");
	// ground_tmp.loadFromFile("/home/unit-hacker/pac-man/src/img/ground.gif");
	for (int i = 0; i < 600; i += 30)
	{
		for (int j = 0; j < 800; j += 30)
		{
			if (j == 0 || j >= 770 || i == 0 || i >= 570)
			{
				wall_back.setTexture(wall_back_tmp);
				wall_back.setScale(0.1, 0.1);
				wall_back.setPosition(j, i);
				window->draw(wall_back);
			}
		}
	}
	for (int i = 0; i < map->size(); i++)
	{
		wall_back.setTexture(wall_back_tmp);
		wall_back.setScale(0.1, 0.1);
		wall_back.setPosition(0, y);
		window->draw(wall_back);
		x = 30;
		for (int j = 0; j < (*map)[i].size(); j++)
		{
			if ((*map)[i][j] == 0)
			{
				wall.setTexture(wall_tmp);
				wall.setScale((float)w / 32.0, (float)h / 32.0);
				wall.setPosition(x, y);
				window->draw(wall);
			}
			else if ((*map)[i][j] == 5)
			{
				point.setTexture(ptr_tmp);
				point.setScale((float)w / 32.0, (float)h / 32.0);
				point.setPosition(x, y);
				window->draw(point);
			}
			// else
			// {
			// 	ground.setTexture(ground_tmp);
			// 	ground.setTextureRect(sf::IntRect(0, 0, 32, 32));
			// 	ground.setScale((float)w / 32.0, (float)h / 32.0);
			// 	ground.setPosition(x, y);
			// 	window->draw(ground);
			// }
			x += w;
		}
		y += h;
	}
}

void	go_viz(std::vector<std::vector<int> > *map, Pac *pacman, std::vector<Ghost*> ghosts)
{
	sf::RenderWindow	window(sf::VideoMode(800, 600), "Pac-man");
	sf::Texture 		pac;
	sf::Sprite			pacman_sprite;
	sf::Font			font;
	sf::Text 			score;
	float				current;
	sf::Clock 			clockS;

	current = 0;
	pac.loadFromFile("/home/unit-hacker/pac-man/src/img/all.png");
	pacman_sprite.setTexture(pac);
	pacman_sprite.setPosition(pacman->x * 32 + 30, pacman->y * 32 + 30);
	pacman_sprite.setTextureRect(sf::IntRect(320, 0, 32, 32));
	font.loadFromFile("/home/unit-hacker/pac-man/src/img/Comic_sans.ttf");
	score = sf::Text("", font, 20);
	score.setColor(sf::Color::Black);
	score.setStyle(sf::Text::Bold | sf::Text::Underlined);
	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed ||
			(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();
		}
		window.clear();
		draw_map(map, &window);
		draw_pacman(map, pacman, &pacman_sprite, clockS, current);
		window.draw(pacman_sprite);
		score.setString("Pac-mans points: " + std::to_string(pacman->points));
		score.setPosition(30, 0);
		window.draw(score);
        window.display();
    }
}

void	vizualize(std::vector<std::vector<int> > *map, int gh)
{
	Pac 				*pacman = new Pac(*map);
	std::vector<Ghost*>	ghosts;
	std::thread			pac_thread;
	std::thread			ghosts_thread;

	ghosts.reserve(gh);
	gh = 0;
	for (int i = 0; i < (int)map->size(); i++)
	{
		for (int j = 0; j < (int)(*map)[i].size(); j++)
			if ((*map)[i][j] == 3)
				gh++;
	};
	gh = 0;
	for (int i = 0; i < (int)map->size(); i++)
	{
		for (int j = 0; j < (int)(*map)[i].size(); j++)
			if ((*map)[i][j] == 3)
			ghosts.push_back(new Ghost(j, i, gh++));
	}
	go_viz(map, pacman, ghosts);
}