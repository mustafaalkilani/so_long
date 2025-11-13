/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:06:01 by malkilan          #+#    #+#             */
/*   Updated: 2025/11/13 17:06:03 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

char	**load_map(const char *filename);
void	free_map(char **map);
int		validate_map(char **map);
int		validate_path(char **map);

#endif