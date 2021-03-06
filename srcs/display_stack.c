/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 21:54:53 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/17 21:54:54 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	display_stack(int *stack, int size)
{
	register int	i;

	i = -1;
	while (++i < size)
	{
		ft_putnbr_fd(stack[i], 1);
		if (i + 1 != size)
			write(1, "\t", 1);
	}
	write(1, "\n", 1);
}

void		display_instr(int instr, bool color)
{
	char	*arr[11];

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
	if (color)
	{
		if (arr[instr][1] == 'a' || arr[instr][2] == 'a')
			ft_textcolor(A_COLOR);
		else if (arr[instr][1] == 'b' || arr[instr][2] == 'b')
			ft_textcolor(B_COLOR);
		else
			ft_textcolor(R_COLOR);
	}
	ft_putstr(arr[instr]);
	color ? ft_textcolor(NOCOLOR) : (0);
}

void		display_a(t_info *info)
{
	write(1, "a:\t", 3);
	if (info->rev)
		display_stack(info->b, info->b_size);
	else
		display_stack(info->a, info->a_size);
}

void		display_b(t_info *info)
{
	write(1, "b:\t", 3);
	if (info->rev)
		display_stack(info->a, info->a_size);
	else
		display_stack(info->b, info->b_size);
}

void		display_ab(t_info *info)
{
	display_a(info);
	display_b(info);
	write(1, "\n", 1);
}
