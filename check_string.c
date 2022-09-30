/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:38:08 by kferterb          #+#    #+#             */
/*   Updated: 2021/11/28 19:54:17 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_err_correct_map(void)
{
	write(1, "ERR_correct_map\n", 16);
	exit(0);
}

void	ft_check_string(int count, int len, int i, char *str)
{
	int	j;

	j = 0;
	if (i == 1 || i == count)
	{
		while (str[j])
		{
			if (str[j] != '1')
				ft_err_correct_map();
			j++;
		}
	}
	else if (str[0] != '1' || str[len -1] != '1')
		ft_err_correct_map();
}

void	ft_map_count(int *len, int *count, char **argv)
{
	int		fd;
	char	*str;

	*len = 0;
	*count = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_err_open_map();
	while (1)
	{
		str = gnl(fd);
		if (str[0] == '\0')
		{
			free(str);
			break ;
		}
		if (*len == 0)
			*len = ft_strlen(str);
		if (*len != (int)ft_strlen(str))
			ft_err_map();
		free(str);
		(*count)++;
	}
	close(fd);
}

void	ft_map_check_string(int *len, int *count, char **argv)
{
	int		i;
	int		fd;
	char	*str;

	i = 1;
	ft_map_count(len, count, argv);
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		str = gnl(fd);
		if (str[0] == '\0')
		{
			free(str);
			break ;
		}
		ft_check_string(*count, *len, i, str);
		free(str);
		i++;
	}
	close(fd);
}
