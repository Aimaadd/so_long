/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:46:32 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/13 19:35:30 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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

t_win  new_img(void *mlg)
{
    t_win  img;
    img.img = mlx_xpm_file_to_image(mlg, CRATE, &img.width, &img.length);
    return (img);
}

int main()
{
    t_win   mlg;
    t_data  img;
    char    *img_addr;
    int     x = 0;
    int     y = 0;
    int     length = 720;
    int     width = 480;
    int     color = 0;
    
    mlg.ptr = mlx_init();
    mlg.win = mlx_new_window(mlg.ptr, length, width, "NAHUI");
    img.img = mlx_new_image(mlg.ptr, length, width);
    img_addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_put_image_to_window(mlg.ptr, mlg.win, img.img, mlg.width, mlg.length);
    // new_img(&mlg);
    // disp_color(length, width, mlg, color++);
    mlx_key_hook(mlg.win, close_win, &mlg);
    // mlx_loop_hook(mlg, render_next, );
    mlx_loop(mlg.ptr);
     
	return (0);
}