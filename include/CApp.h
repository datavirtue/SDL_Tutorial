#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

class CApp {

private:
    bool Running;
    SDL_Window* Window;
    SDL_Surface* WindowSurface;
    SDL_Surface* ImageSurface;


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


