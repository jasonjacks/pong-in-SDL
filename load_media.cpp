#include <SDL.h>
#include <stdio.h>

bool loadMedia(SDL_Surface* gPaddle, SDL_Surface* gBlanker, SDL_Surface* gBall)
{
    //Loading success flag
    bool success = true;

    //Load splash image
    gPaddle = SDL_LoadBMP( "pong/paddle.bmp" );
    if( gPaddle == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "pong/paddle.bmp\n", SDL_GetError() );
        success = false;
    }

	gBlanker = SDL_LoadBMP( "pong/blanker.bmp" );
    if( gBlanker == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "pong/blanker.bmp\n", SDL_GetError() );
        success = false;
    }

	gBall = SDL_LoadBMP( "pong/ball.bmp" );
    if( gBall == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "pong/ball.bmp\n", SDL_GetError() );
        success = false;
    }

	printf("all media loaded\n");
	SDL_Delay(2000);

    return success;
}
