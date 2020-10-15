#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL.h>
#include "mywindow.h"
#include "CSpriteSheet.h" // Includes the CSpriteSheet header file.
#include "CScroll_Space.h" // Includes the CScroll_Space header file.
#include <SDL_ttf.h> // Includes the SDL_ttf library.

#define TICK_INTERVAL    10
#define NUM_SPRITES     15 // How many missiles there are. For some reason if it's less then 15 then some of the missiles just do not animate.
#define MAX_SPEED       4 // Changed the max speed to 3 so that each missiles speed varies.

class CApp
{
private:
	Uint32 next_time;
	SDL_Window *window;
	SDL_Renderer *renderer;
	CSpriteSheet allmissiles[NUM_SPRITES]; // Creates missile objects.
	CSpriteSheet PlayerCharacter; // Creates a Player Character object.
	CScroll_Space Space; // Creates a Space object.
	TTF_Font * font;			//font object we will use for the message.
	SDL_Color color;			//color of the message.
	SDL_Surface * messageSurface;	//surface that stores the message,
	SDL_Texture * messageTexture;	//surface is converted to a texture.
	SDL_Rect messageRect;		//location of the message.
	char message[100];			//the message string.
	bool Running;

public:
	CApp();
	Uint32 time_left(void);
	int OnExecute();

public:
	int LoadSprite(char *file, SDL_Texture* &psprite, SDL_Rect *prect); // 4/4.
	int score; // 4/4.
	int numofScrolls; // 4/4.
	int numofLivesLeft; // 4/4.
	int speedFactor; // 4/4.
	void OnEvent(SDL_Event* Event);
	void OnLoop();
	void OnRender();
	void MoveSprites();
	void displayGameStats(int x, int y, char* formattedString, int number);
	void OnCleanup();
	bool OnInit();
	bool checkCollision(SDL_Rect A, SDL_Rect B); // Collision detection code. 
};
#endif