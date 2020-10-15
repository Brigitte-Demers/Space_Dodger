#include "CApp.h"

void CApp::OnCleanup() {
    //SDL_FreeSurface(Surf_Display);
    SDL_Quit();

	TTF_CloseFont(font);			//free the font resource.
	TTF_Quit(); 				//shut down the SDL_ttf subsystem.
}