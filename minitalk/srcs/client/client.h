/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:26:19 by                   #+#    #+#             */
/*   Updated: 2022/01/06 18:08:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

typedef struct s_infos
{
	int					sigs;
	int					last;
	int					handling;
	int					got_hash;
	int					server_hash;
	struct sigaction	sa;
}						t_infos;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	*ft_calloc(size_t n, size_t size);
void	ft_memset(void *dest, int value, size_t len);

#endif