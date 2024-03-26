/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:34:17 by abentaye          #+#    #+#             */
/*   Updated: 2024/03/26 13:29:14 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_copy(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**copy_map(char **map)
{
	char	**map_copy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	map_copy = (char **)malloc((i + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	map_copy[i] = 0;
	i = 0;
	while (map[i])
	{
		map_copy[i] = (char *)malloc(ft_strlen(map[i]) + 1);
		if (!map_copy[i])
		{
			map_copy[i] = 0;
			free_map_copy(map_copy);
			return (NULL);
		}
		ft_strcpy(map_copy[i], map[i]);
		i++;
	}
	map[i] = 0;
	return (map_copy);
}

t_reachable_pair	reachable(t_map_lookup map, int curr_x, int curr_y)
{
	t_reachable_pair	west_pair;
	t_reachable_pair	east_pair;
	t_reachable_pair	south_pair;
	t_reachable_pair	north_pair;
	t_reachable_pair	pair;

	pair = (t_reachable_pair){0, 0};
	if (curr_x < 0 || curr_y < 0 || curr_x >= map.max_x
		|| curr_y >= map.max_y || map.map[curr_x][curr_y] == '1')
		return (pair);
	if (map.map[curr_x][curr_y] == 'C')
		pair.collectibles += 1;
	if (map.map[curr_x][curr_y] == 'E')
		pair.exit += 1;
	map.map[curr_x][curr_y] = '1';
	west_pair = reachable(map, curr_x -1, curr_y);
	east_pair = reachable(map, curr_x +1, curr_y);
	south_pair = reachable(map, curr_x, curr_y -1);
	north_pair = reachable(map, curr_x, curr_y +1);
	pair.exit += west_pair.exit + east_pair.exit
		+ south_pair.exit + north_pair.exit;
	pair.collectibles += west_pair.collectibles + east_pair.collectibles
		+ south_pair.collectibles + north_pair.collectibles;
	return (pair);
}

int	is_finishable(t_win *mlg, t_map_info *map_info)
{
	char				**map_copy;
	t_reachable_pair	pair;
	t_map_lookup		map;

	pair = (t_reachable_pair){0, 0};
	map_copy = copy_map(mlg->map);
	if (!map_copy)
		return (1);
	map = (t_map_lookup){map_copy, map_info->num_lines, map_info->line_length};
	pair = reachable(map, map_info->player_x / 64, map_info->player_y / 64);
	free_map_copy(map_copy);
	return (pair.exit && pair.collectibles == mlg->collectibles);
}
