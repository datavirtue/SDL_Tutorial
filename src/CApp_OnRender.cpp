#include "..\include\CApp.h"


void CApp::OnRender(){

    ImageSurface = SDL_LoadBMP(".\\image.bmp");

    SDL_BlitSurface( ImageSurface, NULL, WindowSurface, NULL );
    SDL_UpdateWindowSurface(Window);

}
