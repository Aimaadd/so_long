/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:46:32 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/22 18:47:36 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int args_handler(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Error\n");
        exit(1);
    }
    if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
    {
        printf("Error\n");
        exit(1);
    }
    return (0);
}

int main(int argc , char **argv)
{
    t_win   mlg;
    int     length = 512;
    int     width = 512;
    
    args_handler(argc, argv);
    map_check(argv[1]);
    init_display(&mlg, length, width);
    put_wall(&mlg, length, width);
    put_floor(&mlg);
    put_bee(&mlg);
    put_collectible(&mlg);
    put_exit(&mlg);
    mlx_key_hook(mlg.win, controls, &mlg);
    mlx_hook(mlg.win, 17, 0, (void *)exit, 0);
    mlx_loop(mlg.ptr);
     
	return (0);
}