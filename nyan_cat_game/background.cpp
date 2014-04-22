#include "background.h"
#include "myinputs.h"


void BG_Image::init() //again, getting the image, resized it, etc.
{
	position.set(0, 0);

	image.LoadBitmapA("background.bmp");


	source.top = 0;
	source.left = 0;
	source.right = 1100;
	source.bottom = 900;

}
void BG_Image::update()
{

	//get keyb state
	MyInputs::GetInstance()->SampleKeyboard();
	Vector2D temp(69, 0);

	//if (MyInputs::GetInstance()->KeyPressed(DIK_W))
	position = position + temp;

	source.left = 0 + position.XValue;
	source.right = 1100 + position.XValue;

	//because the background was too small, i thought to reset it, and with a speedy vector2d, will create the sparkling stars effect(or this is how I actually see them).

	if (source.right >= 1600)
	{
		source.right = 1100;
		source.left = 0;

		position.set(0, 0);
	}

}

//drawing
void BG_Image::Draw()
{

	dest.top = 0;
	dest.left = 0;
	dest.right = 1100;
	dest.bottom = 900;

	MyDrawEngine::GetInstance()->Blit(dest, source, &image);
}

//releasing 
void BG_Image::Terminate()
{
	image.Release();
}