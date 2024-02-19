/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:46:32 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/19 13:50:15 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void    put_bee(t_win *mlg)
{
    int len;
    int x;
    int y;

    y = 0;
    x = 0;
    len = 2400;
    mlg->img.wall = mlx_xpm_file_to_image(mlg->win, BEE, &len, &len);
    mlx_put_image_to_window(mlg->ptr, mlg->win, mlg->img.wall, 64, 64);
}

void    put_images(t_win *mlg)
{
    int len;
    int x;
    int y;
    
    y = 0;
    x = 0;
    len = 19173463;
    mlg->img.wall = mlx_xpm_file_to_image(mlg->win, CRATE, &len, &len);
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

int main()
{
    t_win   mlg;
    char    *img_addr;
    int     x = 0;
    int     y = 0;
    int     length = 512;
    int     width = 512;
    int     color = 0;
    
    mlg.ptr = mlx_init();
    mlg.win = mlx_new_window(mlg.ptr, length, width, "NAHUI");
    put_images(&mlg);
    put_bee(&mlg);
    mlx_key_hook(mlg.win, close_win, &mlg);
    mlx_loop(mlg.ptr);
     
	return (0);
}