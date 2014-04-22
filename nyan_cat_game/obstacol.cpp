#include "obstacol.h"
#include "myinputs.h"
#include "playerNyan.h"

void obstacol::init(int type, int location)
{
	typec = type;
	locationc = location;
								// This piece of code gets the images - obstacles from the Ressource Files.
	switch (type)						
	{
		case 0:
			image.LoadBitmapA("1.bmp");
			break;
		case 1:
			image.LoadBitmapA("2.bmp");
			break;
		case 2:
			image.LoadBitmapA("3.bmp");
			break;
		case 3:
		default:
			image.LoadBitmapA("4.bmp");
			break;
	}

	source.top = 0;
	source.left = 0;
	source.right = 100;
	source.bottom = 100;

	terminated = false;
}

void obstacol::update()			//Placing the obstacles in the right side of the screen, and deleting them when they reach the limit in the left side of the screen.
{
	//get keyb state
	MyInputs::GetInstance()->SampleKeyboard();
	Vector2D temp(10, 0);

	position = position - temp;

	dest.left =  1020 + position.XValue;
	dest.right = 1120 + position.XValue;

	if (dest.right < 0)
	{

		Terminate();
	}

}


//Supposed to be some kind of collision detector, but it didn't work or I was way too tired to think about it.

/*bool obstacol::CheckCollision()

{
	if (position.YValue <dest.bottom &&
		position.YValue >dest.top &&
		position.XValue > dest.left &&
		position.XValue < dest.right)
	{
		playerNyan *alive = false;
		return true;
	}
	return false;
}
*/ 



void obstacol::Draw()  //this function draws the obstacles, different sizes. beacause of i do not know why, it takes only a single jpg, and resizes it.
{ 
	
	switch (typec)
	{
	case 0:
		if (locationc)
			dest.bottom = 310;
		else
		{
			dest.bottom = 770;
			dest.top = 670;
		}
		break;
	case 1:
		if (locationc)
		dest.bottom = 100;
		else{
			dest.bottom = 800;
			dest.top = 400;
		}
		break;
	case 2:
		if (locationc)
		dest.bottom = 310;
		else{
			dest.bottom = 800;
			dest.top = 500;
		}
		break;

	case 3:
	default:
		if (locationc)
		dest.bottom = 310;
		else
		{
			dest.bottom = 800;
			dest.top = 400;

		}
		break;
	}

	if (locationc == 1)
		dest.top = 0;


	if (dest.left == 0) {
		dest.left = 1020;
		dest.right = 1120;
	}

	MyDrawEngine::GetInstance()->Blit(dest, source, &image);
}
void obstacol::Terminate()			//clearing the memory, etc.
{
	terminated = true;
	image.Release();
}