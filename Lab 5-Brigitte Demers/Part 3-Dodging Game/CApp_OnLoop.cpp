#include "CApp.h"

void CApp::MoveSprites()
{
	int i;
    // Moves the sprite. Specifically the missile sprites.
    for (i = 0; i < NUM_SPRITES; ++i)
    {
		if (allmissiles[i].position.y > window_h)
		{
			allmissiles[i].position.x = rand() % (window_w - allmissiles[i].position.w); // Randomizes the missiles positions along the x axis (width wise). I believe.
			allmissiles[i].position.y = -rand() % (400); // The minus in front of the rand makes the missiles start before the visible play screen.
			allmissiles[i].velocity.y = rand() % (MAX_SPEED)+1; // Makes the missiles move downward. Makes it a random velocity downwards.
			allmissiles[i].velocity.x = 0; // Missile velocity along the x axis (width), always zero for the missiles.
			score += 1; // Gain one point for each missile avoided(Missile must reach the bottom of the screen).
		}

		if (checkCollision(PlayerCharacter.position, allmissiles[i].position) == true) // Checks for collisions between the missiles and the Player.
		{
			allmissiles[i].position.x = rand() % (window_w); // Randomizes the missiles positions along the x axis (width wise).
			allmissiles[i].position.y = -rand() % (400); // The minus in front of the rand makes the missiles start before the visible play screen.
			allmissiles[i].velocity.y = rand() % (MAX_SPEED)+1; // Makes the missiles move downward. Makes it a random velocity downwards.
			allmissiles[i].velocity.x = 0; // Missile velocity along the x axis (width), always zero for the missiles.
			score -= 2; // Lose 2 points for each missile collided with.
			numofLivesLeft -= 1; // Each collision loses one life.
		}

		if (numofLivesLeft == 0)
		{
			SDL_Quit(); // Exits the game once the lives have reached zero. 
		}

		allmissiles[i].move(); // Calls the move function for all of the missiles.
	}

	if ((PlayerCharacter.position.x < 0) || (PlayerCharacter.position.x >= (WINDOW_WIDTH - PlayerCharacter.images[0].w))) // If x position is less than 0, or x position is greater or = to window width - position width.
	{
		PlayerCharacter.position.x = WINDOW_WIDTH - PlayerCharacter.images[0].w; // Prevents the player character object from going off the right side of the screen.
	}
}

void CApp::OnLoop()
{
    MoveSprites();

	PlayerCharacter.move(); // Calls the move function for the player character, applying the CPlayer functionality to stop it from going out of bounds.

	Space.move(numofScrolls); // Calls on the move function for the background. And outputs the number of scrolls completed.
}