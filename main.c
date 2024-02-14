/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:46:32 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/14 17:50:33 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "so_long.h"

int draw_line(void *mlx_ptr, void *mlx_win, int startX, int startY, int endX, int endY, int color)
{
    while (startX != endX || startX != endY)
    {
        mlx_pixel_put(mlx_ptr, mlx_win, startX, startY, 0x00FF00F0);
        startX++;
    }
    mlx_loop(mlx_ptr);
    return 1;
}

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

int disp_color(int length, int width, t_win *mlg, int color)
{
     int    x = 0;
     int    y = 0;
     while (x <= length && y <= width)
    {
        mlx_pixel_put(mlg->ptr, mlg->win, x++, y, color);
        if (x == length)
        {
            y++;
            x = 0;
        }
    }
    return 0;
}

// int render_next(void *astruct)
// {
//      while (color <= INT_MAX)
//     {
//         if (color == INT_MAX)
//             color = 0;
//         else
//         {
//             disp_color(length, width, mlg, color);
//             color++;
//         }
//     } 
// }

int mouse_hi_bye(int keycode, t_win *var)
{
    if (keycode == ON_EXPOSE)
        printf("hi\n");
    if (keycode == ON_MOUSEUP)
        printf("bye\n");
    return 0;
}

void    put_images(t_win *mlg)
{
    int len;

    len = 32;
    mlg->img.wall = mlx_xpm_file_to_image(mlg->win, CRATE, &len, &len);
    if (mlg->img.wall == NULL)
    {
        printf("raté\n");
    }
    mlx_put_image_to_window(mlg->ptr, mlg->win, mlg->img.wall, len, len);
}

int main()
{
    t_win   mlg;
    char    *img_addr;
    int     x = 0;
    int     y = 0;
    int     length = 720;
    int     width = 480;
    int     color = 0;
    
    mlg.ptr = mlx_init();
    mlg.win = mlx_new_window(mlg.ptr, length, width, "NAHUI");
    put_images(&mlg);
    mlx_key_hook(mlg.win, close_win, &mlg);
    mlx_loop(mlg.ptr);
     
	return (0);
}