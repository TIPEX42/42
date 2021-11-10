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
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

int		read_new_file(char **fileRead);
int	ft_concat(char **fileRead, char *buffer, size_t bytesRead);
char	*get_next_line(int fd);
char	*find_line(int fd, char **fileRead);
char	*ft_cut_line(char **fileRead);

#endif