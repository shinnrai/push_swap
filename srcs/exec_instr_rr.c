/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instr_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 21:20:50 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/17 21:20:52 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	exec_instr_rra(t_info *info)
{
	int				tmp;
	register int	i;

	if (info->a_size < 2)
		return ;
	tmp = info->a[info->a_size - 1];
	i = info->a_size;
	while (i-- > 1)
		info->a[i] = info->a[i - 1];
	info->a[0] = tmp;
}

void	exec_instr_rrb(t_info *info)
{
	int				tmp;
	register int	i;

	if (info->b_size < 2)
		return ;
	tmp = info->b[info->b_size - 1];
	i = info->b_size;
	while (i-- > 1)
		info->b[i] = info->b[i - 1];
	info->b[0] = tmp;
}

void	exec_instr_rrr(t_info *info)
{
	exec_instr_rra(info);
	exec_instr_rrb(info);
}
