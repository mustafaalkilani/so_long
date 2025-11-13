/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:04:59 by malkilan          #+#    #+#             */
/*   Updated: 2025/11/13 18:29:11 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/error.h"
#include "../include/map.h"
#include "../include/so_long.h"

static char	**copy_map(char **old_map, char **new_map, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		new_map[i] = old_map[i];
		i++;
	}
	return (new_map);
}

static char	**resize_map(char **map, int lines)
{
	char	**new_map;

	new_map = malloc(sizeof(char *) * (lines + 2));
	if (!new_map)
		return (NULL);
	if (map)
	{
		new_map = copy_map(map, new_map, lines);
		free(map);
	}
	new_map[lines] = NULL;
	return (new_map);
}

char	**load_map(const char *filename)
{
	int	fd;
	char	**map;
	char	*line;
	int	lines;

	map = NULL;
	lines = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror(PERROR), NULL);
	while ((line = get_next_line(fd)) != NULL)
	{
		map = resize_map(map, lines);
		if (!map)
			return (free(line), close(fd), NULL);
		map[lines++] = line;
	}
	close(fd);
	if (validate_map(map))
		return (map);
	free_map(map);
	return (NULL);
}