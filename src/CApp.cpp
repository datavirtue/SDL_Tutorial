#include "..\include\CApp.h"

CApp::CApp(){
    Window = NULL;
    Renderer = 0;
    Running = true;

    LTexture gFooTexture;
    LTexture gBackgroundTexture;

}




int CApp::OnExecute(){

    if(OnInit() == false){
        return -1;
    }

    SDL_Event Event;



    /* The game loop */
    while(Running){

        while(SDL_PollEvent(&Event)){
            OnEvent(&Event);
        }

        OnLoop();

        OnRender();
        //scanf("Pause..." );
    }

    OnCleanup();

    return 0;

}


void CApp::OnRender(){


    //Clear screen
    //SDL_SetRenderDrawColor( Renderer, 0xFF, 0xFF, 0xFF, 0xFF );

    SDL_RenderClear( Renderer );

    gBackgroundTexture.render(0,0, Renderer);

    gFooTexture.render(240,190, Renderer);

    printf("Render call Renderer %p\n", Renderer);

    SDL_RenderPresent( Renderer );

}


bool CApp::OnInit(){

    /* Print current working directory */
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
       fprintf(stdout, "Current working dir: %s\n", cwd);
    else
       perror("getcwd() error");


    bool success = true;

    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    if (SDL_Init(SDL_INIT_VIDEO) < 0 ){
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }

    //Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

    Window = SDL_CreateWindow("My Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
    if (Window == NULL){
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }



    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
    if (Renderer == NULL){
        success = false;
    }else {
        //SDL_SetRenderDrawColor(Renderer, 0xFF, 0xFF, 0xFF, 0xFF);

        //Initialize PNG loading
		int imgFlags = IMG_INIT_PNG;
		if( !( IMG_Init( imgFlags ) & imgFlags ) )
		{
			printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
			success = false;
		}
    }

     //Load Foo' texture
    if( !gFooTexture.loadFromFile( ".\\assets\\foo.png", Renderer ) )
    {
        printf( "Failed to load Foo' texture image!\n" );
        success = false;
    }

    //Load background texture
    if( !gBackgroundTexture.loadFromFile( ".\\assets\\background.png", Renderer ) )
    {
        printf( "Failed to load background texture image!\n" );
        success = false;
    }

    return success;
}


void CApp::OnCleanup() {

    gBackgroundTexture.free();
    gFooTexture.free();

	if(Window) {
		SDL_DestroyWindow(Window);
		Window = NULL;
	}

    SDL_DestroyRenderer(Renderer);

    IMG_Quit();
    SDL_Quit();
}



void CApp::OnLoop(){

}

void CApp::OnEvent(SDL_Event *Event){

    /* SDL_QUIT event type is triggered when we X out a window! */
    if(Event->type == SDL_QUIT){

        Running = false;
    }


}




int WinMain(int argc, char *agv[]){

    CApp theApp;
    return theApp.OnExecute();

}




