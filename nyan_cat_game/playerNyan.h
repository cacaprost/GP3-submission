#ifndef __playerNyan__
#define __playerNyan__
#include "vector2D.h"
#include "mydrawengine.h"

class playerNyan

{

private:
	Vector2D position;
	RECT source, dest;

	MyPicture image;

	
public:

	bool alive(); 

	void init();

	void update();

	void Draw();

	void Terminate();

};
 
#endif