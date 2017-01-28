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

#define BUFF_SIZE 2048

void	receive_instr(t_info *info)
{
	char	*buff;
	char	*str;

	buff = ft_memalloc(sizeof(char) * BUFF_SIZE);
	while (read(0, buff, BUFF_SIZE - 1))
	{
		if (info->ops)
		{
			str = info->ops;
			info->ops = ft_strjoin(info->ops, buff);
			free(str);
		}
		else
			info->ops = buff;
		ft_bzero(buff, ft_strlen(buff));
	}
	free(buff);
}

int		checker(t_info *info)
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
	int		result;

	info = receive_values(argc, argv);
	receive_instr(info);
	result = checker(info);
	if (result == -1)
		ft_error(NULL);
	else if (result == 0)
		ft_putendl("KO");
	else
		ft_putendl("OK");
}
