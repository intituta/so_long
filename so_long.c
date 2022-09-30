/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:19:58 by kferterb          #+#    #+#             */
/*   Updated: 2021/11/28 19:49:56 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit(void)
{
	exit(0);
	return (0);
}

void	**ft_init_img(void *mlx_ptr)
{
	int		i;
	int		j;
	void	**img;

	i = 0;
	j = 0;
	img = (void **)malloc(sizeof(void *) * 6);
	img[0] = mlx_xpm_file_to_image(mlx_ptr, "img/player.xpm", &i, &j);
	img[1] = mlx_xpm_file_to_image(mlx_ptr, "img/sand.xpm", &i, &j);
	img[2] = mlx_xpm_file_to_image(mlx_ptr, "img/wall.xpm", &i, &j);
	img[3] = mlx_xpm_file_to_image(mlx_ptr, "img/item.xpm", &i, &j);
	img[4] = mlx_xpm_file_to_image(mlx_ptr, "img/exit.xpm", &i, &j);
	img[5] = mlx_xpm_file_to_image(mlx_ptr, "img/enemy.xpm", &i, &j);
	return (img);
}

char	**ft_save_map(int count, char *argv)
{
	int		i;
	int		fd;
	char	**map;

	map = malloc(sizeof(char *) * count + 1);
	if (!map)
		exit(0);
	fd = open(argv, O_RDONLY);
	i = 0;
	while (i < count)
	{
		map[i] = gnl(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	ft_check_format(char *argv)
{
	size_t	len;

	len = ft_strlen(argv);
	if (argv[len - 4] == '.')
	{
		if (argv[len - 3] == 'b')
		{
			if (argv[len - 2] == 'e')
			{
				if (argv[len - 1] == 'r')
					return ;
			}
		}
	}
	ft_err_format();
}

int	main(int argc, char **argv)
{
	t_struct	var;
	int			len;
	int			count;

	if (argc != 2)
		ft_err_not_map();
	ft_check_format(argv[1]);
	ft_map_check_string(&len, &count, argv);
	ft_map_check_object(argv);
	var.map = ft_save_map(count, argv[1]);
	var.mlx_ptr = mlx_init();
	var.win_ptr = mlx_new_window(var.mlx_ptr, len * 96, count * 128, "So_long");
	var.img = ft_init_img(var.mlx_ptr);
	ft_draw_map(var.mlx_ptr, var.win_ptr, var.img, var.map);
	mlx_key_hook(var.win_ptr, ft_key_hook, &var);
	mlx_hook(var.win_ptr, 17, 0L, &quit, &var);
	mlx_loop(var.mlx_ptr);
	return (0);
}
