#include "..\include\CApp.h"



void CApp::OnRender(){

    SDL_Rect stretchRect;
    stretchRect.x = 0;
    stretchRect.y = 0;
    stretchRect.w = WindowSurface->w;
    stretchRect.h = WindowSurface->h;

    //write out the original surface to the window surface
    SDL_BlitSurface(OriginalSurface, NULL, WindowSurface, NULL);

    //write the image onto the window service over the original surface
    //SDL_BlitSurface(ImageSurface, NULL, WindowSurface, NULL);
    SDL_BlitScaled(ImageSurface, NULL, WindowSurface, &stretchRect);

    SDL_UpdateWindowSurface(Window);

}


SDL_Surface* CApp::LoadImage(std::string file){

    SDL_Surface* OptimizedSurface;

    SDL_Surface* surface = IMG_Load(file.c_str());

    OptimizedSurface = SDL_ConvertSurface(surface, WindowSurface->format, NULL);

    SDL_FreeSurface(surface);

    if (OptimizedSurface == NULL){
        printf("Unable to load image %s! SDL Error: %s\n", file.c_str(), SDL_GetError());
    }
    return OptimizedSurface;
}
