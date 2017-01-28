/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 12:19:36 by ofedorov          #+#    #+#             */
/*   Updated: 2017/01/13 12:19:42 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	end_rotate(t_info *info)
{
	register int	i;
	int				min_ind;

	i = 0;
	min_ind = 0;
	while (++i < info->a_size)
		if (info->a[i] < info->a[min_ind])
			min_ind = i;
	i = -1;
	if (min_ind <= info->a_size / 2)
		while (++i < min_ind)
			add_and_exec(info, INSTR_RA);
	else
		while (++i < info->a_size - min_ind)
			add_and_exec(info, INSTR_RRA);
}
