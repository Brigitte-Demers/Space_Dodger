#include "CScroll_Space.h"
#include "CApp.h"

CScroll_Space::CScroll_Space()
{
    //ctor
}

CScroll_Space::~CScroll_Space()
{
    //dtor
}

void CScroll_Space::display(SDL_Renderer *prenderer)
{
    SDL_RenderCopy(prenderer, texture, &src, &destscr);
}

int CScroll_Space::loadPlayer(SDL_Renderer *prenderer)
{
    int retval;

    retval = CPlayer::loadPlayer(prenderer);
    destscr.x = 0;
    destscr.y = 0;
    destscr.h = window_h;
    destscr.w = window_w;
    velocity.x = 1;
    velocity.y = 0;
    return (retval);
}

void CScroll_Space::move(int &ScrollCount)
{
    src.x += velocity.x;
    src.y += velocity.y;
    if (src.y >= position.h - window_h) // Adding the '-window_h' stops the image from stretching when it reaches the bottom.
    {
        velocity.y = -velocity.y;
        src.y += velocity.y;
    }
    if (src.y < 0 )
    {
        velocity.y = -velocity.y;
        src.y += velocity.y;
    }
    if (src.x >= position.w - window_w)   // Assumes that image is greater than window width..
    {
        velocity.x = -velocity.x;
        src.x += velocity.x;
		ScrollCount ++;
    }
    if (src.x < 0)
    {
        velocity.x = -velocity.x;
        src.x += velocity.x;
    }
}