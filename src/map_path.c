/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:03:06 by malkilan          #+#    #+#             */
/*   Updated: 2025/11/13 19:44:08 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"
#include "../include/so_long.h"
#include "../libft/libft.h"

static void	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*y = i;
				*x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

static char	**copy_map_for_flood(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int x, int y)
{
	if (!map[y] || !map[y][x])
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == '\n')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'F';
		return ;
	}
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static int	check_items(char **map, char item)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == item)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_path(char **map)
{
	char	**map_copy;
	int		player_x;
	int		player_y;
	int		result;

	map_copy = copy_map_for_flood(map);
	if (!map_copy)
		return (0);
	find_player(map_copy, &player_x, &player_y);
	flood_fill(map_copy, player_x, player_y);
	result = check_items(map_copy, 'C') && check_items(map_copy, 'E');
	free_map(map_copy);
	return (result);
}
