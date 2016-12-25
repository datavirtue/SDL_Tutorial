#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string>
#include <vector>
#include "..\include\EventConstants.h"

class CApp {

private:
    bool Running;
    SDL_Window* Window;
    SDL_Surface* WindowSurface;
    SDL_Surface* ImageSurface;

    SDL_Surface* OriginalSurface;
    std::vector<SDL_Surface*> KeyPressSurface;

public:
    CApp();
    int OnExecute();


public:
    bool OnInit();
    void OnEvent(SDL_Event *Event);
    void OnLoop();
    void OnRender();
    void OnCleanup();
    SDL_Surface* LoadImage(std::string file);


};
#endif


