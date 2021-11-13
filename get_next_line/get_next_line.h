/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeannot <bjeannot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:45:26 by njennes           #+#    #+#             */
/*   Updated: 2021/11/10 23:45:26 by bjeannot         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_UTILS_H
# define GET_NEXT_LINE_UTILS_H

#include <stddef.h>

int		ft_strlen(char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	*get_next_line(int fd);
char	*find_line(int fd, char *buffer, char **line);
int		ft_get_line_length(char *buffer, int bytesRead);
int		ft_add_to_line(char **line, char *buffer, int bytesRead);

#endif