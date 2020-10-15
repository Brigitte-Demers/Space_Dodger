//#ifndef CMISSILE_H
//#define CMISSILE_H
//
//#include <SDL.h>
//#include "mywindow.h"
//#include <string>
//
//using namespace std;
//
//#define MAX_SPRITE_IMAGES 100 // This is added to animate the missiles.
//
///* Implement a sprite as an obstacle.... */
//
//class CMissile
//{
//    public:
//            bool loaded;
//			string imagename;
//			int maximum_images; // Maximum ammount of images in spritesheet, added to animate missiles.
//			int current_image; // Current spritesheet image displayed, added to animate missiles.
//			int sheet_width; // Whole width of spritesheet, added to animate missiles.
//			int sheet_height; // Whole height of spritesheet, added to animate missiles.
//            SDL_Rect position;
//            SDL_Rect velocity;
//			SDL_Rect images[MAX_SPRITE_IMAGES]; // Added to animate missiles.
//            CMissile();
//			void set_sheet(string s) { imagename = s; }
//			int load_missile_sheet(SDL_Renderer *renderer); // Altered to animate missiles.
//			void config_sheet(int num_of_images, int sx, int sy, int sw, int sh, int wx, int hy, int border); // Added to animate missiles.
//			void display(SDL_Renderer *r, SDL_Rect *pos, bool gotonext); // Altered to animate missiles.
//			void rewind() { current_image = 0; }
//			CMissile(string s, int x, int y, int vx, int vy);
//
//            void move();
//    protected:
//            SDL_Texture *texture;
//			SDL_Surface *ps; // Added to animate missiles.
//};
//#endif
