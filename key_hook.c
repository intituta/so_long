/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:50:25 by kferterb          #+#    #+#             */
/*   Updated: 2021/11/28 19:52:47 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_c(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				return (1);
			(x)++;
		}
		(y)++;
	}
	return (0);
}

void	ft_walker_add(int *x, int	*y, int key)
{
	if (key == 0)
		*x -= 1;
	if (key == 1)
		*y += 1;
	if (key == 2)
		*x += 1;
	if (key == 13)
		*y -= 1;
}

void	ft_find_player(char **map, int *x, int *y)
{
	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

int	ft_walker(t_struct *var, int key)
{
	int	x;
	int	y;
	int	x_x;
	int	y_y;

	ft_find_player(var->map, &x, &y);
	y_y = y;
	x_x = x;
	ft_walker_add(&x, &y, key);
	if (var->map[y][x] == 'E' && ft_check_c(var->map) == 0)
		exit (0);
	if (var->map[y][x] == 'V')
		exit(0);
	if (var->map[y][x] == '1' || var->map[y][x] == 'E')
		return (0);
	else
	{
		var->map[y][x] = 'P';
		var->map[y_y][x_x] = '0';
	}
	if (ft_check_c(var->map) == 0)
		var->img[4] = mlx_xpm_file_to_image(var->mlx_ptr,
				"img/exit_new.xpm", &x, &y);
	return (1);
}

int	ft_key_hook(int key, t_struct *var)
{
	static int	step = 0;

	if (key == 53)
		exit(0);
	if (key == 0 || key == 1 || key == 2 || key == 13)
	{
		step += ft_walker(var, key);
		write(1, "Step:", 5);
		ft_putnbr_fd(step, 1);
		write(1, "\n", 1);
		ft_draw_map(var->mlx_ptr, var->win_ptr, var->img, var->map);
	}
	return (0);
}
