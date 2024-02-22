/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:49:08 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/22 18:52:45 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_up(t_win *mlg)
{
    
}

void    move_right(t_win *mlg)
{
    
}

void    move_down(t_win *mlg)
{
    
}

void    move_left(t_win *mlg)
{
    
}

int    controls(int keycode, t_win *mlg)
{
   if (keycode == 53)
        close_win(keycode, mlg);
   if (keycode == 13 || keycode == 126)
        move_up(mlg);
    if (keycode == 2 || keycode == 124)
        move_right(mlg);
    if (keycode == 1 || keycode == 125)
        move_down(mlg);
    if (keycode == 0 || keycode == 123)
        move_left(mlg);
    return (0);
}