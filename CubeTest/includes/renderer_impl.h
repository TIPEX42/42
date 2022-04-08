/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_impl.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:29:39 by njennes           #+#    #+#             */
/*   Updated: 2022/04/08 18:43:23 by njennes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_IMPL_H
# define RENDERER_IMPL_H

//Colors
int		get_color(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

//Rendering
void	render_wall_column(int x, int color, int distance);

#endif
