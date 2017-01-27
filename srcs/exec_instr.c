/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 21:02:28 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/17 21:02:30 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	add_instr(t_info *info, int instr)
{
	char	*arr[11];
	char	*str;

	arr[INSTR_SA] = "sa\n";
	arr[INSTR_SB] = "sb\n";
	arr[INSTR_SS] = "ss\n";
	arr[INSTR_PA] = "pa\n";
	arr[INSTR_PB] = "pb\n";
	arr[INSTR_RA] = "ra\n";
	arr[INSTR_RB] = "rb\n";
	arr[INSTR_RR] = "rr\n";
	arr[INSTR_RRA] = "rra\n";
	arr[INSTR_RRB] = "rrb\n";
	arr[INSTR_RRR] = "rrr\n";
	str = info->ops;
	info->ops = ft_strjoin(info->ops, arr[instr]);
	free(str);
}

void	exec_instr(t_info *info, int instr)
{
	void	(*arr[11])(t_info *info);

	arr[INSTR_SA] = exec_instr_sa;
	arr[INSTR_SB] = exec_instr_sb;
	arr[INSTR_SS] = exec_instr_ss;
	arr[INSTR_PA] = exec_instr_pa;
	arr[INSTR_PB] = exec_instr_pb;
	arr[INSTR_RA] = exec_instr_ra;
	arr[INSTR_RB] = exec_instr_rb;
	arr[INSTR_RR] = exec_instr_rr;
	arr[INSTR_RRA] = exec_instr_rra;
	arr[INSTR_RRB] = exec_instr_rrb;
	arr[INSTR_RRR] = exec_instr_rrr;
	arr[instr](info);
}

void	add_and_exec(t_info *info, int instr)
{
	add_instr(info, instr);
	exec_instr(info, instr);
//	display_ab(info);
}
