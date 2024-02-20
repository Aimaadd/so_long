/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:36:26 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/20 17:41:46 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void init_display(t_win *mlg)
{
    mlg->ptr = mlx_init();
    mlg->win = mlx_new_window(mlg->ptr, 640, 640, "so_long");
    set_img(mlg);
}