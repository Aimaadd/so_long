/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:39:56 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/20 16:11:29 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void    read_map(char *map)
{
    int fd;
    char *line;
    int ret;

    fd = open(map, O_RDONLY);
    if (fd < 0)
    {
        printf("Error\n");
        exit(1);
    }
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
    free(line);
    close(fd);
}

// one char == one 64x64 
// CRATE are around the map associated char is 1
// BEE is the player with floor under it associated char is P
// FLOOR is surrounded by CRATE and BEE associated char is 0
// HONEY is a collectible associated char is C

