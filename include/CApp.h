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

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;




class LTexture {
public:
        LTexture();
        ~LTexture();
        bool loadFromFile(std::string path, SDL_Renderer* renderer);
        void free();
        void render(int x, int y, SDL_Renderer* renderer, SDL_Rect* clip);
        int getWidth();
        int getHeight();

private:


    SDL_Texture* mTexture;

    int mWidth;
    int mHeight;
};



class CApp {

private:
    bool Running;
    SDL_Window* Window;
    SDL_Surface* WindowSurface;
    SDL_Surface* ImageSurface;

    std::vector<SDL_Surface*> KeyPressSurface;
    SDL_Renderer* Renderer;
    SDL_Rect gSpriteClips[4];
    LTexture gSpriteSheetTexture;



public:
    CApp();
    int OnExecute();


public:
    bool OnInit();
    void OnEvent(SDL_Event *Event);
    void OnLoop();
    void OnRender();
    void OnRenderPrimitive();
    void OnCleanup();

};




#endif


