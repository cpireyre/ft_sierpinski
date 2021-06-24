/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <cpireyre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 17:28:29 by cpireyre          #+#    #+#             */
/*   Updated: 2019/06/22 17:29:23 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIERPINSKI_H
# define SIERPINSKI_H

//#include <SDL2/SDL.h>
#include "queue.h"

t_queue	*compute_sierpinski(unsigned int lines);
void	free_sierpinski(t_queue *sierpinski, unsigned int lines);

//int  do_sdl_crap(SDL_Window *w, t_queue *q, unsigned int l);
#endif
