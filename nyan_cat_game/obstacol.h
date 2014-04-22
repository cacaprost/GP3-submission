#ifndef __obstacol__
#define __obstacol__
#include "vector2D.h"
#include "mydrawengine.h"

class obstacol

{

private:
	Vector2D position;

	int typec;
	int locationc;
	MyPicture image;

public:
	

	void init(int type, int position);

	RECT source, dest;
	
	bool CheckCollision();

	void update();

	void Draw();

	void Terminate();

    bool terminated = true;

};

#endif