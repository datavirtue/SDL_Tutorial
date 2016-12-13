#include "..\include\CApp.h"


void CApp::OnRender(){

    SDL_RenderClear(Renderer);



	SDL_RenderPresent(Renderer);

}
