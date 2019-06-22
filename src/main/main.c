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
#include <SDL2/SDL.h>
#define LINESIZE	93
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

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

void  dump_coordinates(t_queue *sierpinski, unsigned int lines)
{
  unsigned int  i;
  int           p;
  t_queue       cpy;

  i = 0;
  while (i < lines)
  {
    cpy = sierpinski[i];
    while ((p = pop(&cpy)) != -1)
    {
      if (0 <= p && p < LINESIZE)
      {
        ft_putnbr(p);
        ft_putchar(' ');
      }
    }
    ft_putchar('\n');
    i++;
  }
}

void	print_tty(t_queue *sierpinski, unsigned int lines)
{
	size_t	i;

	i = 0;
	while (i < lines)
  {
    if (i % 2)
      ft_putstr("\x1b[034m");
    else
      ft_putstr("\x1b[033m");
    println(sierpinski[i++]);
  }
  ft_putstr("\x1b[0m");
}

/* int		main(int ac, char **av) */
/* { */
/* 	unsigned int	height; */
/* 	t_queue			*sierpinski; */

/* 	if (ac == 2 && ft_isint(av[1])) */
/* 	{ */
/* 		height = ft_atoi(av[1]); */
/* 		sierpinski = compute_sierpinski(ft_atoi(av[1])); */
/*     do_sdl_crap(sierpinski, height); */
/* 		free_sierpinski(sierpinski, height); */
/* 	} */
/* } */

int main(int ac, char* av[]) {

  unsigned int height;
  t_queue *sierpinski;
  SDL_Window *window;                    // Declare a pointer

  SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

  // Create an application window with the following settings:
  window = SDL_CreateWindow(
      "Sierpiński's frog 🐸",                  // window title
      SDL_WINDOWPOS_UNDEFINED,           // initial x position
      SDL_WINDOWPOS_UNDEFINED,           // initial y position
      1280,                               // width, in pixels
      512,                               // height, in pixels
      SDL_WINDOW_OPENGL                  // flags - see below
      );

  // Check that the window was successfully created
  if (window == NULL) {
    // In the case that the window could not be made...
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }

  // A basic main loop to prevent blocking
  t_bool is_running = true;
  SDL_Event event;
  while (is_running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        is_running = false;
      }
    }
    if (ac == 2 && ft_isint(av[1]))
    {
      height = ft_atoi(av[1]);
      sierpinski = compute_sierpinski(ft_atoi(av[1]));
      do_sdl_crap(window, sierpinski, height);
      free_sierpinski(sierpinski, height);
    }
  }

  // Close and destroy the window
  SDL_DestroyWindow(window);

  // Clean up
  SDL_Quit();
  return 0;

}
