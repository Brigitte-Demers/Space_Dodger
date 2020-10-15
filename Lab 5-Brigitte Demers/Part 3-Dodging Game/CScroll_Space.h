#ifndef CSCROLL_SPACE_H
#define CSCROLL_SPACE_H

#include "CPlayer.h"

class CScroll_Space : public CPlayer
{
    public:
        CScroll_Space();
        virtual ~CScroll_Space();
        SDL_Rect destscr;
        SDL_Rect src;   // Where to get Image (Part of Big Image).
        void display(SDL_Renderer *prenderer);
        int loadPlayer(SDL_Renderer *prenderer);
        void set_scroll_loc(int sx, int sy, int sw, int sh)
        {
            src.x = sx;
            src.y = sy;
            src.w = sw,
            src.h = sh;
        }
        void move(int &ScrollCount); // Counts the number of scrolls.
    protected:
    private:
};
#endif // CSCROLL_PLAYER_H