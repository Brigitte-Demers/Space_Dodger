#include "CApp.h" // Includes the CApp header file.

void CApp::OnEvent(SDL_Event* Event)
{
	switch (Event->type)
	{
	 case SDL_QUIT:
	 case SDL_MOUSEMOTION:
		// Controls the player character with the mouse.
		PlayerCharacter.position.x = Event->motion.x;
		break;
	 case SDL_KEYDOWN:
		 if (Event->key.keysym.sym == SDLK_DOWN)
		 {
			 speedFactor = +1;
		 }
		 if (Event->key.keysym.sym == SDLK_UP)
		 {
			 speedFactor = -1;
		 }
		switch (Event->key.keysym.sym)
		{
		 case SDLK_ESCAPE:
			SDL_Quit();
			break;
		 case SDLK_DOWN:
			for (int i = 0; i < NUM_SPRITES; ++i)
			{
				allmissiles[i].velocity.y = (MAX_SPEED)+1;
			}
			break;
		 case SDLK_UP:
			 for (int i = 0; i < NUM_SPRITES; ++i)
			 {
				 allmissiles[i].velocity.y = (MAX_SPEED)-2;
			 }
			 break;
		}
	}
}