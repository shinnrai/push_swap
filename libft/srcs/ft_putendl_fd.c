/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 20:03:47 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/17 14:01:56 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putendl_fd(char const *s, int fd)
{
	int	i;

	i = ft_putstr_fd(s, fd);
	i += ft_putchar_fd('\n', fd);
	return (i);
}
