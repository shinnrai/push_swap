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

void	push_to(t_info *info, t_list *excl)
{
	int 	*rot;
	int 	excl_len;

	excl_len = ft_lstlen(excl);
	while (((!info->reversed && (info->a_size > 3 && info->a_size > excl_len)) || info->reversed) &&
			info->a_size > 0)
	{
		rot = get_ind(info, excl); // can return -1 ?
		while ((rot[0])-- > 0)
		{
			if (rot[1] && info->a[0] != rot[2] && info->b_size && info->b[0] != rot[3])
				add_and_exec(info, rot[1]);
			else if (rot[1] && info->a[0] != rot[2])
				add_and_exec(info, rot[1] == INSTR_RR ? INSTR_RA : INSTR_RRA);
			else if (rot[1] && info->b[0] != rot[3])
				add_and_exec(info, rot[1] == INSTR_RR ? INSTR_RB : INSTR_RRB);
			else if (info->a[0] != rot[2])
				add_and_exec(info, rot[4]);
			else if (info->b[0] != rot[3])
				add_and_exec(info, rot[5]);
		}
		free(rot);
		add_and_exec(info, INSTR_PB);
	}
	if (!info->reversed)
		do_three(info);
}
