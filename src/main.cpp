#include "SDL.h"
#include "vars.hpp"

int main (int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Failed to init SDL: %s\n", SDL_GetError());
		return 1;
	}

	// SDL_Surface* surface;
	SDL_Window* window;
	SDL_Renderer* renderer;

	window = SDL_CreateWindow
	(
		 "Game of Life",
		 SDL_WINDOWPOS_UNDEFINED,
		 SDL_WINDOWPOS_UNDEFINED,
		 WINDOW_SIZE_X,
		 WINDOW_SIZE_Y,
		 SDL_WINDOW_SHOWN
	);

	if (!window)
	{
		printf("Failed to create window: %s\n", SDL_GetError());
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Rect rect = {20, 20, 10, 10};
	
	SDL_Event event;
	while (true)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) { break; }
			
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);
	}	

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	
	SDL_Quit();
	return 0;
}
