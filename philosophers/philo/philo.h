/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:26:19 by                   #+#    #+#             */
/*   Updated: 2022/01/06 18:08:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_mutex
{
	int				init;
	pthread_mutex_t	m;
}					t_mutex;

typedef struct s_philo
{
	int			id;
	int			is_eating;
	suseconds_t	tb_eat;
	suseconds_t	ts_eat;
	suseconds_t	tt_eat;
	suseconds_t	ts_think;
	suseconds_t	ts_sleep;
	suseconds_t	tt_sleep;
	int			is_dead;
	pthread_t	thread;
	t_mutex		lfork;
	t_mutex		rfork;
	int			*cycle;
}				t_philo;

int		ft_printf(const char *str, ...);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(long n, int fd);
int		ft_putnbr_base_fd(size_t nbr, char *base, int fd);
int		ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(char *str);
void	ft_mutex_init(t_mutex *mutex);

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(int c);

void	*ft_calloc(size_t count, size_t size);

#endif
