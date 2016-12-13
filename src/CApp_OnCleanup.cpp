#include "..\include\CApp.h"


void CApp::OnCleanup() {

    if(Renderer) {
		SDL_DestroyRenderer(Renderer);
		Renderer = NULL;
	}

	if(Window) {
		SDL_DestroyWindow(Window);
		Window = NULL;
	}

    SDL_Quit();
}
