// GameCode.cpp		Version 11			5/3/08	
// These three functions form the basis of a game loop in the window created in the
// wincode.cpp file

#include "gamecode.h"
#include "mydrawengine.h"
#include "mypicture.h"
#include "mysoundengine.h"
#include "mysound.h"
#include "myinputs.h"
#include <time.h>
#include "gametimer.h"
#include "errorlogger.h"
#include <math.h>
#include "playerNyan.h"
#include "background.h"
#include "obstacol.h"  

MyDrawEngine* pTheDrawEngine;	// A pointer to the drawing engine
MySoundEngine* pTheSoundEngine;	// A pointer to the sound engine
MyInputs* pTheInputs;

extern HWND gHwnd;				// A handle to the main window application (created and declared in wincode.cpp).
extern HINSTANCE g_hinstance;	// A handle to the program instance

// Your global objects ***********************************************************************
BG_Image* back;
obstacol *obstacle[4];
playerNyan* NYAN;
int random_number ;
time_t new_time, prev_time;
// Your global functions *********************************************************************
MySound* pSoundObject;


// The game !!! *********************************************************************************

ErrorType GameInit(bool bFullScreen)
// Called once before entering game loop. 
// Use this function to set up the program
// gHwnd is the handle to the window and is required by the constructors for the engines
{
	// Create the engines - this should be done before creating other DDraw objects
	pTheDrawEngine = MyDrawEngine::Start(SCREENWIDTH, SCREENHEIGHT, COLOURDEPTH, gHwnd, bFullScreen);
	pTheSoundEngine = MySoundEngine::Start(gHwnd);
	pTheInputs = MyInputs::Start(g_hinstance, gHwnd);
	srand(time(NULL));

	back = new BG_Image();		//loading the background image.
	back->init();
	/*obstacle = new obstacol();
	
	random_number = rand() % 4;
	obstacle->init(random_number, 1);
	*/
	NYAN = new playerNyan();		//loading the magical cat.
	NYAN->init();
	
	//int i = rand() % 4;

	for (int i = 0; i < 4; i++)		//this was the most interesting part: creating the obstacles!
		obstacle[i] = new obstacol();
	

    pSoundObject = new MySound();		//funky music.
    pSoundObject->LoadWave("Nyan Cat.wav");
    pSoundObject->Play(0);

	prev_time = time(NULL);
    
    
    return (SUCCESS);
// ******************************************************************
}

ErrorType GameMain()
// Called repeatedly - the game loop
{
	//  validation routine - should be able to alt-tab out of program
	// (Done in game main just to show that it needs to be done - better to do in MyDrawEngine. really)

	//Instead of instantiating the obstacles randomly, i chosed to instantiate them after some time. (my original idea was to have only 5-6 objects on the screen, ONLY. but in some cases the obstacles were overlapping.
	if(pTheDrawEngine->Validate()==FAILURE) return FAILURE;
	int i;

	new_time = time(NULL);
	
	if (rand() % 30 == 0 && difftime(new_time, prev_time) > 0.5)
	{
		prev_time = new_time;

		for (i = 0; i < 4; i++)
			if (obstacle[i]->terminated)
			{
				obstacle[i] = new obstacol();
				obstacle[i] -> init(rand() % 4, rand() % 2);
				break;
			}
	}
	
    //CODE GOES HEREs

	
	
	back->update();
	back->Draw();
	//obstacle->update();
	//obstacle->Draw();
	NYAN->update();
	NYAN->Draw();

	//obstacle 
	for (i = 0; i < 4; i++)
	if (!obstacle[i]->terminated)
	{
		obstacle[i]->update();
		obstacle[i]->Draw();
	}


	//Flip and clear the back buffer
	pTheDrawEngine->Flip();
	pTheDrawEngine->ClearBackBuffer();
	return SUCCESS;
}

// ***********************************************************

void GameShutdown()		
// called after the game loop is finished
{ 
	back->Terminate();
	delete back;
	//obstacle->Terminate();
	delete obstacle;
	NYAN->Terminate();
	delete NYAN;
    // (engines must be terminated last)
	pTheDrawEngine->Terminate();
	pTheSoundEngine->Terminate();
	pTheInputs->Terminate();   
}



