/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:44:07 by njennes           #+#    #+#             */
/*   Updated: 2022/04/08 18:46:42 by njennes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define EMPTY 0
# define WALL 1

typedef struct	s_map
{
	int			width;
	int			height;
	int			**walls;
}				t_map;

#endif
