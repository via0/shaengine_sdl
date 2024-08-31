/* aapi.h: Structs, unions, function prototypes, etc.
    needed for aapi.c
*/

#ifndef AAPI_H_INCLUDED
#define AAPI_H_INCLUDED

#include <SDL2/SDL.h>

/* Constants, defines, macros, etc. */
#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 720

/* This struct holds stuff only relevant to SDL
*/
typedef struct
{
    SDL_Renderer *renderer;
    SDL_Window   *window;
} s_sdlApp;

/* This struct holds graphics, inputs, outputs
*/
typedef struct
{
    s_sdlApp sdlApp;
} s_app;

/* Generic App Helpers (Call these outside aapi.c!) */
void app_initialize(s_app* app);
void app_prepareScene(s_app* app);
void app_handleInput(s_app* app);
void app_presentScene(s_app* app);
void app_finishFrame(s_app* app);

/* SDL Only Helpers (Only call in aapi.c!) */
void sdl_setup(s_sdlApp* sdlApp);
void sdl_cleanup(s_sdlApp* sdlApp);

#endif // AAPI_H_INCLUDED
