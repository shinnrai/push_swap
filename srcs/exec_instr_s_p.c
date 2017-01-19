/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instr_s_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 21:20:24 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/17 21:20:26 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	exec_instr_sa(t_info *info)
{
	int tmp;

	if (info->a_size < 2)
		return ;
	tmp = info->a[0];
	info->a[0] = info->a[1];
	info->a[1] = tmp;
}

void	exec_instr_sb(t_info *info)
{
	int tmp;

	if (info->b_size < 2)
		return ;
	tmp = info->b[0];
	info->b[0] = info->b[1];
	info->b[1] = tmp;
}

void	exec_instr_ss(t_info *info)
{
	exec_instr_sa(info);
	exec_instr_sb(info);
}

void	exec_instr_pa(t_info *info)
{
	register int	i;

	if (!info->b_size)
		return ;
	i = info->a_size;
	while (i-- > 0)
		info->a[i + 1] = info->a[i];
	info->a[0] = info->b[0];
	i = 0;
	while (i++ < info->b_size - 1)
		info->b[i - 1] = info->b[i];
	info->a_size++;
	info->b_size--;
}

void	exec_instr_pb(t_info *info)
{
	register int	i;

	if (!info->a_size)
		return ;
	i = info->b_size;
	while (i-- > 0)
		info->b[i + 1] = info->b[i];
	info->b[0] = info->a[0];
	i = 0;
	while (i++ < info->a_size - 1)
		info->a[i - 1] = info->a[i];
	info->b_size++;
	info->a_size--;
}
