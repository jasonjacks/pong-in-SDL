#include <SDL.h>
#include <stdio.h>
#include <string>

int key_poll(bool &quit)
{
	//Event handler
	SDL_Event e;
	
	//Handle events on queue
	while( SDL_PollEvent( &e ) != 0 )
	{
		//User requests quit
		if( e.type == SDL_QUIT )
		{
			printf("user has quit\n");
			quit = true;
		}
	}

	const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
	if( currentKeyStates[ SDL_SCANCODE_UP ] )
	{
		printf("up\n");
		return 1; //up code
	}
	else if( currentKeyStates[ SDL_SCANCODE_DOWN ] )
	{
		printf("down\n");
		return 0; //down code
	}
	else
	{
		//pass NULL code to game logic
		return 2; //stationary code
	}
}
