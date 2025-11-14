/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:05:21 by malkilan          #+#    #+#             */
/*   Updated: 2025/11/13 18:31:34 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../include/game.h"
#include "../include/so_long.h"
#include "../libft/libft.h"

static void	get_map_dimensions(char **map, int *width, int *height)
{
	int	h;
	int	w;

	h = 0;
	while (map[h])
		h++;
	w = ft_strlen(map[0]);
	if (map[0][w - 1] == '\n')
		w--;
	*width = w;
	*height = h;
}

static void	find_player_pos(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static int	count_collectibles(char **map)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static int	load_images(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &game->wall.width, &game->wall.height);
	game->floor.img = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &game->floor.width, &game->floor.height);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &game->player.width, &game->player.height);
	game->collectible.img = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &game->collectible.width,
			&game->collectible.height);
	game->exit.img = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &game->exit.width, &game->exit.height);
	if (!game->wall.img || !game->floor.img || !game->player.img
		|| !game->collectible.img || !game->exit.img)
	{
		ft_printf("Error: failed to load textures\n");
		return (0);
	}
	return (1);
}

int	init_game(t_game *game, char **map)
{
	game->map = map;
	get_map_dimensions(map, &game->map_width, &game->map_height);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE, "Mustafa's So Long Game");
	if (!game->win)
		return (0);
	if (!load_images(game))
		return (0);
	find_player_pos(game);
	game->collectibles = count_collectibles(map);
	game->collected = 0;
	game->moves = 0;
	return (1);
}
