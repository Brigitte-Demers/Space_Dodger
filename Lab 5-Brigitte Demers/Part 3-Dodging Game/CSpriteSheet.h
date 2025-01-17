#ifndef CSPRITESHEET_H
#define CSPRITESHEET_H

#include <SDL.h>
#include <string>
#include "CPlayer.h" // Includes the CPlayer header file.

using namespace std;

#define MAX_SPRITE_IMAGES 100

class CSpriteSheet : public CPlayer // Inherits CPlayer functionality.
{
public:
	string filename;	//filename of spritesheet
	int max_images;		//max images in spritesheet
	int cur_image;		//current image displayed in spritesheet
	int w_width;		//Whole width and height of spritesheet
	int w_height;
	SDL_Rect images[MAX_SPRITE_IMAGES];
	CSpriteSheet();				//constructor
	virtual ~CSpriteSheet();	//destructor
	void set_sheet(string s) { filename = s; }
	int load_sheet(SDL_Renderer *renderer);
	void config_sheet(int num_of_images, int sx, int sy, int sw, int sh, int wx, int hy, int border);
	void play(SDL_Renderer *r, SDL_Rect *pos, bool gotonext);
	void rewind() { cur_image = 0; }
protected:
private:
	SDL_Texture *texture;
	SDL_Surface *ps;
};
#endif // CSPRITESHEET_H