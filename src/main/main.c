/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 17:27:17 by cpireyre          #+#    #+#             */
/*   Updated: 2019/06/22 17:29:37 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "queue.h"
#include "sierpinski.h"
#include <unistd.h>
#define LINESIZE	100

void	println(t_queue cpy)
{
	char	buffer[LINESIZE];
	int		p;

	ft_memset(&buffer, ' ', LINESIZE);
	while ((p = pop(&cpy)) != -1)
		if (0 <= p && p < LINESIZE)
			buffer[p] = '#';
	write(1, &buffer, LINESIZE);
	ft_putchar('\n');
}

void	print_tty(t_queue *sierpinski, unsigned int lines)
{
	size_t	i;

	i = 0;
	while (i < lines)
		println(sierpinski[i++]);
}

int		main(int ac, char **av)
{
	unsigned int	height;
	t_queue			*sierpinski;

	if (ac == 2 && ft_isint(av[1]))
	{
		height = ft_atoi(av[1]);
		sierpinski = compute_sierpinski(ft_atoi(av[1]));
		print_tty(sierpinski, height);
		free_sierpinski(sierpinski, height);
	}
}
