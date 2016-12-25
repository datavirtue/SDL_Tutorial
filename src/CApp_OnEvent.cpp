#include "..\include\CApp.h"

void CApp::OnEvent(SDL_Event *Event){

    /* SDL_QUIT event type is triggered when we X out a window! */
    if(Event->type == SDL_QUIT){

        Running = false;
    }else if (Event->type == SDL_KEYDOWN){

        switch(Event->key.keysym.sym) {

        case SDLK_UP:
            ImageSurface = KeyPressSurface.at(KEY_PRESS_SURFACE_UP);
            break;
        case SDLK_DOWN:
            ImageSurface = KeyPressSurface.at(KEY_PRESS_SURFACE_DOWN);
            break;
        case SDLK_LEFT:
            ImageSurface = KeyPressSurface.at(KEY_PRESS_SURFACE_LEFT);
            break;
        case SDLK_RIGHT:
            ImageSurface = KeyPressSurface.at(KEY_PRESS_SURFACE_RIGHT);
            break;
        default:
            ImageSurface = KeyPressSurface.at(KEY_PRESS_SURFACE_DEFAULT);
            break;


        }

    }


}
