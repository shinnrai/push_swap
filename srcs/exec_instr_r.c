/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instr_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 21:20:31 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/17 21:20:32 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	exec_instr_ra(t_info *info)
{
	int				tmp;
	register int	i;

	if (info->a_size < 2)
		return ;
	tmp = info->a[0];
	i = 1;
	while (i++ < info->a_size)
		info->a[i - 2] = info->a[i - 1];
	info->a[info->a_size - 1] = tmp;
}

void	exec_instr_rb(t_info *info)
{
	int				tmp;
	register int	i;

	if (info->b_size < 2)
		return ;
	tmp = info->b[0];
	i = 1;
	while (i++ < info->b_size)
		info->b[i - 2] = info->b[i - 1];
	info->b[info->b_size - 1] = tmp;
}

void	exec_instr_rr(t_info *info)
{
	exec_instr_ra(info);
	exec_instr_rb(info);
}
