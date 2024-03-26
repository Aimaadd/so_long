/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:49:08 by abentaye          #+#    #+#             */
/*   Updated: 2024/03/26 14:40:54 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_win *mlg)
{
	int	target_x;
	int	target_y;

	disp_move(mlg);
	target_y = mlg->pos_y - 64;
	target_x = mlg->pos_x;
	if (!is_walkable(mlg, target_x, target_y))
		return ;
	update_player_position(mlg, target_x, target_y);
	update_elements(mlg);
	if (!is_exit(mlg, target_x, target_y + 64))
		put_exit(mlg, mlg->pos_x, mlg->pos_y + 64);
	else
		put_floor(mlg, mlg->pos_x, mlg->pos_y + 64);
}

void	move_right(t_win *mlg)
{
	int	target_x;
	int	target_y;

	disp_move(mlg);
	target_x = mlg->pos_x + 64;
	target_y = mlg->pos_y;
	if (!is_walkable(mlg, target_x, target_y))
		return ;
	update_player_position(mlg, target_x, target_y);
	update_elements(mlg);
	if (!is_exit(mlg, target_x - 64, target_y))
		put_exit(mlg, mlg->pos_x - 64, mlg->pos_y);
	else
		put_floor(mlg, mlg->pos_x - 64, mlg->pos_y);
}

void	move_down(t_win *mlg)
{
	int	target_x;
	int	target_y;

	disp_move(mlg);
	target_y = mlg->pos_y + 64;
	target_x = mlg->pos_x;
	if (!is_walkable(mlg, target_x, target_y))
		return ;
	update_player_position(mlg, target_x, target_y);
	update_elements(mlg);
	if (!is_exit(mlg, target_x, target_y - 64))
		put_exit(mlg, mlg->pos_x, mlg->pos_y -64);
	else
		put_floor(mlg, mlg->pos_x, mlg->pos_y - 64);
}

void	move_left(t_win *mlg)
{
	int	target_x;
	int	target_y;

	disp_move(mlg);
	target_x = mlg->pos_x - 64;
	target_y = mlg->pos_y;
	if (!is_walkable(mlg, target_x, target_y))
		return ;
	update_player_position(mlg, target_x, target_y);
	update_elements(mlg);
	if (!is_exit(mlg, target_x + 64, target_y))
		put_exit(mlg, mlg->pos_x + 64, mlg->pos_y);
	else
		put_floor(mlg, mlg->pos_x + 64, mlg->pos_y);
}

int	controls(int keycode, t_win *mlg)
{
	if (keycode == 53)
		close_win(mlg);
	if (keycode == 13 || keycode == 126)
	{
		move_up(mlg);
		mlg->moves++;
	}
	if (keycode == 2 || keycode == 124)
	{
		move_right(mlg);
		mlg->moves++;
	}
	if (keycode == 1 || keycode == 125)
	{
		move_down(mlg);
		mlg->moves++;
	}
	if (keycode == 0 || keycode == 123)
	{
		move_left(mlg);
		mlg->moves++;
	}
	return (0);
}
