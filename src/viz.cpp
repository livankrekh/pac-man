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

void	going(Pac *pacman, std::vector<std::vector<int> > *map, sf::Sprite *pacman_sprite)
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
		exit(1);
	(*map)[new_y][new_x] = 2;
	(*map)[pacman->y][pacman->x] = 1;
	pacman->x = new_x;
	pacman->y = new_y;
}

void	draw_pacman(std::vector<std::vector<int> > *map, Pac *pacman, sf::Sprite *pacman_sprite, sf::Clock & clockS, float & current, float & current2)
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
			going(pacman, map, pacman_sprite);
			current2 = 0;
		}
		pacman_sprite->setTextureRect(sf::IntRect(320 + (32 * (int)current), 0, 32, 32));
		pacman_sprite->move(0.1 * sec, 0);
		// std::cout << (pacman_sprite->getPosition()).x << std::endl;
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
			going(pacman, map, pacman_sprite);
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
			going(pacman, map, pacman_sprite);
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
			going(pacman, map, pacman_sprite);
			current2 = 0;
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
	char				path[2048];
	// sf::Texture 		ground_tmp;
	// sf::Sprite 			ground;
	int					w;
	int					h;
	int					x;
	int					y;

	y = 30;
	h = 540 / map->size();
	w = get_w(map);

	ptr.loadFromFile(strcat(getcwd(path, 2048), "/src/img/point.bmp"));
	bzero(path, 2048);
	ptr.createMaskFromColor(sf::Color(255, 0, 255));
	ptr_tmp.loadFromImage(ptr);
	wall_tmp.loadFromFile(strcat(getcwd(path, 2048), "/src/img/wall.png"));
	bzero(path, 2048);
	wall_back_tmp.loadFromFile(strcat(getcwd(path, 2048), "/src/img/wall_back.jpg"));
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
	sf::RenderWindow			window(sf::VideoMode(800, 600), "Pac-man");
	sf::Texture 				pac;
	sf::Sprite					pacman_sprite;
	sf::Font					font;
	sf::Text 					score;
	float						current;
	float						current2;
	sf::Clock 					clockS;
	std::vector<sf::Sprite*>	gh_sprite;
	sf::Texture 				tmp_door;
	sf::Sprite 					door;
	sf::Texture 				tmp_ghosts;
	char						path[2048];

	current = 0;
	current2 = 0;
	pac.loadFromFile(strcat(getcwd(path, 2048), "/src/img/all.png"));
	bzero(path, 2048);
	pacman_sprite.setTexture(pac);
	pacman_sprite.setPosition(pacman->x * 32 + 30, pacman->y * 32 + 30);
	pacman_sprite.setTextureRect(sf::IntRect(320, 0, 32, 32));
	font.loadFromFile(strcat(getcwd(path, 2048), "/src/img/Comic_sans.ttf"));
	bzero(path, 2048);
	score = sf::Text("", font, 20);
	score.setColor(sf::Color::Black);
	score.setStyle(sf::Text::Bold | sf::Text::Underlined);
	tmp_door.loadFromFile(strcat(getcwd(path, 2048), "/src/img/door.png"));
	bzero(path, 2048);
	tmp_ghosts.loadFromFile(strcat(getcwd(path, 2048), "/src/img/all.png"));
	door.setTexture(tmp_door);
	get_ghosts(ghosts, map, gh_sprite, tmp_ghosts);
	for (int i = 0; i < map->size(); i++)
	{
		for (int j = 0; j < (*map)[i].size(); j++)
			if ((*map)[i][j] == 4)
				door.setPosition(j * get_w(map) + 30, i * (540 / map->size()) + 30);
	}
	door.setTextureRect(sf::IntRect(20, 0, 64, 64));
	door.setScale((float)get_w(map) / 64.0, (float)(540 / map->size()) / 64.0);
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
		draw_pacman(map, pacman, &pacman_sprite, clockS, current, current2);
		for (int i = 0; i < ghosts.size(); i++)
			window.draw(*(gh_sprite[i]));
		window.draw(door);
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