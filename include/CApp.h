#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL.h>

#include "..\include\CSurface.h"


class CApp {

private:
    bool Running;
    SDL_Window* Window;
    SDL_Renderer* Renderer = NULL;
	SDL_Surface* PrimarySurface = NULL;


public:
    CApp();
    int OnExecute();

public:
    bool OnInit();
    void OnEvent(SDL_Event *Event);
    void OnLoop();
    void OnRender();
    void OnCleanup();


};
#endif


