/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:06:08 by malkilan          #+#    #+#             */
/*   Updated: 2025/11/13 17:06:11 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../minilibx-linux/mlx.h"
# include "map.h"

# define TILE_SIZE 32

typedef struct s_image
{
	void	*img;
	int		width;
	int		height;
}			t_image;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		collected;
	int		moves;
	t_image	wall;
	t_image	floor;
	t_image	player;
	t_image	collectible;
	t_image	exit;
}			t_game;

int			init_game(t_game *game, char **map);
void		free_game(t_game *game);
void		render_map(t_game *game);
int			handle_keypress(int keycode, t_game *game);
int			handle_close(t_game *game);

#endif
