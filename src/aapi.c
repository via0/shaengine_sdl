/* aapi.c: Anything which interacts with...
    SDL in the level 1 basic baby development stage
    Bare Metal in the final based stage
    should go here!

    E.g. drawing graphics, handling user input, playing sound
    These will be treated differently depending on if we're using
    an existing library or we're writing our own insane bare metal
    functions...
*/

#include "aapi.h"

void app_initialize(s_app* app){
    memset(app, 0, sizeof(s_app));

    s_sdlApp* sdlApp = &app->sdlApp;
    sdl_setup(sdlApp);
    
    // not sure if we need atexit function since app/sdlApp are
    // on the stack, not on the heap like in tutorial
    // on_exit is nice because it lets us pass in sdlApp but
    // almost certainly isn't supported
    // on_exit(sdl_cleanup, sdlApp);

    // initialize textures... maybe this should happen on map load?
    app_loadTexture(app, "gfx/shae.png", INDEX_TEXTURE_SHAE_WALK0);

}

void app_prepareScene(s_app* app){
    s_sdlApp* sdlApp = &app->sdlApp;

    SDL_SetRenderDrawColor(sdlApp->renderer, 96, 128, 255, 255);
    SDL_RenderClear(sdlApp->renderer);
}

void app_handleInput(s_app* app){
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        switch (event.type){
            case SDL_QUIT:
                exit(0);
                break;

            default:
                break;
        }
    }
}

void app_presentScene(s_app* app){
    s_sdlApp* sdlApp = &app->sdlApp;

    SDL_RenderPresent(sdlApp->renderer);
}

void app_finishFrame(s_app* app){
    SDL_Delay(16);
}

void app_loadTexture(s_app* app, char *filename, int index){
    s_sdlApp* sdlApp = &app->sdlApp;

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);
    
    // Not checking for null ptr here because i'm straight!
    sdlApp->textures[index] = IMG_LoadTexture(sdlApp->renderer, filename);

}

void app_drawShae(s_app* app){
    s_sdlApp* sdlApp = &app->sdlApp;

    SDL_Rect dest;
    SDL_Texture* texture = sdlApp->textures[INDEX_TEXTURE_SHAE_WALK0];
    dest.x = 15;
    dest.y = 87;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(sdlApp->renderer, texture, NULL, &dest);
}

void sdl_setup(s_sdlApp* sdlApp){
    int rendererFlags, windowFlags;
    rendererFlags = SDL_RENDERER_ACCELERATED;
    windowFlags = 0;

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    sdlApp->window = SDL_CreateWindow("Shae when he's a window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

    if(!sdlApp->window){
        printf("Failed to open %d by %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    sdlApp->renderer = SDL_CreateRenderer(sdlApp->window, -1, rendererFlags);

    if(!sdlApp->renderer){
        printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }

    IMG_Init(IMG_INIT_PNG);

    SDL_ShowCursor(0);
}

void sdl_cleanup(s_sdlApp* sdlApp){
    SDL_DestroyRenderer(sdlApp->renderer);
    SDL_DestroyWindow(sdlApp->window);
    SDL_Quit();
}