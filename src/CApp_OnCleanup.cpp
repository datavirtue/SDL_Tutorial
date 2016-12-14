#include "..\include\CApp.h"


void CApp::OnCleanup() {

    if(WindowSurface) {
		SDL_FreeSurface(WindowSurface);
		WindowSurface = NULL;
	}

	if (ImageSurface){

        SDL_FreeSurface(ImageSurface);
        ImageSurface = NULL;
	}

	if(Window) {
		SDL_DestroyWindow(Window);
		Window = NULL;
	}

    SDL_Quit();
}
