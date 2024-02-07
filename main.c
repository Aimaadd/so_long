/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:46:32 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/07 19:48:24 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int draw_line(void *mlx_ptr, void *mlx_win, int startX, int startY, int endX, int endY, int color)
{
    while (startX != endX)
    {
        mlx_pixel_put(mlx_ptr, mlx_win, startX++, startY++, 0x0000FF00);
    }
    mlx_loop(mlx_ptr);
    return 1;
}

int main()
{
    void    *mlx_ptr;
    void    *mlx_win;
    t_data  img;
    
    mlx_ptr = mlx_init();
    if (!mlx_ptr)
    {
        free(mlx_ptr);
        return (1);
    }
    mlx_win = mlx_new_window(mlx_ptr, 1280, 720, "NAHUI");
    img.img = mlx_new_image(mlx_ptr, 1280 ,720);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    draw_line(mlx_ptr, mlx_win, 0, 0, 1280, 1280, 0x00FF0000);
    // my_mlx_pixel_put(&img, width, length, 0x00FF0000);
    mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
    if (!mlx_win)
        return (free(mlx_ptr), 1);
    mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, mlx_win);
	free(mlx_ptr);
	return (0);
}