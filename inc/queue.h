/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 14:38:59 by cpireyre          #+#    #+#             */
/*   Updated: 2019/06/22 17:15:07 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# define QSIZE_INIT	32

typedef struct	s_queue
{
	int		*nums;
	size_t	in;
	size_t	out;
	size_t	size;
}				t_queue;

t_queue			init(void);
void			push(t_queue *s, int val);
int				pop(t_queue *s);
void			print(t_queue *s);

#endif
