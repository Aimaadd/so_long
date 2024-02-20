/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:41:51 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/20 21:48:20 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
#include "./so_long.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*read_and_keep(int fd, char *remn_str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *remn_str, char *buff);
size_t	ft_strlen(const char *str);
char	*ft_get_line(char *remn_str);
char	*new_remn_str(char *remn_str);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
