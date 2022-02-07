/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:26:19 by                   #+#    #+#             */
/*   Updated: 2022/01/06 18:08:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

typedef struct s_infos
{
	int					sigs;
	int					last;
	int					handling;
	int					got_length;
	int					str_length;
	int					max_length;
	int					got_str;
	int					got_hash;
	int					hash;
	int					curr_length;
	int					client_pid;
	int					current;
	int					can_send;
	int					send_mode;
	char				*str;
	struct sigaction	sa;
}						t_infos;

#endif