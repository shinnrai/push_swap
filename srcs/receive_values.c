/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 12:05:00 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/17 12:05:03 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	check_equal(int *a, int start, int size)
{
	register int	i;

	i = start;
	while (++i < size)
		if (a[i] == a[start])
			ft_error(NULL);
}

t_info	*receive_values(int argc, char **argv)
{
	register int	i;
	t_info			*info;

	if (argc-- == 1)
		exit(0);
	info = (t_info*)malloc(sizeof(t_info));
	info->a = (int*)malloc(sizeof(int) * argc);
	info->b = (int*)ft_memalloc(sizeof(int) * argc);
	info->size = argc;
	info->a_size = argc;
	info->b_size = 0;
	info->ops = ft_strnew(0);
	info->reversed = 0;
	if (!info->a || !info->b)
		ft_error(NULL);
	i = argc;
	while (i-- > 0)
	{
		info->a[i] = check_atoi(argv[i + 1]);
		check_equal(info->a, i, argc);
	}
	return (info);
}
