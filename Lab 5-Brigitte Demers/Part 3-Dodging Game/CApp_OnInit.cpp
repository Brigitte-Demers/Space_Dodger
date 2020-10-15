#include "CApp.h"
#include <stdlib.h>
#include <time.h>

bool CApp::OnInit()
{
    int i;

	TTF_Init();		//starts up SDL_ttf. 
	// Loads our font with font size.
	font = TTF_OpenFont("earthorbiter.ttf", 25);
	color = { 127, 127, 127 }; // Makes the text colour grey.
	score; // The score of the player, affected by how many missiles are avoided or collided with.
	numofScrolls;
	numofLivesLeft = 20; // The amount of lives you have, decreased by every collision with a missile.
	speedFactor;

    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK)<0)
    {
        return false;
    }
    window = SDL_CreateWindow("Basic SDL 2.0 Scrolling",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window)
        return false;
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
        return false;

    srand(time(NULL));

    for (i = 0; i < NUM_SPRITES; ++i) 
	{
		allmissiles[i].set_sheet("missileshopefully.bmp"); 
		if (allmissiles[i].load_sheet(renderer) != 0) // Makes all of the missiles appear. I wrote it wrong, that's why only one showed up originally.
		{
			printf("Bad load of Missile animation file\n");
		}
		// Added to animate missiles.
		allmissiles[i].config_sheet(20, 0, 0, 20, 100, 12, 3, 0);
		allmissiles[i].position.h = allmissiles[i].images[0].h;
		allmissiles[i].position.w = allmissiles[i].images[0].w;
        allmissiles[i].position.x = rand() % (window_w);
        allmissiles[i].position.y = -rand() % (400); // The minus in front of the rand makes the missiles start before the visible play screen.
		allmissiles[i].velocity.y = rand() % (MAX_SPEED)+1; // Makes the missiles move downward. Makes it a random velocity downwards.
    }
	// Loads ship basically.
	PlayerCharacter.set_sheet("orangeshipspritesheet.bmp"); // Added to animate the ship.
	if (PlayerCharacter.load_sheet(renderer) != 0)
	{
		printf("Bad load of Player Character animation file\n");
	}
	// Added to animate ship.
	PlayerCharacter.config_sheet(15, 0, 0, 91, 144, 5, 3, 0); // Spritesheet configuration. 
	PlayerCharacter.position.h = PlayerCharacter.images[0].h;
	PlayerCharacter.position.w = PlayerCharacter.images[0].w;
	PlayerCharacter.position.x = WINDOW_WIDTH/2 - 55; // Positions the ship in the middle of the screen
	PlayerCharacter.position.y = 666; // Positions the ship at the bottom of the screen.

	// This is to load the background.
	Space.imagename = "PinkSpace.bmp";
	Space.loadPlayer(renderer);
	Space.set_scroll_loc(0, 0, window_w, window_h);
	return true;
}