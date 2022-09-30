/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:15:27 by kferterb          #+#    #+#             */
/*   Updated: 2021/11/28 19:54:44 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_err_symbol(void)
{
	write(1, "ERR_symbol\n", 11);
	exit(0);
}

void	ft_err_format(void)
{
	write(1, "ERR_file_format\n", 16);
	exit(0);
}

void	ft_err_map(void)
{
	write(1, "ERR_invalid_map\n", 16);
	exit(0);
}

void	ft_err_open_map(void)
{
	write(1, "ERR_open_map\n", 13);
	exit(0);
}

void	ft_err_not_map(void)
{
	write(1, "ERR_not_map\n", 12);
	exit(0);
}
