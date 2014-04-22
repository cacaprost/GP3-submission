#include "playerNyan.h"
#include "myinputs.h"
#include "gamecode.h"

void playerNyan::init()				// position.set - places the object [which is in our case the nyan cat] in the centre of the screen, loads the bitmap, bla bla bla.
{
	position.set(150,334);

	image.LoadBitmapA("resized.bmp");


	source.top = 0;
	source.left = 0;
	source.right = 100;
	source.bottom = 100;

}
void playerNyan::update()   //the keyboard functionality, which is W/S - up/down + the smooth fall effect of the nyan cat if W is not pressed.
{
	if (alive){
		//get keyb state
		MyInputs::GetInstance()->SampleKeyboard();
		Vector2D temp(0, 7);
		//check w/s keyboard


		if (MyInputs::GetInstance()->KeyPressed(DIK_W))
		{
			if (position.YValue >= 0)
			{
				position -= temp;
				
			}
		}
		else if (MyInputs::GetInstance()->KeyPressed(DIK_S))
		{
			if (position.YValue <= SCREENHEIGHT - source.bottom)
			{

				position += temp;
			}
		}
		else
		if (position.YValue <= SCREENHEIGHT - source.bottom)
		{
			Vector2D cazi_in_pula_mea(0, 4);
			position = position + cazi_in_pula_mea;
		}

	}
		
}
void playerNyan::Draw()			// as in Obstacol.cpp, this function draws the cat.
{
	if (alive)
	{

		dest.top = 0 + position.YValue;
		dest.left = 0 + position.XValue;
		dest.right = 100 + position.XValue;
		dest.bottom = 100 + position.YValue;

		MyDrawEngine::GetInstance()->Blit(dest, source, &image);
	}
}
void playerNyan::Terminate()		//bla bla memory free.
{
	image.Release();
}