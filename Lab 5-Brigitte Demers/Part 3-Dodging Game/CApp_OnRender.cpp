#include "CApp.h"

void CApp::OnRender()
{
	SDL_SetRenderDrawColor(renderer, 0xA0, 0xA0, 0xA0, 0xFF);
	SDL_RenderClear(renderer);    
	// Moved these to from OnLoop, cause this is the render function... so yeah. Keep code clean.
	// Try to put all objects that are being rendered in here. Be careful of your render order!

	// This has to be first, otherwise the background will load up and cover the sprites.
	Space.display(renderer);

	int i;

	for (i = 0; i < NUM_SPRITES; ++i)
	{
		static Uint32 cnt = 0;

		if (cnt % 2 == 0)
			allmissiles[i].play(renderer, &allmissiles[i].position, true); // Renders missiles.
		else                                                                 
			allmissiles[i].play(renderer, &allmissiles[i].position, false);
		cnt++;
	}

	displayGameStats(10, 10, "Score: %3d", score);
	displayGameStats(10, 30, "Number Of Scrolls: %2d", numofScrolls);
	displayGameStats(10, 50, "Number Of Lives Left: %2d", numofLivesLeft);
	displayGameStats(10, 70, "Speed Factor: %2d", speedFactor);

	static Uint32 cnt = 0;

	if (cnt % 2 == 0)
		PlayerCharacter.play(renderer, &PlayerCharacter.position, true); // Renders player character.
	else
		PlayerCharacter.play(renderer, &PlayerCharacter.position, false);
	cnt++;

    /* Update the screen! */
    SDL_RenderPresent(renderer);
    SDL_Delay(10);
    SDL_Delay(time_left());
    next_time += TICK_INTERVAL;
}