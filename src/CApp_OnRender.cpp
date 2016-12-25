#include "..\include\CApp.h"



void CApp::OnRender(){


    //SDL_UpdateWindowSurface(Window);

    SDL_BlitSurface( ImageSurface, NULL, OriginalSurface, NULL );
    SDL_BlitSurface( OriginalSurface, NULL, WindowSurface, NULL );
    SDL_UpdateWindowSurface(Window);

}


SDL_Surface* CApp::LoadImage(std::string file){

    SDL_Surface* surface = IMG_Load(file.c_str());

    if (surface == NULL){
        printf("Unable to load image %s! SDL Error: %s\n", file.c_str(), SDL_GetError());
    }
    return surface;
}
