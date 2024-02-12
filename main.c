/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:46:32 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/12 20:24:10 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct   s_win {
    void    *win;
    void    *ptr;
}               t_win;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

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
    printf("key pressed\n");
	mlx_destroy_window(var->ptr, var->win);
    free(var->ptr);
    free(var);
	return (0);
}

int main()
{
    t_win   *mlx_ptr;
    t_win   *mlx_win;
    t_data  img;
    int     x = 0;
    int     y = 0;
    int     length = 720;
    int     width = 480;
    
    mlx_ptr = mlx_init();
    if (!mlx_ptr)
    {
        free(mlx_ptr);
        return (1);
    }
    mlx_win = mlx_new_window(mlx_ptr, length, width, "NAHUI");
    if (!mlx_win)
    {
        free(mlx_win);
        return (1);
    }
    while (x <= length && y <= width)
    {
        mlx_pixel_put(mlx_ptr, mlx_win, x++, y, 0xFFFF00);
        if (x == length)
        {
            y++;
            x = 0;
        }
    }
    if (!mlx_win)
        return (free(mlx_ptr), 1);
    mlx_key_hook(mlx_win, close_win, mlx_win);
    printf("pas d'accord\n");
    mlx_loop(mlx_ptr);  
	return (0);
}