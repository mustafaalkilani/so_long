#include "../include/so_long.h"
#include "../get_next_line/get_next_line.h"

char	**load_map(const char *filename)
{
	int		fd;
	char	**map = NULL;
	char	*line;
	int		lines = 0;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map");
		return (NULL);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		map = realloc(map, sizeof(char *) * (lines + 2));
		map[lines++] = line;
		map[lines] = NULL;
	}
	close(fd);
	return (map);
}
