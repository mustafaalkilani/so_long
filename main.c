#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		i = 0;

	if (argc != 2)
	{
		write(2, "Usage: ./so_long <map.ber>\n", 27);
		return (1);
	}
	map = load_map(argv[1]);
	if (!map)
		return (1);

	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	free_map(map);
	return (0);
}
