/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:23:59 by ofedorov          #+#    #+#             */
/*   Updated: 2017/01/18 14:24:00 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#define IS_PA(s) (*(s) == 'p' && *(s + 1) == 'a')
#define IS_PB(s) (*(s) == 'p' && *(s + 1) == 'b')
#define IS_RA(s) (*(s) == 'r' && *(s + 1) == 'a')
#define IS_RRA(s) (*(s) == 'r' && *(s + 1) == 'r' && *(s + 2) == 'a')
#define IS_RB(s) (*(s) == 'r' && *(s + 1) == 'b')
#define IS_RRB(s) (*(s) == 'r' && *(s + 1) == 'r' && *(s + 2) == 'b')
#define ISNT_LAST(s) (*(s + 2) && *(s + 3))

char	*optimize(char *ops)
{
	char			*str;
	register int	i;
	register int	j;
	int 			len;

	len = ft_strlen(ops);
	str = ft_memalloc(len);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (ISNT_LAST(&ops[i]))
		{
			if (IS_PB(&ops[i]) && IS_PA(&ops[i + 3]))
				i += 3;
			else if ((IS_RA(&ops[i]) && IS_RRA(&ops[i + 3])) ||
				(IS_RRA(&ops[i]) && IS_RA(&ops[i + 4])) ||
				(IS_RB(&ops[i]) && IS_RRB(&ops[i + 3])) ||
				(IS_RRB(&ops[i]) && IS_RB(&ops[i + 4])))
				i += 4;
			else
			{
				str[j++] = ops[i];
				str[j++] = ops[i + 1];
				str[j++] = ops[i + 2];
				(ops[i + 2] && ops[i + 3] == '\n') ? str[j++] = ops[i++ + 3] : (0);
			}
		}
		else
		{
			str[j++] = ops[i];
			str[j++] = ops[i + 1];
			str[j++] = ops[i + 2];
			(ops[i + 2] && ops[i + 3] == '\n') ? str[j++] = ops[i++ + 3] : (0);
		}
		i += 3;
	}
	free(ops);
	ops = ft_strdup(str);
	free(str);
	return (ops);
}
