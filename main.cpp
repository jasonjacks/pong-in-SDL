//INCLUDES
#include <SDL.h>
#include <stdio.h>
#include <string>

//FUNCTION PROTOTYPES
bool init ( SDL_Window*  &gWindow,
	     SDL_Surface* &gScreenSurface); //Starts up SDL and creates window

bool loadMedia ( SDL_Surface* &gPaddle, 
	          SDL_Surface* &gBlanker, 
		  SDL_Surface* &gBall ); //Loads media

int key_poll ( bool &quit ); //Returns integer after polling user input

void game_logic ( SDL_Rect &paddleRect, 
	           SDL_Rect &ballRect, 
		   int      &ball_vector_x, 
		   int      &ball_vector_y, 
		   int      game_logix); //Updates game state

void game_view ( SDL_Window*  gWindow, 
	          SDL_Surface* gScreenSurface, 
		  SDL_Surface* gPaddle, 
		  SDL_Surface* gBlanker, 
		  SDL_Surface* gBall, 
		  SDL_Rect     paddleRect, 
		  SDL_Rect     ballRect); //Renders game state

void close ( SDL_Window*  &gWindow, 
	      SDL_Surface* &gPaddle); //Frees media and shuts down SDL

//SDL RESOURCES
 SDL_Window* gWindow        = NULL; //The window we'll be rendering to
SDL_Surface* gScreenSurface = NULL; //The surface contained by the window
SDL_Surface* gPaddle        = NULL; //Paddle
SDL_Surface* gBlanker       = NULL; //Blanker
SDL_Surface* gBall          = NULL; //Ball (Square)


//MAIN
int main( int argc, char* args[] )
{
	//Game Variables
	int game_logix = 2; //paddle stationary = 2

	SDL_Rect paddleRect; //paddle data - location
	paddleRect.x = 0;
	paddleRect.y = 240;
	paddleRect.w = 15;
	paddleRect.h = 80;
		
	SDL_Rect ballRect; //ball data - location
	ballRect.x = 50;
	ballRect.y = 50;
	ballRect.w = 5;
	ballRect.h = 5;
	int ball_vector_x = 3; //ball data - vector
	int ball_vector_y = 5;
	
	printf("starting...\n");

	//Start up SDL and create window
	if( !init(gWindow, gScreenSurface) )
	{
		printf( "Failed to initialize!\n" );
		SDL_Delay(5000);
	}
	else
	{
		printf( "Initialized!\n" );

		//Load media
		if ( !loadMedia(gPaddle, gBlanker, gBall) )
		{
			printf( "Failed to load media!\n" );
			SDL_Delay(5000);
		}
		else
		{
			printf( "Loaded media!... Entering Game Loop!\n" );
			SDL_Delay(2000);
			
			//Main loop flag
			bool quit = false;
			
			//GAME LOOP
			while( !quit )
			{
				//Get user input
				game_logix = key_poll(quit);

				//Update game state - pass paddle location, ball location, ball vector components, paddle signal
				game_logic(paddleRect, ballRect, ball_vector_x, ball_vector_y, game_logix);

				//Draw game world
				game_view(gWindow, gScreenSurface, gPaddle, gBlanker, gBall, paddleRect, ballRect);

				//Delay for keyboard signal stream
				SDL_Delay( 5 );
			}
		}
	}

	//Free resources and close SDL
	close(gWindow, gPaddle);

	return 0;
}
