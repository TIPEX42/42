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
# include <sys/time.h>

# define IDLE 0
# define EATING 1
# define THINKING 2
# define SLEEPING 3

typedef struct s_mutex
{
	int				init;
	pthread_mutex_t	m;
}					t_mutex;

typedef struct s_timestamp
{
	uint64_t	usecs;
	uint64_t	secs;
}				t_timestamp;

typedef struct s_philo
{
	int			id;
	int         state;
	uint64_t	tmax_since_eat;
	t_timestamp ts_eat;
	uint64_t	tt_eat;
	t_timestamp	ts_sleep;
	uint64_t	tt_sleep;
	int			is_dead;
	pthread_t	thread;
	t_mutex		*lfork;
	t_mutex		*rfork;
}				t_philo;

void	*philo_live(void *ptr);
void	philo_sleep(t_philo *philo, uint64_t time);

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

int		check_args(size_t argc, char **argv);
void	simulate(t_philo *philos, size_t n);
t_philo	*init_philos(size_t n, char **argv);
void	destroy_forks(t_mutex *forks, size_t n);
t_mutex	*init_forks(size_t n);

void	set_timestamp(t_timestamp *timestamp);
int		time_elapsed_since(t_timestamp ts, uint64_t time);

#endif
