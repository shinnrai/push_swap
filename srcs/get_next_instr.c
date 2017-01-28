/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_instr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 12:24:26 by ofedorov          #+#    #+#             */
/*   Updated: 2017/01/25 12:26:21 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		get_next_instr(char **instr)
{
	int instr_res;

	instr_res = -1;
	if (!(**instr))
		return (-1);
	(!ft_strncmp(*instr, "sa\n", 3)) ? instr_res = INSTR_SA : (0);
	(!ft_strncmp(*instr, "sb\n", 3)) ? instr_res = INSTR_SB : (0);
	(!ft_strncmp(*instr, "ss\n", 3)) ? instr_res = INSTR_SS : (0);
	(!ft_strncmp(*instr, "pa\n", 3)) ? instr_res = INSTR_PA : (0);
	(!ft_strncmp(*instr, "pb\n", 3)) ? instr_res = INSTR_PB : (0);
	(!ft_strncmp(*instr, "ra\n", 3)) ? instr_res = INSTR_RA : (0);
	(!ft_strncmp(*instr, "rb\n", 3)) ? instr_res = INSTR_RB : (0);
	(!ft_strncmp(*instr, "rr\n", 3)) ? instr_res = INSTR_RR : (0);
	(!ft_strncmp(*instr, "rra\n", 4)) ? instr_res = INSTR_RRA : (0);
	(!ft_strncmp(*instr, "rrb\n", 4)) ? instr_res = INSTR_RRB : (0);
	(!ft_strncmp(*instr, "rrr\n", 4)) ? instr_res = INSTR_RRR : (0);
	if (instr_res != -1)
		(*instr) += 3;
	if (instr_res >= INSTR_RRA)
		(*instr)++;
	return (instr_res);
}
