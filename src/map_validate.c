/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:03:39 by malkilan          #+#    #+#             */
/*   Updated: 2025/11/13 19:50:49 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../include/error.h"
#include "../include/map.h"
#include "../include/so_long.h"
#include "../libft/libft.h"

static int	error(char *msg)
{
	ft_printf("%s", msg);
	return (0);
}

static int	validate_rectangle(char **map)
{
	int	width;
	int	y;
	int	len;

	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	if (map[0][width - 1] == '\n')
		width--;
	y = 1;
	while (map[y])
	{
		len = ft_strlen(map[y]);
		if (map[y][len - 1] == '\n')
			len--;
		if (len != width)
			return (0);
		y++;
	}
	return (1);
}

static int	validate_wall(char **map)
{
	int	i;
	int	j;
	int	width;
	int	height;

	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	if (map[0][width - 1] == '\n')
		width--;
	height = 0;
	while (map[height])
		height++;
	i = -1;
	while (++i < width)
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
	j = 0;
	while (++j < height - 1)
		if (map[j][0] != '1' || map[j][width - 1] != '1')
			return (0);
	return (1);
}

static int	validate_items(char **map)
{
	int	i;
	int	j;
	int	counters[3];

	counters[0] = 0;
	counters[1] = 0;
	counters[2] = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				counters[0]++;
			else if (map[i][j] == 'E')
				counters[1]++;
			else if (map[i][j] == 'C')
				counters[2]++;
			else if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '\n')
				return (0);
		}
	}
	return (counters[0] == 1 && counters[1] == 1 && counters[2] >= 1);
}

int	validate_map(char **map)
{
	if (!map)
		return (error(ERR_EMPTY));
	if (!validate_rectangle(map))
		return (error(ERR_RECT));
	if (!validate_wall(map))
		return (error(ERR_WALLS));
	if (!validate_items(map))
		return (error(ERR_ITEMS));
	if (!validate_path(map))
		return (error(ERR_PATH));
	return (1);
}
