#include "include.hpp"
#include "define.hpp"
#include "structs.hpp"

#include "im_load.hpp"
#include "perlin.hpp"

// Global variables of other
SDL_Texture *Textures[IMG_count];  // Array of all textures
App app;

// Flags of running
bool running = true;  // Flag of main cycle work

// Function of getting collision of 2 objects
bool isCollide(SDL_Rect rect1, SDL_Rect rect2){
    return (
        ((rect1.y < rect2.y+rect2.h) &&
        (rect1.y+rect1.h > rect2.y))
        &&
        ((rect1.x < rect2.x+rect2.w) &&
        (rect1.x+rect1.w > rect2.x))
    );
}

// Game classes
// Base entity in-game class
class Entity{
protected:
    SDL_Texture *texture;
    SDL_Rect dest;
public:
    Entity(){};
    ~Entity(){};
    void blit(){
	    SDL_RenderCopy(app.renderer, texture, NULL, &dest); 
    };
};


// Function of initialasing 
void initSDL()
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);  // Initialising SDL libarary

	app.window = SDL_CreateWindow(WINDOWNAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);
	
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);  // Initialasing image library
    TTF_Init();  // Initialasing fonts library
    //Mix_Init(MIX_INIT_OGG | MIX_INIT_FLAC);
    //Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
}
// Function of closing and deinitialasing all libraries and files
void cleanup(void)
{
    // Closing all outside libraries
	SDL_DestroyRenderer(app.renderer);
	SDL_DestroyWindow(app.window);
	
    //Mix_CloseAudio();
    Mix_Quit();
	SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}

// Main function
int main(int argv, char** args){
    initSDL();  // Initialasing of main SDL library
    loadAllTextures();  // Loading sprites to the game
    SDL_Event event;
    int x = 0; int dx = 0;

    const siv::PerlinNoise::seed_type seed = 123456;
	const siv::PerlinNoise perlin{ seed };

    int groundW = 0; int grassH = 0;
    SDL_QueryTexture(Textures[IMG_GRND], NULL, NULL, &groundW, NULL);
    SDL_QueryTexture(Textures[IMG_SURF], NULL, NULL, NULL, &grassH);

    // Main game cycle
	while(running)
	{
        // Showing loading screen

        // Getting events
        while( SDL_PollEvent(&event) != 0 ){  
            if (event.type == SDL_QUIT){
                running = false;  // Exit from program
            }
            if (event.type == SDL_KEYDOWN) {
                // Resseting field and next new generation
                if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a){
                    dx = -5;
                }
                if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d){
                    dx = 5;
                }
            }
            if (event.type == SDL_KEYUP) {
                if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_RIGHT 
                || event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_d) {
                    dx = 0;
                }
            }
        }
        x += dx;
        if(x < 0){x=0;}
        
        // Drawing objects at screen
        SDL_SetRenderDrawColor(app.renderer, 77, 143, 172, 255);  // Drawing shield bar
        SDL_RenderClear(app.renderer);

        for(int ddx=0; ddx<SCREEN_WIDTH;++ddx){
            int h = perlin.normalizedOctave1D_01((x+ddx)*0.005, 4, 0.5)*300+250;
            SDL_Rect srcStn = {(x+ddx) % groundW, 0, 1, SCREEN_HEIGHT-h};
            SDL_Rect desStn = {ddx, h, 1, SCREEN_HEIGHT-h};
            SDL_RenderCopyEx(app.renderer, Textures[IMG_GRND], &srcStn, &desStn, 0, NULL, SDL_FLIP_NONE);
            SDL_Rect srcGrs = {(x+ddx) % groundW, 0, 1, grassH};
            SDL_Rect desGrs = {ddx, h-grassH/2, 1, grassH};
            SDL_RenderCopyEx(app.renderer, Textures[IMG_SURF], &srcGrs, &desGrs, 0, NULL, SDL_FLIP_NONE);
        }

        SDL_RenderPresent(app.renderer);  // Blitting textures on screen
		SDL_Delay(1000 / FPS);  // Delaying time to decrease CPU loading
	}

    // Cleaning all data
    unloadTextures();
    //unloadAudio();
    cleanup();
	return 0;
}