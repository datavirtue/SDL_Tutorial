#include "..\include\CApp.h"


/* This takes care of the close function from the LazyFoo tutorial */

void CApp::OnCleanup() {

    if(WindowSurface) {
		SDL_FreeSurface(WindowSurface);
		WindowSurface = NULL;
	}

	if (ImageSurface){

        SDL_FreeSurface(ImageSurface);
        ImageSurface = NULL;
	}



    for (int i= 1; i < KeyPressSurface.size(); i++) {

        if (KeyPressSurface.at(i)){

            SDL_FreeSurface(KeyPressSurface.at(i));
            KeyPressSurface.at(i) = NULL;
        }
    }

	if(Window) {
		SDL_DestroyWindow(Window);
		Window = NULL;
	}

    SDL_Quit();
}
