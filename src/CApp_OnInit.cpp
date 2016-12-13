#include "..\include\CApp.h"

bool CApp::OnInit(){
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0 ){
        return false;
    }

    Window = SDL_CreateWindow("My Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

    PrimarySurface = SDL_GetWindowSurface(Window);

    if ((Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED)) == NULL){
        return false;
    }

    if (Window == NULL ){
        return false;
    }

    SDL_SetRenderDrawColor(Renderer, 0x00, 0x00, 0x00, 0xFF);

    return true;
}
