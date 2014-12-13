#include <SDL.h>
#include <stdio.h>

int padspeed = 5;
int ballspeed = 1;

void game_logic(SDL_Rect &dstrect, SDL_Rect &ballRect, int ball_vector_x, int ball_vector_y, int game_logix)
{
	if(game_logix == 0)
	{
		dstrect.y = dstrect.y - padspeed;
	}
	else if (game_logix == 1)
	{
		dstrect.y = dstrect.y + padspeed;
	}
	else
	{

	}
	
	ballRect.x = ballRect.x + ballspeed*ball_vector_x;
	ballRect.y = ballRect.y + ballspeed*ball_vector_y;

	//add code for collisions:
	//lock paddle at top and bottom
	//reflect ball's vector upon collions - x and y cases
}
