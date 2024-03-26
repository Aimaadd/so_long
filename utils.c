/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:12:35 by abentaye          #+#    #+#             */
/*   Updated: 2024/03/26 12:43:02 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
	return (1);
}

t_win	player_pos(t_win *mlg)
{
	t_map_info	map_info;

	map_info = read_map(mlg->map_name);
	mlg->pos_x = map_info.player_x;
	mlg->pos_y = map_info.player_y;
	return (*mlg);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*original_dest;

	original_dest = dest;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (original_dest);
}

char	**get_map(t_win *mlg, char **map, int x, int y)
{
	int		fd;
	char	*line;

	fd = open(mlg->map_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL && y < mlg->width)
	{
		map[y] = (char *)malloc(ft_strlen(line) + 1);
		if (map[y] == NULL)
		{
			close(fd);
			return (NULL);
		}
		ft_strcpy(map[y], line);
		free(line);
		y++;
		line = get_next_line(fd);
	}
	close(fd);
	if (y == 0 || x >= ft_strlen(map[y - 1]))
		return (NULL);
	return (map);
}
