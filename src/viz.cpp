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
		draw_pacman(map, pacman, &pacman_sprite, clockS, current, current2, ghosts);
		move_ghosts(map, gh_sprite, clockS, pacman, ghosts);
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