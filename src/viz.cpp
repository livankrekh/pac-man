#include "pac.hpp"

void	go_viz(std::vector<std::vector<int> > map, Pac *pacman, std::vector<Ghost*> ghosts)
{
	sf::RenderWindow	window(sf::VideoMode(800, 600), "Pac-man");
	sf::Texture			wall;
	sf::Sprite			pac;

	wall.loadFromFile("all.png");
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
		window.draw(pac);
        window.display();
    }
}

void	vizualize(std::vector<std::vector<int> > map, int gh)
{
	Pac 				*pacman = new Pac(map);
	std::vector<Ghost*>	ghosts;
	std::thread			pac_thread;
	std::thread			ghosts_thread;

	ghosts.reserve(gh);
	gh = 0;
	for (int i = 0; i < (int)map.size(); i++)
	{
		for (int j = 0; j < (int)map[i].size(); j++)
			if (map[i][j] == 3)
				gh++;
	};
	gh = 0;
	for (int i = 0; i < (int)map.size(); i++)
	{
		for (int j = 0; j < (int)map[i].size(); j++)
			if (map[i][j] == 3)
			ghosts.push_back(new Ghost(j, i, gh++));
	}
	go_viz(map, pacman, ghosts);
}