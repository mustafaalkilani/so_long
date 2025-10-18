#include "../include/map.h"
#include "../include/error.h"
#include "../include/so_long.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

int	error(char *msg, char **map)
{
	ft_printf("%s", msg);
	if (map)
		free_map(map);
	return (0);
}
int	validate_rectangle(char **map)
{
	int	width;
	int	y;

	if (!map || !map[0])
		return (0);

	width = ft_strlen(map[0]);
	if (map[0][width - 1] == '\n')
		width--;

	y = 1;
	while (map[y])
	{
		int	len = ft_strlen(map[y]);
		if (map[y][len - 1] == '\n')
			len--;
		if (len != width)
			return (0);
		y++;
	}
	return (1);
}
int	validate_wall(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	if (!map || !map[0])
		return (0);
	while(map[i][0] != '\n')
	{
		if (map[i][0] == 1)
			i++;
		else
			return (0);
	}
	i = 0;
	while(map[i][len])
	{
		if (map[i][len] == 1)
			i++;
		else
			return (0);
	}
}
int validate_map(char **map)
{
    if (!validate_rectangle(map))
	{
        return (error(ERR_RECT, map));
	}
	return(1);
}
