#include "..\include\CApp.h"

CApp::CApp(){
    Window = NULL;

    Running = true;
}

const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

int CApp::OnExecute(){
    if(OnInit() == false){
        return -1;
    }

    SDL_Event Event;

    /* The game loop */
    while(Running){
        /*
            SDL wraps OS event handling.  We pass in an address
            (handled as a pointer in the SDL code) for an SDL Event
            variable and the loop executes for each event in the queue
            populating that variable with event data.  We use that event
            data to make decisions and branch our code in the OnEvent method.
        */
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




