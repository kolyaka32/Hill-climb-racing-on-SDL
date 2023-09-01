#include "include.hpp"
#include "structs.hpp"

#include "im_load.hpp"

/*
    IMG_point,
    IMG_slider_line,
    IMG_slider_button,
    IMG_line,
    // Images of terrain
    IMG_SURF,
    IMG_GRND,
    IMG_SKY,
    // Final count of textures in total
    IMG_count
*/

//App app;
//SDL_Texture *Textures[IMG_count];

int c;  // Counter of loaded textures

// Load all textures
bool loadAllTextures(){
    c = 0;  // Loading textures with they names

    // Base hud elements
    loadTexture(IMG_point, "img/old textures/point.png");
    loadTexture(IMG_slider_line, "img/old textures/slider_line.png");
    loadTexture(IMG_slider_button, "img/old textures/slide_button.png");
    loadTexture(IMG_line, "img/old textures/line.png");

    // Images of terrain
    loadTexture(IMG_SURF, "img/surface/terrain-surface.png");
    loadTexture(IMG_GRND, "img/ground/terrain-ground.png");
    loadTexture(IMG_SKY, "img/sky/sky-bg.png");

    return (c == IMG_count);  // Returning correcting of loading
}

void loadTexture(IMG_names number, std::string name){
    SDL_Texture *temp_texture = IMG_LoadTexture(app.renderer, (name).std::string::c_str() );
    if(temp_texture != NULL){
        Textures[number] = temp_texture;
        c+=1;
    }
}

// Function of clearing data 
void unloadTextures(){
    for(int i = 0; i < IMG_count; ++i){
        SDL_DestroyTexture(Textures[i]);
        Textures[i] = NULL;
    }
}