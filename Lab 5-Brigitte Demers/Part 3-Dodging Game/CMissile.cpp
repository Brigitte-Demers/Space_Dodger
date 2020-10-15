//#include "CMissile.h"
//#include <string>
//
//using namespace std;
//
//CMissile::CMissile() 
//{
//	current_image = 0; // Added to animate the missiles.
//}
//
//CMissile::CMissile(string s, int x = 0, int y = 0, int vx = 0, int vy = 0)
//{
//	imagename = s;
//	position.x = x;
//	position.y = y;
//	velocity.x = vx;
//	velocity.y = vy;
//	loaded = false;
//}
//
//int CMissile::load_missile_sheet(SDL_Renderer *renderer)
//{
//    SDL_Surface *temp;
//
//    /* Load the sprite image */
//    temp = SDL_LoadBMP(imagename.c_str());
//    if (temp == NULL)
//    {
//        fprintf(stderr, "Couldn't load %s: %s", imagename, SDL_GetError());
//        return (-1);
//    }
//    position.w = temp->w;
//    position.h = temp->h;
//
//    /* Set transparent pixel as the pixel at (0,0) */
//    if (temp->format->palette)
//    {
//        SDL_SetColorKey(temp, SDL_TRUE, *(Uint8 *) temp->pixels);
//    }
//    else
//    {
//        switch (temp->format->BitsPerPixel)
//        {
//        case 15:
//            SDL_SetColorKey(temp, SDL_TRUE,
//                            (*(Uint16 *) temp->pixels) & 0x00007FFF);
//            break;
//        case 16:
//            SDL_SetColorKey(temp, SDL_TRUE, *(Uint16 *) temp->pixels);
//            break;
//        case 24:
//            SDL_SetColorKey(temp, SDL_TRUE,
//                            (*(Uint32 *) temp->pixels) & 0x00FFFFFF);
//            break;
//        case 32:
//            SDL_SetColorKey(temp, SDL_TRUE, *(Uint32 *) temp->pixels);
//            break;
//        }
//    }
//
//    /* Create textures from the image */
//    texture = SDL_CreateTextureFromSurface(renderer, temp);
//    if (!texture)
//    {
//        fprintf(stderr, "Couldn't create texture: %s\n", SDL_GetError());
//        SDL_FreeSurface(temp);
//        return (-1);
//    }
//    SDL_FreeSurface(temp);
//
//    /* We're ready to roll. :) */
//    return (0);
//}
//
//void CMissile::display(SDL_Renderer *r, SDL_Rect *pos, bool gotonext) // Altered to animate missiles.
//{
//	SDL_RenderCopy(r, texture, &images[current_image], pos);
//	if (gotonext)
//	{
//		current_image++;
//		if (current_image >= maximum_images)
//			current_image = 0;
//	}
//}
//
//void CMissile::config_sheet(int num_of_images, int sx, int sy, int sw, int sh, int wx, int hy, int border) // Added to animate missiles.
//{
//	SDL_Rect *pr;
//	int curx, cury;
//	int working_rec = 0;
//	int working_row = 1;
//	int working_col = 1;
//
//	curx = sx;
//	cury = sy;
//	while (working_rec < num_of_images && working_row <= hy)
//	{
//		pr = &images[working_rec];
//		pr->x = curx;
//		pr->y = cury;
//		pr->w = sw;
//		pr->h = sh;
//		working_col++;
//		working_rec++;
//		curx += sw + border;
//		if (working_col > wx)
//		{
//			working_row++;
//			working_col = 1;
//			cury += sh + border;
//			curx = sx;
//		}
//
//	}
//	maximum_images = num_of_images;
//}
//
//void CMissile::move()
//{
//    SDL_Rect *p;
//    SDL_Rect *v;
//
//    p = &position;
//    v = &velocity;
//    p->x += v->x;
//    if ((p->x < 0) || (p->x >= (window_w - p->w)))
//    {
//        v->x = -v->x;
//        p->x += v->x;
//    }
//    p->y += v->y;
//    if ((p->y < 0) || (p->y >= (window_h - p->h)))
//    {
//        v->y = -v->y;
//        p->y += v->y;
//    }
//}
//
