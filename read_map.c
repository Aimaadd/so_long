/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:39:56 by abentaye          #+#    #+#             */
/*   Updated: 2024/03/23 13:24:03 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	check_line_length(t_map_info *map_info, char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (!map_info->line_length)
		map_info->line_length = i;
	else if (i != map_info->line_length)
		ft_error();
}

void	update_map_info(t_map_info *map_info, char *line, int line_num)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
		{
			map_info->player_count++;
			map_info->player_x = i * 64;
			map_info->player_y = line_num * 64;
		}
		if (line[i] == 'C')
			map_info->collectible_count++;
		if (line[i] == 'E')
			map_info->exit_count++;
		i++;
	}
}

t_map_info	read_map(char *map)
{
	int			fd;
	char		*line;
	t_map_info	map_info;

	map_info = (t_map_info){0, 0, 0, 0, 0, 0, 0};
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error();
	line = get_next_line(fd);
	while (line)
	{
		check_line_length(&map_info, line);
		update_map_info(&map_info, line, map_info.num_lines);
		map_info.num_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map_info);
}

t_map_info	map_check(char *map, t_win *mlg)
{
	t_map_info	map_info;

	map_info = read_map(map);
	closed_map(map, map_info);
	if (map_info.num_lines < 3
		|| map_info.line_length < 3
		|| map_info.num_lines == map_info.line_length
		|| map_info.player_count != 1
		|| map_info.collectible_count < 1
		|| map_info.exit_count < 1
		|| map_info.line_length >= 50
		|| map_info.num_lines >= 24
		|| map_info.exit_count > 1)
		ft_error();
	mlg->collectibles = map_info.collectible_count;
	return (map_info);
}

int	closed_map(char *map, t_map_info map_info)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error();
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (i == 0 || i == map_info.num_lines - 1)
			check_all_chars(line, map_info);
		else
			check_first_last_chars(line, map_info);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
