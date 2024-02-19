/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:46:32 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/19 16:36:37 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
    t_win   mlg;
    char    *img_addr;
    int     x = 0;
    int     y = 0;
    int     length = 1024;
    int     width = 1024;
    int     color = 0;
    
    mlg.ptr = mlx_init();
    mlg.win = mlx_new_window(mlg.ptr, length, width, "NAHUI");
    set_img(&mlg);
    put_wall(&mlg, length, width);
    put_bee(&mlg);
    put_floor(&mlg);
    put_collectible(&mlg);
    mlx_key_hook(mlg.win, close_win, &mlg);
    mlx_loop(mlg.ptr);
     
	return (0);
}