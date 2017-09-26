#include "pac.hpp"

void	draw_map(std::vector<std::vector<int> > *map, sf::RenderWindow *window)
{
	sf::Texture			wall_tmp;
	sf::Texture 		wall_back_tmp;
	sf::Sprite			wall_back;
	sf::Sprite			wall;
	int					w;
	int					h;
	int					x;
	int					y;

	y = 30;
	h = 540 / map->size();
	w = 0;
	wall_tmp.loadFromFile("/home/unit-hacker/pac-man/src/img/wall.png");
	wall_back_tmp.loadFromFile("/home/unit-hacker/pac-man/src/img/wall_back.jpg");
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
		if (w < (*map)[i].size())
			w = (*map)[i].size();
	w = 740 / w;
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
			x += w;
		}
		y += h;
	}
}

void	go_viz(std::vector<std::vector<int> > *map, Pac *pacman, std::vector<Ghost*> ghosts)
{
	sf::RenderWindow	window(sf::VideoMode(800, 600), "Pac-man");
	sf::Texture			wall;
	sf::Sprite			pac;

	wall.loadFromFile("/home/unit-hacker/pac-man/src/img/all.png");
	pac.setTexture(wall);
	pac.setPosition(100, 100);
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