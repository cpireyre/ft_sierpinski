#include <SDL2/SDL.h>
#include "sierpinski.h"

#define SCREEN_WIDTH 1366
#define SCREEN_HEIGHT 768

static void	printsdl(t_queue cpy, SDL_Renderer *r, unsigned int ln)
{
	int		p;

	while ((p = pop(&cpy)) != -1)
		if (0 <= p && p < SCREEN_WIDTH)
      SDL_RenderDrawPoint(r, p, ln);
}

static void	render_sdl(SDL_Renderer *r, t_queue *sierpinski, unsigned int lines)
{
	size_t	i;

	i = -1;
	while (++i < lines)
    printsdl(sierpinski[i], r, i);
}

int  do_sdl_crap(SDL_Window *w, t_queue *sierpinski, unsigned int lines)
{
  SDL_Renderer *renderer = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED);
  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
  render_sdl(renderer, sierpinski, lines);
  SDL_RenderPresent(renderer);
  return (1);
}
