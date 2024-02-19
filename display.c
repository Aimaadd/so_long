/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:33:25 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/19 16:26:28 by abentaye         ###   ########.fr       */
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

// int disp_color(int length, int width, t_win *mlg, int color)
// {
//      int    x = 0;
//      int    y = 0;
//      while (x <= length && y <= width)
//     {
//         mlx_pixel_put(mlg->ptr, mlg->win, x++, y, color);
//         if (x == length)
//         {
//             y++;
//             x = 0;
//         }
//     }
//     return 0;
// }

void    put_wall(t_win *mlg)
{
    int len;
    int x;
    int y;
    
    y = 0;
    x = 0;
    len = 128;
    if (mlg->img.wall == NULL)
    {
        printf("raté\n");
    }
    while (x <= 512 && y <= 512)
    {
        mlx_put_image_to_window(mlg->ptr, mlg->win, mlg->img.wall, x, y);
        x += 64;
        if (x == 512)
        {
            y += 64;
            x = 0;
        }
    }
}

void    put_bee(t_win *mlg)
{
    int len;
    int x;
    int y;

    y = 0;
    x = 0;
    len = 128;
    mlx_put_image_to_window(mlg->ptr, mlg->win, mlg->img.player, 64, 64);
}

void    put_floor(t_win *mlg)
{
    int len;
    int x;
    int y;

    y = 0;
    x = 0;
    len = 128;
    mlx_put_image_to_window(mlg->ptr, mlg->win, mlg->img.floor, 128, 128);
}

void    put_collectible(t_win *mlg)
{
    int len;
    int x;
    int y;

    x = 0;
    y = 0;
    len = 256;
    put_floor(mlg);
    mlx_put_image_to_window(mlg->ptr, mlg->win, mlg->img.collectible, len, len);
}