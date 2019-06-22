/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:30:16 by cpireyre          #+#    #+#             */
/*   Updated: 2019/06/22 17:25:07 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "queue.h"

t_queue			init(void)
{
	t_queue	queue;

	queue.nums = ft_memalloc(sizeof(int) * QSIZE_INIT);
	queue.in = 0;
	queue.out = 1;
	queue.size = QSIZE_INIT;
	return (queue);
}

static t_queue	resize(t_queue *s)
{
	t_queue	bigger_queue;
	size_t	new_size;

	new_size = s->size * 2;
	bigger_queue.nums = ft_memalloc(sizeof(int) * new_size);
	ft_memcpy(bigger_queue.nums, s->nums, sizeof(int) * (s->in + 1));
	bigger_queue.in = s->in;
	bigger_queue.out = s->out;
	bigger_queue.size = new_size;
	ft_memdel((void**)&s->nums);
	return (bigger_queue);
}

void			push(t_queue *s, int val)
{
	s->in++;
	s->nums[s->in] = val;
	if (s->in == s->size - 1)
		*s = resize(s);
}

int				pop(t_queue *s)
{
	int	ret;

	if (s->out > s->in)
		return (-1);
	ret = s->nums[s->out];
	s->out++;
	return (ret);
}

void			print(t_queue *s)
{
	size_t	i;

	i = 1;
	while (i <= s->in)
	{
		ft_putnbr(s->nums[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}
