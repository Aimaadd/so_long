/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:39:56 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/22 16:12:32 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

t_map_info	read_map(char *map)
{
    int		fd;
    char	*line;
    t_map_info map_info;

    map_info = (t_map_info){0, 0, 0, 0};
    fd = open(map, O_RDONLY);
    if (fd < 0)
        exit(1);
    while ((line = get_next_line(fd)))
    {
        if (!map_info.line_length)
            map_info.line_length = ft_strlen(line);
        else if (ft_strlen(line) != map_info.line_length)
            exit(1);
        for (int i = 0; line[i]; i++)
        {
            if (line[i] == 'P') map_info.player_count++;
            if (line[i] == 'C') map_info.collectible_count++;
            if (line[i] == 'E') map_info.exit_count++;
        }
        map_info.num_lines++;
        free(line);
    }
    close(fd);
    return map_info;
}

void    map_check(char *map)
{
    t_map_info map_info;

    map_info = read_map(map);
    if (map_info.num_lines < 3
        || map_info.line_length < 3
        || map_info.num_lines == map_info.line_length
        || map_info.player_count != 1
        || map_info.collectible_count < 1
        || map_info.exit_count < 1)
        exit(1);
}



// one char == one 64x64 
// CRATE are around the map associated char is 1
// BEE is the player with floor under it associated char is P
// FLOOR is surrounded by CRATE and BEE associated char is 0
// HONEY is a collectible associated char is C

