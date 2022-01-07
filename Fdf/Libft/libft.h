/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:34:44 by njennes           #+#    #+#             */
/*   Updated: 2022/01/06 12:41:27 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

# define BUFFER_SIZE 1024

# define PI 3.141592653589793
# define TWO_PI 6.28318530718
# define HALF_PI 1.57079632679

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_StringV
{
	char	*chars;
	int		size;
}			t_StringV;

typedef struct s_vec2
{
	float	x;
	float	y;
}			t_vec2;

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}			t_vec3;

typedef struct s_vec4
{
	float	x;
	float	y;
	float	z;
	float	w;
}			t_vec4;

typedef struct s_mat4
{
	float	m[4][4];
}			t_mat4;

typedef struct s_proj
{
	float	right;
	float	left;
	float	top;
	float	bot;
	float	far;
	float	near;
	float	aspect;
}			t_proj;

//Character Testing
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);

//C style Strings Manipulation
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		**ft_split(char const *s, char c);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

//Stringview
t_StringV	sv_create(const char *str);
t_StringV	sv_copy(const t_StringV other);
void		sv_delete(const t_StringV stringV);

//Basic IO
int			ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(char *s, int fd);
int			ft_putendl_fd(char *s, int fd);
int			ft_putnbr_fd(long n, int fd);
int			ft_putnbr_base_fd(size_t nbr, char *base, int fd);
char		*ft_get_next_line(int fd);
int			ft_printf(const char *str, ...);

//Memory Management
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_calloc(size_t count, size_t size);

//lists
int			ft_lstsize(t_list *lst);
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstadd_front(t_list **alst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//Maths Basics
double		ft_abs(double nb);
double		ft_sqrt(double nb);
long		ft_fact(long value);
double		ft_pow2(double value);
double		ft_cos(double x);
double		ft_sin(double x);
double		ft_modf(double x, double y);

//Vectors
t_vec2		vec2(float x, float y);
t_vec2		vec2_copy(t_vec2 old);
t_vec2		vec2_zero(void);
t_vec2		vec2_set(float value);
t_vec2		*vec2_add(t_vec2 *self, const t_vec2 other);
t_vec2		*vec2_multi(t_vec2 *self, long value);
t_vec2		*vec2_multf(t_vec2 *self, float value);
t_vec2		*vec2_multv2(t_vec2 *self, t_vec2 vec);
t_vec2		*vec2_divi(t_vec2 *self, long value);
t_vec2		*vec2_divf(t_vec2 *self, float value);
t_vec2		*vec2_divv2(t_vec2 *self, t_vec2 vec);
t_vec2		*vec2_normalize(t_vec2 *vec);
t_vec2		vec2_normalized(t_vec2 vec);
float		vec2_mag(t_vec2 vec);

t_vec3		vec3(float x, float y, float z);
t_vec3		vec3_copy(t_vec3 old);
t_vec3		vec3_zero(void);
t_vec3		vec3_set(float value);
t_vec3		*vec3_add(t_vec3 *self, const t_vec3 other);
t_vec3		*vec3_multi(t_vec3 *self, long value);
t_vec3		*vec3_multf(t_vec3 *self, float value);
t_vec3		*vec3_multv2(t_vec3 *self, t_vec3 vec);
t_vec3		*vec3_divi(t_vec3 *self, long value);
t_vec3		*vec3_divf(t_vec3 *self, float value);
t_vec3		*vec3_divv3(t_vec3 *self, t_vec3 vec);
t_vec3		*vec3_normalize(t_vec3 *vec);
t_vec3		vec3_normalized(t_vec3 vec);
float		vec3_mag(t_vec3 vec);

t_vec4		vec4(float x, float y, float z, float w);
t_vec4		vec4_copy(t_vec4 old);
t_vec4		vec4_zero(void);
t_vec4		vec4_set(float value);
t_vec4		*vec4_add(t_vec4 *self, const t_vec4 other);
t_vec4		*vec4_multi(t_vec4 *self, long value);
t_vec4		*vec4_multf(t_vec4 *self, float value);
t_vec4		*vec4_multv2(t_vec4 *self, t_vec4 vec);
t_vec4		*vec4_divi(t_vec4 *self, long value);
t_vec4		*vec4_divf(t_vec4 *self, float value);
t_vec4		*vec4_divv4(t_vec4 *self, t_vec4 vec);

//Matrix
t_mat4		mat4(float value);
t_mat4		mat4_copy(t_mat4 old);
t_mat4		mat4_zero(void);
t_mat4		mat4_identity(void);
t_mat4		*mat4_multi(t_mat4 *self, int value);
t_mat4		*mat4_multf(t_mat4 *self, float value);
t_vec4		mat4_multv4(t_mat4 self, t_vec4 other);
t_mat4		mat4_multm4(t_mat4 self, t_mat4 other);
t_mat4		mat4_translate(t_mat4 self, t_vec3 vec);
t_mat4		mat4_rotatex(t_mat4 self, float value);
t_mat4		mat4_rotatey(t_mat4 self, float value);
t_mat4		mat4_rotatez(t_mat4 self, float value);
t_mat4		mat4_rotate(t_vec3 vec);
t_mat4		mat4_translate(t_mat4 self, t_vec3 vec);
t_mat4		mat4_ortho(t_proj proj);
t_mat4		mat4_scalef(float value);
t_mat4		mat4_scalev3(t_vec3 vec);

#endif