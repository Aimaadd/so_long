/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:33:25 by abentaye          #+#    #+#             */
/*   Updated: 2024/03/23 13:11:47 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	put_wall(t_win *mlg, int pos_x, int pos_y)
{
	mlx_put_image_to_window(mlg->ptr, mlg->win, mlg->img.wall, pos_x, pos_y);
}

void	put_floor(t_win *mlg, int pos_x, int pos_y)
{
	mlx_put_image_to_window(mlg->ptr, mlg->win, mlg->img.floor, pos_x, pos_y);
}

void	put_player(t_win *mlg, int pos_x, int pos_y)
{
	mlx_put_image_to_window(mlg->ptr, mlg->win, mlg->img.player, pos_x, pos_y);
}

void	put_collectible(t_win *mlg, int pos_x, int pos_y)
{
	mlx_put_image_to_window(mlg->ptr, mlg->win,
		mlg->img.collectible, pos_x, pos_y);
}

void	put_exit(t_win *mlg, int pos_x, int pos_y)
{
	mlx_put_image_to_window(mlg->ptr, mlg->win, mlg->img.exit, pos_x, pos_y);
}
