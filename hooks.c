/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:39:02 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/23 16:16:34 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	close_win(int keycode, t_win *var)
{
	if (keycode == 53)
	{
		mlx_clear_window(var->ptr, var->win);
		mlx_destroy_window(var->ptr, var->win);
		exit(0);
	}
	return (0);
}