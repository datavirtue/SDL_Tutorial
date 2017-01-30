#include "..\include\CApp.h"


bool Running;
SDL_Window* Window = NULL;
SDL_Surface* WindowSurface = NULL;
SDL_Surface* ImageSurface = NULL;
std::vector<SDL_Surface*> KeyPressSurface;
SDL_Renderer* Renderer;

LTexture gSpriteSheetTexture;
LTexture gBackground;

const int WALKING_ANIMATION_FRAMES = 4;
SDL_Rect gSpriteClips[WALKING_ANIMATION_FRAMES];

SDL_Rect* currentClip;
int frame = 0;

struct colorMap {
    Uint8 red;
    Uint8 green;
    Uint8 blue;
};

colorMap tColorMap;

CApp::CApp(){
    Window = NULL;
    Renderer = 0;
    Running = true;

    tColorMap.red = 1;
    tColorMap.green = 0;
    tColorMap.blue = 0;
    std::srand(254);
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

        //tColorMap.red = std::rand();
        //tColorMap.green = std::rand();
        //tColorMap.blue = std::rand();
        //printf("Color Map: %d %d %d", tColorMap.red, tColorMap.green, tColorMap.blue);

        OnRender();

    }

    OnCleanup();

    return 0;

}


void CApp::OnRender(){


    //Clear screen
    SDL_SetRenderDrawColor( Renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( Renderer );
    currentClip = &gSpriteClips[frame / 4];

    // Ideally we would create a grid addressing method to select the clip without thinking about all of the screen coordinates
    gBackground.render(0,0,Renderer, NULL);
    gSpriteSheetTexture.render(( SCREEN_WIDTH - currentClip->w ) / 2, ( SCREEN_HEIGHT - currentClip->h ) / 2, Renderer,  currentClip );
    //gSpriteSheetTexture.render(0,0, Renderer, &gSpriteClips[0]);
    //gSpriteSheetTexture.render(SCREEN_WIDTH - gSpriteClips[1].w, 0, Renderer, &gSpriteClips[1]);
    //gSpriteSheetTexture.render(0,SCREEN_HEIGHT - gSpriteClips[2].h, Renderer, &gSpriteClips[2]);
    //gSpriteSheetTexture.render(SCREEN_WIDTH - gSpriteClips[3].w, SCREEN_HEIGHT - gSpriteClips[3].h, Renderer, &gSpriteClips[3]);

    gSpriteSheetTexture.setBlendMode(SDL_BLENDMODE_BLEND);
    gSpriteSheetTexture.setAlpha(255);

    //Go to next frame
                ++frame;

                //Cycle animation
                if( frame / 4 >= WALKING_ANIMATION_FRAMES )
                {
                    frame = 0;
                }

    //gSpriteSheetTexture.setColor(tColorMap.red, tColorMap.green, tColorMap.blue);

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



    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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

    /*

        Load textures

    */

    gBackground.loadFromFile( ".\\assets\\background.png", Renderer );

    if( !gSpriteSheetTexture.loadFromFile( ".\\assets\\fooAnim.png", Renderer ) )
    {
        printf( "Failed to load Foo' texture image!\n" );
        success = false;
    }else {
       //Set top left sprite
        gSpriteClips[ 0 ].x =   0;
        gSpriteClips[ 0 ].y =   0;
        gSpriteClips[ 0 ].w = 64;
        gSpriteClips[ 0 ].h = 205;

        //Set top right sprite
        gSpriteClips[ 1 ].x = 64;
        gSpriteClips[ 1 ].y =   0;
        gSpriteClips[ 1 ].w = 64;
        gSpriteClips[ 1 ].h = 205;

        //Set bottom left sprite
        gSpriteClips[ 2 ].x = 128;
        gSpriteClips[ 2 ].y = 0;
        gSpriteClips[ 2 ].w = 64;
        gSpriteClips[ 2 ].h = 205;

        //Set bottom right sprite
        gSpriteClips[ 3 ].x = 196;
        gSpriteClips[ 3 ].y = 0;
        gSpriteClips[ 3 ].w = 64;
        gSpriteClips[ 3 ].h = 205;
    }

    return success;
}


void CApp::OnCleanup() {

    gSpriteSheetTexture.free();

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




