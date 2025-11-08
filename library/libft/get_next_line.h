/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpichyal <bpichyal@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:06:23 by bpichyal          #+#    #+#             */
/*   Updated: 2025/11/09 00:07:43 by bpichyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
#include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*read_file(int fd, char *bowl);
char	*read_tukar(int fd, char *bowl, char *bucket, int *byte_read);
char	*extract_line(char *s);
char	*save_leftovers(char *s);
char	*get_next_line(int fd);

int		has_fish(char *s);

#endif
