#include "so_long.h"

void	free_map(char **map)
{
	int i;

    i = 0;
	if (!map)
		return;
	while (map[i])
		free(map[i++]);
	free(map);
}
