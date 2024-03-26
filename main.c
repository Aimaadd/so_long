/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:46:32 by abentaye          #+#    #+#             */
/*   Updated: 2024/03/26 13:19:14 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	is_exit(t_win *mlg, int x, int y)
{
	if (mlg->map[y / 64][x / 64] == 'E')
		return (0);
	return (1);
}

void	update_player_position(t_win *mlg, int x, int y)
{
	mlg->pos_x = x;
	mlg->pos_y = y;
	is_collectible(mlg, mlg->pos_x, mlg->pos_y);
}

void	update_elements(t_win *mlg)
{
	mlx_put_image_to_window(mlg->ptr, mlg->win, mlg->img.player,
		mlg->pos_x, mlg->pos_y);
	put_player(mlg, mlg->pos_x, mlg->pos_y);
}

int	args_handler(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_win		mlg;
	t_map_info	map_info;

	mlg.moves = 0;
	args_handler(argc, argv);
	mlg.map_name = argv[1];
	map_info = map_check(mlg.map_name, &mlg);
	mlg.map = malloc(sizeof(char *) * (map_info.num_lines + 1));
	if (!mlg.map)
		ft_error();
	mlg.map[map_info.num_lines] = NULL;
	mlg.width = read_map(mlg.map_name).num_lines;
	mlg.map = get_map(&mlg, mlg.map, 0, 0);
	if (mlg.map == NULL)
		ft_error();
	if (!is_finishable(&mlg, &map_info))
		ft_error();
	init_display(&mlg, mlg.map_name);
	player_pos(&mlg);
	mlx_key_hook(mlg.win, controls, &mlg);
	mlx_hook(mlg.win, 17, 0, (void *)exit, 0);
	mlx_loop(mlg.ptr);
	return (0);
}
