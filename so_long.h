/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:30:38 by kferterb          #+#    #+#             */
/*   Updated: 2021/11/28 18:33:37 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_kferterb
{
	char	**map;
	void	**img;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_struct;

int			quit(void);
char		*gnl(int fd);
void		ft_err_not_map(void);
void		ft_err_open_map(void);
void		ft_err_map(void);
void		ft_err_correct_map(void);
void		ft_err_format(void);
void		ft_err_object(void);
void		ft_err_symbol(void);
void		ft_map_check_string(int *len, int *count, char **argv);
void		ft_map_count(int *len, int *count, char **argv);
void		ft_check_string(int count, int len, int i, char *str);
void		ft_map_check_object(char **argv);
void		ft_check_object(int *c, int *e, int *p, char *str);
void		ft_check_format(char *argv);
char		**ft_save_map(int count, char *argv);
void		**ft_init_img(void *mlx_ptr);

void		ft_draw_map(void *mlx_ptr, void	*win_ptr, void	**img, char **map);
void		*ft_select_image(void **img, char ch);

char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *str);
int			ft_key_hook(int key, t_struct *var);
int			ft_walker(t_struct *var, int key);
void		ft_find_player(char **map, int *x, int *y);
void		ft_walker_add(int *x, int	*y, int key);
int			ft_check_c(char **map);
void		ft_putnbr_fd(int n, int fd);
long int	ft_count_r(int n);
void		ft_logic(int fd, int n, int r);

#endif
