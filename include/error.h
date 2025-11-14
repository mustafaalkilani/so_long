/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:06:15 by malkilan          #+#    #+#             */
/*   Updated: 2025/11/13 17:06:17 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_RECT "Error: map is not rectangular\n"
# define ERR_WALLS "Error: map not surrounded by walls\n"
# define ERR_ITEMS "Error: missing or invalid map items (need 1P, >=1C, 1E)\n"
# define ERR_CHAR "Error: map contains invalid character\n"
# define ERR_PATH "Error: no valid path to all collectibles and exit\n"
# define PERROR "Error opening map"
# define ERR_EMPTY "Error: map is empty or invalid\n"

#endif