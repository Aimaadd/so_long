/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:36:00 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/23 16:21:14 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	set_img(t_win *content)
{
	int	res;

	res = 64;
	content->img.wall = mlx_xpm_file_to_image(content->ptr, CRATE, &res, &res);
	content->img.player = mlx_xpm_file_to_image(content->ptr, BEE, &res, &res);
	content->img.floor = mlx_xpm_file_to_image(content->ptr, FLOOR, &res, &res);
	content->img.collectible = mlx_xpm_file_to_image(content->ptr, HONEY, &res, &res);
	content->img.exit = mlx_xpm_file_to_image(content->ptr, EXIT, &res, &res);
}