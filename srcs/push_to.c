/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:28:38 by ofedorov          #+#    #+#             */
/*   Updated: 2017/01/11 12:28:39 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	do_three(t_info *info)
{
	if (info->a_size == 3)
	{
		if (info->a[0] < info->a[2] && info->a[2] < info->a[1])
			add_and_exec(info, INSTR_SA);
		else if (info->a[1] < info->a[0] && info->a[0] < info->a[2])
			add_and_exec(info, INSTR_SA);
		else if (info->a[2] < info->a[1] && info->a[1] < info->a[0])
			add_and_exec(info, INSTR_SA);
	}
}

void	push_to(t_info *inf)
{
	int		*r;

	while (((!inf->rev && (inf->a_size > 3)) || inf->rev) && inf->a_size > 0)
	{
		r = get_ind(inf);
		while ((r[0])-- > 0)
		{
			if (r[1] && inf->a[0] != r[2] && inf->b_size && inf->b[0] != r[3])
				add_and_exec(inf, r[1]);
			else if (r[1] && inf->a[0] != r[2])
				add_and_exec(inf, r[1] == INSTR_RR ? INSTR_RA : INSTR_RRA);
			else if (r[1] && inf->b[0] != r[3])
				add_and_exec(inf, r[1] == INSTR_RR ? INSTR_RB : INSTR_RRB);
			else if (inf->a[0] != r[2])
				add_and_exec(inf, r[4]);
			else if (inf->b[0] != r[3])
				add_and_exec(inf, r[5]);
		}
		free(r);
		add_and_exec(inf, INSTR_PB);
	}
	if (!inf->rev)
		do_three(inf);
}
