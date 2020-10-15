#ifndef CSPRITESHEET_H
#define CSPRITESHEET_H

#include <SDL.h>
#include <string>

using namespace std;

#define MAX_SPRITE_IMAGES 100


class CSpriteSheet
{
public:
	string filename;	// Filename of the sprite sheet.
	int max_images;		// Max images in the sprite sheet.
	int cur_image;		// Current image displayed in sprite sheet.
	int w_width;		// Whole width and height of sprite sheet.
	int w_height;
	SDL_Rect position;
	SDL_Rect velocity;
	SDL_Rect images[MAX_SPRITE_IMAGES];
	CSpriteSheet();				// Constructor.
	virtual ~CSpriteSheet();	// Destructor.
	void set_sheet(string s) { filename = s; }
	int load_sheet(SDL_Renderer *renderer);
	void config_sheet(int num_of_images, int sx, int sy, int sw, int sh, int wx, int hy, int border);
	/*
	int num_of_images    How many images to extract from texture
	 int sx,             Start image x loc in texture
	  int sy,            Start image y loc in texture
	   int sw,           Width of ONE image in texture
		int sh,          Height of ONE image in texture
		 int wx,         How many images on ONE row
		  int hy,        How many rows of images on texture
		   int border    How many pixels between images

	Note: Images are not really extracted... locations are saved to allow quick display...

*/
	void play(SDL_Renderer *r, SDL_Rect *pos, bool gotonext);
	void rewind() { cur_image = 0; }
protected:
private:
	SDL_Texture *texture;
	SDL_Surface *ps;
};

#endif // CSPRITESHEET_H
