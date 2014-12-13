#include <SDL.h>
#include <stdio.h>

using namespace std;

int padspeed = 10;
int ballspeed = 1;

void game_logic(SDL_Rect &paddleRect, SDL_Rect &ballRect, int &ball_vector_x, int &ball_vector_y, int game_logix)
{
	if(game_logix == 0) //down
	{
		paddleRect.y = paddleRect.y + padspeed;
		if (paddleRect.y > 400) {paddleRect.y = 400;} //paddle lock bottom
	}
	else if (game_logix == 1) //up
	{
		paddleRect.y = paddleRect.y - padspeed;
		if (paddleRect.y < 0) {paddleRect.y = 0;} //paddle lock top
	}
	else
	{

	}
	
	//update ball position
	ballRect.x = ballRect.x + ballspeed*ball_vector_x;
	ballRect.y = ballRect.y + ballspeed*ball_vector_y;

	//collision detection
	if (ballRect.x > 625) {ballRect.x = 625; ball_vector_x = -ball_vector_x;} //right side collision
	if (ballRect.y > 465) {ballRect.y = 465; ball_vector_y = -ball_vector_y;} //bottom collision
	if (ballRect.y < 0)   {ballRect.y = 0;   ball_vector_y = -ball_vector_y;} //top collision

	if (ballRect.x < 15)
	{
		if(ballRect.y >= paddleRect.y && ballRect.y <= paddleRect.y + 80)
		{
			ballRect.x = 15;
			ball_vector_x = -ball_vector_x;
			ball_vector_y = -ball_vector_y;
		}
		else
		{
			printf("Game over\n");
			SDL_Delay(3000);
		}
	}
}
