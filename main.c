/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:04:31 by malkilan          #+#    #+#             */
/*   Updated: 2025/11/13 17:04:40 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "include/so_long.h"

int	check_extension(const char *filename)
{
	int	len;

	len = 0;
	while (filename[len])
		len++;
	if (len < 5 || filename[len - 4] != '.' || filename[len - 3] != 'b'
		|| filename[len - 2] != 'e' || filename[len - 1] != 'r')
	{
		ft_printf("Error: map file must have .ber extension\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char **map;
	t_game game;

	if (argc != 2)
	{
		write(2, "Usage: ./so_long <map.ber>\n", 27);
		return (1);
	}
	if (!check_extension(argv[1]))
		return (1);
	map = load_map(argv[1]);
	if (!map)
		return (1);
	if (!init_game(&game, map))
	{
		ft_printf("Error: failed to initialize game\n");
		free_map(map);
		return (1);
	}
	render_map(&game);
	mlx_hook(game.win, 17, 0, handle_close, &game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_loop(game.mlx);
	return (0);
}