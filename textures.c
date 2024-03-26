/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:36:00 by abentaye          #+#    #+#             */
/*   Updated: 2024/03/26 15:05:04 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	set_img(t_win *content)
{
	int	res;

	res = 64;
	if (!BEE || !CRATE || !FLOOR || !EXIT)
		ft_error();
	content->img.wall = mlx_xpm_file_to_image(content->ptr, CRATE, &res, &res);
	content->img.player = mlx_xpm_file_to_image(content->ptr, BEE, &res, &res);
	content->img.floor = mlx_xpm_file_to_image(content->ptr, FLOOR, &res, &res);
	content->img.collectible = mlx_xpm_file_to_image(content->ptr, \
												HONEY, &res, &res);
	content->img.exit = mlx_xpm_file_to_image(content->ptr, EXIT, &res, &res);
	if (content->img.wall == NULL || content->img.player == NULL
		|| content->img.floor == NULL || content->img.collectible == NULL)
		ft_error();
}

int	ft_get_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

void	ft_fill_res(int size, int offset, int n, char *res)
{
	while (size > offset)
	{
		res[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	int		offset;
	int		size;
	char	*res;

	offset = 0;
	size = ft_get_size(n);
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (0);
	if (n == -2147483648)
	{
		res[0] = '-';
		res[1] = '2';
		n = 147483648;
		offset = 2;
	}
	if (n < 0)
	{
		res[0] = '-';
		offset = 1;
		n = -n;
	}
	ft_fill_res(size, offset, n, res);
	res[size] = '\0';
	return (res);
}

void	disp_move(t_win *mlg)
{
	char	*moves_str;

	moves_str = ft_itoa(mlg->moves);
	write(1, "Moves: ", 7);
	write(1, ft_itoa(mlg->moves), ft_strlen(moves_str));
	write(1, "\n", 1);
	free(moves_str);
}
