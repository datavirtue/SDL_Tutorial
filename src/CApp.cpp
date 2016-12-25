#include "..\include\CApp.h"

CApp::CApp(){
    Window = NULL;

    Running = true;
}

    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    std::string path = ".\\assets\\image.bmp";


int CApp::OnExecute(){
    if(OnInit() == false){
        return -1;
    }

    SDL_Event Event;


    //KeyPressSurface = new SDL_Surface [KEY_PRESS_SURFACE_TOTAL];

    //Load default surface to render surface
    ImageSurface = KeyPressSurface.at(KEY_PRESS_SURFACE_DEFAULT);

    /* The game loop */
    while(Running){
        /*
            SDL wraps OS event handling.  We pass in an address
            (handled as.\\assets\\image.bmp a pointer in the SDL code) for an SDL Event
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




