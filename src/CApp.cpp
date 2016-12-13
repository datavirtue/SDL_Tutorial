#include "..\include\CApp.h"

CApp::CApp(){
    Window = NULL;

    Running = true;
}

int CApp::OnExecute(){
    if(OnInit() == false){
        return -1;
    }

    SDL_Event Event;

    while(Running){
        while(SDL_PollEvent(&Event)){
            OnEvent(&Event);
        }
        OnLoop();
        OnRender();
    }

    OnCleanup();

    return 0;

}

int WinMain(int argc, char *agv[]){

    CApp theApp;
    return theApp.OnExecute();

}




