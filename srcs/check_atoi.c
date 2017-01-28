/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 12:26:25 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/17 12:26:26 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <limits.h>

int		check_atoi(char *str)
{
	long long	result;
	char		*cstr;

	cstr = str;
	while (cstr && *cstr)
	{
		if (!ft_isdigit(*cstr) && *cstr != '-')
			ft_error(NULL);
		cstr++;
	}
	result = ft_atoi(str);
	if (result > INT32_MAX || result < INT32_MIN)
		ft_error(NULL);
	return ((int)result);
}
