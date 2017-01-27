/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:50:14 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/23 11:50:15 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


void	push_swap(t_info *info)
{
	t_info	*rev_info;
	char	*optimized;

	push_to(info); // was excl
	rev_info = reverse_info(info);
	push_to(rev_info);
	merge_infos(info, rev_info);
	end_rotate(info);
	del_rev_info(&rev_info);
	while (ft_strlen((optimized = optimize(info->ops))) != ft_strlen(info->ops))
	{
		free(info->ops);
		info->ops = optimized;
	}
}

void	pause_for(int t)
{
	long	i;
	long	time;

	i = 0;
	time = t * 500000000;
	while (i < time)
		i++;
}

void	print_result(char *ops, t_info *cp_info)
{
	int instr;
	int *each_op;
	int i;

	each_op = (int*)ft_memalloc(sizeof(int) * 12);
	(cp_info->display_stacks) ? display_ab(cp_info) : (0);
	while ((instr = get_next_instr(&ops)) != -1)
	{
		(cp_info->print_slow) ? pause_for(1) : (0);
		(cp_info->display_stacks) ? exec_instr(cp_info, instr) : (0);
		display_instr(instr, cp_info->color);
		(cp_info->display_stacks) ? display_ab(cp_info) : (0);
		(each_op[11])++;
		(each_op[instr])++;
	}
	i = -1;
	if (cp_info->each_op || cp_info->display_number)
	{
		ft_textcolor(DIS_COLOR);
		ft_putendl("Stats:");
		ft_textcolor(NOCOLOR);
	}
	while (++i < 11 && cp_info->each_op)
		if (each_op[i])
		{
			ft_putnbr(each_op[i]);
			ft_putchar(' ');
			ft_textcolor(DIS_COLOR);
			display_instr(i, false);
			ft_textcolor(NOCOLOR);
		}
	if (cp_info->display_number)
	{
		ft_putnbr(each_op[11]);
		ft_textcolor(DIS_COLOR);
		ft_putendl(" total");
		ft_textcolor(NOCOLOR);
	}
	free(each_op);
}

int		main(int argc, char **argv)
{
	t_info	*info;
	t_info	*cp_info;
	char	*ops;

	info = receive_values(argc, argv);
	cp_info = copy_info(info);
	push_swap(info);
	ops = info->ops;
	if (ops)
		print_result(ops, cp_info);
	del_info(&info);
	del_info(&cp_info);
}