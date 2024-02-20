/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:39:56 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/20 22:09:47 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void read_map(char *map)
{
    int fd;
    char *line;
    char ret;
    int line_length = 0;
    int num_lines = 0;

    fd = open(map, O_RDONLY);
    if (fd < 0)
    {
        printf("Error\n");
        exit(1);
    }
    while ((ret = *get_next_line(fd)) > 0)
    {
        if (line_length == 0)
        {
            line_length = ft_strlen(line);
        }
        else if (ft_strlen(line) != line_length)
        {
            printf("Error: All lines must have the same length.\n");
            exit(1);
        }
        num_lines++;
        free(line);
    }
    free(line);
    close(fd);
    printf("Line length: %d\n", line_length);
    printf("Number of lines: %d\n", num_lines);
}

// one char == one 64x64 
// CRATE are around the map associated char is 1
// BEE is the player with floor under it associated char is P
// FLOOR is surrounded by CRATE and BEE associated char is 0
// HONEY is a collectible associated char is C

