/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:46:32 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/06 20:45:51 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx2/mlx.h"
#include <stdlib.h>



int main()
{
    void    *mlx_ptr;
    void    *mlx_win;
    
    mlx_ptr = mlx_init();
    if (!mlx_ptr)
    {
        free(mlx_ptr);
        return (1);
    }
	mlx_win = mlx_new_window(mlx_ptr, 1920, 1080, "Hello world!");
	if (!mlx_win)
		return (free(mlx_ptr), 1);
    mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, mlx_win);
	free(mlx_ptr);
	return (0);
}