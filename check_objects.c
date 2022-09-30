/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:41:49 by kferterb          #+#    #+#             */
/*   Updated: 2021/11/28 20:15:58 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_err_object(void)
{
	write(1, "ERR_object\n", 11);
	exit(0);
}

void	ft_check_object(int *c, int *e, int *p, char *str)
{
	while (*str)
	{
		if (*str == 'C')
			*c += 1;
		if (*str == 'E')
			*e += 1;
		if (*str == 'P')
			*p += 1;
		if (*str != 'C' && *str != 'E' && *str != 'P'
			&& *str != '1' && *str != '0' && *str != '\n' && *str != 'V')
			ft_err_symbol();
		str++;
	}
}

void	ft_map_check_object(char **argv)
{
	int		c;
	int		e;
	int		p;
	int		fd;
	char	*str;

	c = 0;
	e = 0;
	p = 0;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		str = gnl(fd);
		if (str[0] == '\0')
		{
			free(str);
			break ;
		}
		ft_check_object(&c, &e, &p, str);
		free(str);
	}
	close(fd);
	if (c * e * p == 0 || p < 1 || e < 1)
		ft_err_object();
}
