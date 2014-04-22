#ifndef __BG_Image__
#define __BG_Image__
#include "vector2D.h"
#include "mydrawengine.h"

class BG_Image

{

private:
	Vector2D position;
	RECT source, dest;

	MyPicture image;
public:

	void init();

	void update();

	void Draw();

	void Terminate();

};

#endif