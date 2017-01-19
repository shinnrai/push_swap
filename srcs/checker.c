/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 17:35:45 by ofedorov          #+#    #+#             */
/*   Updated: 2017/01/13 17:35:46 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	receive_instr(t_info *info)
{
	
}

int 	get_next_instr(char **instr)
{
	int instr_res;

	instr_res = -1;
	if (!(**instr))
		return (-1);
	(!ft_strncmp(*instr, "sa", 2)) ? instr_res = INSTR_SA : (0);
	(!ft_strncmp(*instr, "sb", 2)) ? instr_res = INSTR_SB : (0);
	(!ft_strncmp(*instr, "ss", 2)) ? instr_res = INSTR_SS : (0);
	(!ft_strncmp(*instr, "pa", 2)) ? instr_res = INSTR_PA : (0);
	(!ft_strncmp(*instr, "pb", 2)) ? instr_res = INSTR_PB : (0);
	(!ft_strncmp(*instr, "ra", 2)) ? instr_res = INSTR_RA : (0);
	(!ft_strncmp(*instr, "rb", 2)) ? instr_res = INSTR_RB : (0);
	(!ft_strncmp(*instr, "rr", 2)) ? instr_res = INSTR_RR : (0);
	(!ft_strncmp(*instr, "rra", 3)) ? instr_res = INSTR_RRA : (0);
	(!ft_strncmp(*instr, "rrb", 3)) ? instr_res = INSTR_RRB : (0);
	(!ft_strncmp(*instr, "rrr", 3)) ? instr_res = INSTR_RRR : (0);
	if (instr_res != -1)
		(*instr) += 2;
	if (instr_res >= INSTR_RRA)
		(*instr)++;
	if (**instr == '\n' && instr_res != -1)
		(*instr)++;
	return (instr_res);
}

int 	checker(t_info *info)
{
	int				instr;
	register int	i;

	while ((instr = get_next_instr(&info->ops)) != -1)
		exec_instr(info, instr);
	if (*info->ops)
		return (-1);
	i = 0;
	if (info->a_size != info->size || info->b_size != 0)
			return (0);
	while (++i < info->a_size)
		if (info->a[i] < info->a[i - 1])
			return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_info	*info;
	int 	result;

	info = receive_values(argc, argv);

	result = checker(info);
	if (result == -1)
		ft_error(NULL);
	else if (result == 0)
		ft_putstr("KO");
	else
		ft_putstr("OK");
}
