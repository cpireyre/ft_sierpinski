/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:05:01 by cpireyre          #+#    #+#             */
/*   Updated: 2019/06/22 17:29:10 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "queue.h"

/*
**	I wish these things were immutable.
*/

static t_queue	makeline(t_queue *line)
{
	t_queue	next;
	int		lookingat;
	int		tmp;

	next = init();
	lookingat = pop(line);
	tmp = lookingat;
	push(&next, lookingat - 1);
	while ((lookingat = pop(line)) != -1)
	{
		if (ft_abs(tmp - lookingat) != 2)
		{
			push(&next, tmp + 1);
			push(&next, lookingat - 1);
		}
		tmp = lookingat;
	}
	push(&next, tmp + 1);
	return (next);
}

t_queue		*compute_sierpinski(unsigned int lines)
{
	t_queue			*ret;
	t_queue			curr;
	t_queue			new;
	unsigned int	i;

	ret = ft_memalloc(sizeof(t_queue) * lines);
	curr = init();
	push(&curr, lines);
	push(&curr, lines + 256);
	i = 0;
	while (i < lines)
	{
		ret[i] = curr;
		new = makeline(&curr);
		curr = new;
		i++;
	}
	ft_memdel((void**)&new.nums);
	return (ret);
}

void		free_sierpinski(t_queue *sierpinski, unsigned int lines)
{
	size_t	i;

	i = 0;
	while (i < lines)
		ft_memdel((void**)&sierpinski[i++].nums);
	ft_memdel((void**)&sierpinski);
}
