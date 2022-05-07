/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:26:19 by                   #+#    #+#             */
/*   Updated: 2022/05/07 13:56:11 by njennes          ###   ########.fr       */
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

typedef struct s_mutex
{
	int				init;
	pthread_mutex_t	m;
}					t_mutex;

typedef struct s_data
{
	struct timeval	start_ts;
	t_mutex			ds_mutex;
	int				death_switch;
	t_mutex			running_mutex;
	int				running;
}	t_data;

typedef struct s_philo
{
	int				id;
	t_mutex			done_mutex;
	int				done;
	int64_t			tmax_since_eat;
	int64_t			eats;
	int64_t			max_eats;
	struct timeval	ts_eat;
	t_mutex			eat_mutex;
	int64_t			tt_eat;
	int64_t			tt_sleep;
	pthread_t		thread;
	t_mutex			*lfork;
	int				has_lfork;
	t_mutex			*rfork;
	int				has_rfork;
	t_data			*data;
}					t_philo;

void	*philo_live(void *ptr);
int		philo_print(t_philo *philo, const char *msg);

void	lock_philo_eat(t_philo *philo);
void	unlock_philo_eat(t_philo *philo);

int		is_philo_done(t_philo *philo);
int		set_philo_done(t_philo *philo);
int		get_philo_alive(t_data *data);

int		ft_printf(const char *str, ...);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(long n, int fd);
int		ft_putnbr_base_fd(size_t nbr, char *base, int fd);
int		ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(char *str);

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(int c);

void	*ft_calloc(size_t count, size_t size);

int		check_args(size_t argc, char **argv);
void	simulate(t_data *data, t_philo *philos, size_t n);
t_philo	*init_philos(size_t n, char **argv, int args, t_data *data);
void	destroy_forks(t_mutex *forks, size_t n);
void	destroy_data(t_data *data);
t_mutex	*init_forks(size_t n);
int		init_forks_philos(t_mutex **forks, t_philo **philos, size_t n);
void	init_philo(t_philo *philo, int argc, char **argv, t_data *data);
void	init_philo_2(t_philo *philos, size_t i, size_t n, t_mutex *forks);
void	init_mutex(t_mutex *mutex);
void	init_data(t_data *data, int running);

int64_t	time_diff(struct timeval start, struct timeval end);
int		my_sleep(t_philo *philo, int64_t time);
int		my_eat(t_philo *philo, int64_t time);

void	lock_lfork(t_philo *philo);
void	lock_rfork(t_philo *philo);
void	unlock_forks(t_philo *philo);
void	set_death_switch(t_data *data, int status);
int		get_death_switch(t_data *data);

#endif
