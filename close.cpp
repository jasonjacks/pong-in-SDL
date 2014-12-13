#include <SDL.h>
#include <stdio.h>

void close(SDL_Window* &gWindow, SDL_Surface* &gPaddle)
{
	printf("Closing...\n");
	SDL_Delay(2000);

	//Deallocate surface
    SDL_FreeSurface( gPaddle );
    gPaddle = NULL;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();

	printf("Closed...\n");
	SDL_Delay(2000);
}
