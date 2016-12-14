#include "..\include\CApp.h"

void CApp::OnEvent(SDL_Event *Event){

    /* SDL_QUIT event type is triggered when we X out a window! */
    if(Event->type == SDL_QUIT){

        Running = false;
    }


}
