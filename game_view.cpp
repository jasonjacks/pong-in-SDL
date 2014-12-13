#include <SDL.h>
#include <stdio.h>
#include <string>

void game_view(SDL_Window *gWindow, SDL_Surface *gScreenSurface, SDL_Surface *gPaddle, SDL_Surface *gBlanker, SDL_Surface *gBall, SDL_Rect dstrect, SDL_Rect ballRect)
{
	SDL_BlitSurface( gBlanker, NULL, gScreenSurface, NULL);
	SDL_BlitSurface( gPaddle, NULL, gScreenSurface, &dstrect );
	SDL_BlitSurface( gBall, NULL, gScreenSurface, &ballRect );

	//Update the surface
	SDL_UpdateWindowSurface( gWindow );
}
