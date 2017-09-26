#include "pac.hpp"

int		get_file_size(char *name)
{
	std::ifstream	file_tmp;
	int				res;
	char			tmp[2048];

	res = 0;
	file_tmp.open(name);
	while (!file_tmp.eof())
	{
		file_tmp.getline(tmp, 2048);
		res++;
	}
	return (res);
}

int		main(int argc, char **argv)
{
	std::vector<std::vector<int> >	map;
	std::ifstream					file_map;
	char							buff[2048];
	char							**tmp;
	int								size_y;
	int								gh;

	gh = 0;
	if (argc == 1)
	{
		map.reserve(20);
		for (int i = 0; i < 20; i++)
		{
			map[i].reserve(20);
			map.push_back(map[i]);
			for (int j = 0; j < 20; j++)
			{
				if (i == 0 && j == 0)
					map[i].push_back(2);
				else if (i == 0 && j == 19)
					map[i].push_back(3);
				else if (i == 19 && j == 0)
					map[i].push_back(3);
				else if (i == 19 && j == 19)
					map[i].push_back(3);
				else if (i == 19 && j == 9)
					map[i].push_back(4);
				else
					map[i].push_back(5);
			}
		}
	}
	else
	{
		size_y = get_file_size(argv[1]);
		file_map.open(argv[1]);
		map.reserve(size_y);

		for (int i = 0; !file_map.eof(); i++)
		{
			file_map.getline(buff, 2048);
			tmp = ft_strsplit(buff, ' ');
			map[i].reserve(split_size(tmp));
			map.push_back(map[i]);

			for (int j = 0, size = split_size(tmp); j < size; j++)
				map[i].push_back(atoi(tmp[j]));
			delete_split(tmp);
		}
		tmp = NULL;
	}
	for (int k = 0; k < (int)map.size(); k++)
	{
		for (int l = 0; l < (int)map[k].size(); l++)
		{
			if (map[k][l] == 3)
				gh++;
			std::cout << map[k][l] << " ";
		}
		std::cout << std::endl;
	}
	vizualize(map, gh);

	return (0);
}