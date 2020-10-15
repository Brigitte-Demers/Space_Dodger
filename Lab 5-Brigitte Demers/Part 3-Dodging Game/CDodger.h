//#ifndef CDODGER_H
//#define CDODGER_H
//
//#include <SDL.h>
//#include "mywindow.h"
//#include <string>
//
//using namespace std;
//
//#define MAX_SPRITE_IMAGES 100 // Added to animate the ship.
//
///* Implement a sprite as a player.... */
//
//class CDodger
//{
//public:
//	bool loaded;
//	string imagename;
//	int maximum_images; // Maximum ammount of images in spritesheet, added to animate ship.
//	int current_image; // Current spritesheet image displayed, added to animate ship.
//	int sheet_width; // Whole width of spritesheet, added to animate ship.
//	int sheet_height; // Whole height of spritesheet, added to animate ship.
//	SDL_Rect position;
//	SDL_Rect velocity;
//	SDL_Rect images[MAX_SPRITE_IMAGES]; // Added to try to animate ship.
//	CDodger(); // Constructor.
//	void set_sheet(string s) { imagename = s; }
//	int load_ship_sheet(SDL_Renderer *renderer); // Altered to try to animate ship.
//	void config_sheet(int num_of_images, int sx, int sy, int sw, int sh, int wx, int hy, int border); // Added to try to animate ship.
//	void display(SDL_Renderer *r, SDL_Rect *pos, bool gotonext); // Altered to try to animate ship.
//	void rewind() { current_image = 0; }
//
//	CDodger(string s, int x, int y, int vx, int vy);
//
//	void move();
//protected:
//	SDL_Texture *texture;
//	SDL_Surface *ps;
//};
//#endif
