/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:36:26 by abentaye          #+#    #+#             */
/*   Updated: 2024/03/26 13:09:00 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	process_line(t_win *mlg, char *line, int pos_x, int pos_y)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			put_wall(mlg, pos_x, pos_y);
		else if (line[i] == '0')
			put_floor(mlg, pos_x, pos_y);
		else if (line[i] == 'P')
			display_player(mlg, pos_x, pos_y);
		else if (line[i] == 'C')
		{
			put_floor(mlg, pos_x, pos_y);
			put_collectible(mlg, pos_x, pos_y);
		}
		else if (line[i] == 'E')
		{
			put_floor(mlg, pos_x, pos_y);
			put_exit(mlg, pos_x, pos_y);
		}
		i++;
		pos_x += 64;
	}
}

void	init_map(t_win *mlg, char *map)
{
	char	*line;
	int		fd;
	int		pos_y;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return ;
	pos_y = 0;
	line = get_next_line(fd);
	while (line)
	{
		process_line(mlg, line, 0, pos_y);
		free(line);
		pos_y += 64;
		line = get_next_line(fd);
	}
	close(fd);
}

void	init_display(t_win *mlg, char *map)
{
	int			length;
	int			width;
	t_map_info	map_info;

	length = 0;
	width = 0;
	map_info = read_map(map);
	length = 64 * (map_info.line_length - 1);
	width = 64 * map_info.num_lines;
	mlg->length = length;
	mlg->width = width;
	mlg->ptr = NULL;
	mlg->ptr = mlx_init();
	if (!mlg->ptr)
		exit(1);
	set_img(mlg);
	mlg->win = mlx_new_window(mlg->ptr, length, width, "so_long");
	init_map(mlg, map);
}
