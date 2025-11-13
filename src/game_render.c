/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:05:12 by malkilan          #+#    #+#             */
/*   Updated: 2025/11/13 18:33:59 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#include "../include/so_long.h"

static void	render_tile(t_game *game, char tile, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->floor.img, x
		* TILE_SIZE, y * TILE_SIZE);
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall.img, x
		* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player.img, x
		* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collectible.img, x
		* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit.img, x
		* TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			render_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
