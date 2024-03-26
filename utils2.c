/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:16:12 by abentaye          #+#    #+#             */
/*   Updated: 2024/03/23 13:25:39 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	check_first_last_chars(char *line, t_map_info map_info)
{
	if (line[0] != '1' || line[map_info.line_length - 2] != '1')
		ft_error();
}

void	check_all_chars(char *line, t_map_info map_info)
{
	int	j;

	j = 0;
	while (j < map_info.line_length - 1)
	{
		if (line[j] != '1')
			ft_error();
		j++;
	}
}

void	display_player(t_win *mlg, int pos_x, int pos_y)
{
	put_floor(mlg, pos_x, pos_y);
	put_player(mlg, pos_x, pos_y);
}

int	is_collectible(t_win *mlg, int x, int y)
{
	if (mlg->map[y / 64][x / 64] == 'C')
	{
		if (mlg->pos_x == x && mlg->pos_y == y)
		{
			mlg->collectibles--;
			mlg->map[y / 64][x / 64] = '0';
		}
		return (1);
	}
	if (mlg->collectibles == 0
		&& mlg->map[mlg->pos_y / 64][mlg->pos_x / 64] == 'E')
	{
		mlx_clear_window(mlg->ptr, mlg->win);
		mlx_destroy_window(mlg->ptr, mlg->win);
		exit(0);
	}
	return (0);
}

int	is_walkable(t_win *mlg, int x, int y)
{
	if (x < 0 || y < 0 || x > mlg->length || y > mlg->width)
		return (0);
	if (mlg->map[y / 64][x / 64] == '1')
		return (0);
	return (1);
}
