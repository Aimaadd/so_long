/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:36:26 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/21 13:33:18 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void init_display(t_win *mlg, int length, int width)
{
    mlg->ptr = mlx_init();
    mlg->win = mlx_new_window(mlg->ptr, length, width, "so_long");
    set_img(mlg);
}

void init_map(t_win *mlg)
{
    set_img(mlg);
}