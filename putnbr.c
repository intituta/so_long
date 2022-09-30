/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:57:44 by kferterb          #+#    #+#             */
/*   Updated: 2021/11/28 18:29:24 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_logic(int fd, int n, int r)
{
	long int	n2;
	char		ch;

	n2 = n;
	if (n2 < 0)
	{
		write(fd, "-", 1);
		n2 *= -1;
	}
	if (n2 == 0)
	{
		write(fd, "0", 1);
	}
	while (r != 0)
	{
		ch = n2 / r + '0';
		write(fd, &ch, 1);
		n2 = n2 % r;
		r = r / 10;
	}
}

long int	ft_count_r(int n)
{
	long int	r;

	r = 1;
	while (n != 0)
	{
		r = r * 10;
		n = n / 10;
	}
	r = r / 10;
	return (r);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	r;

	r = ft_count_r(n);
	ft_logic(fd, n, r);
}
