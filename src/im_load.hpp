#pragma once

#include <string>
#include "include.hpp"
#include "structs.hpp"

// Names of images in array to using
enum IMG_names{
    // Base hud elements
    IMG_point,
    IMG_slider_line,
    IMG_slider_button,
    IMG_line,
    // Images of terrain
    IMG_SURF,
    IMG_GRND,
    IMG_SKY,
    // Images of car
    IMG_body,
    IMG_tire,
    IMG_antenna,
    // Final count of textures in total
    IMG_count
};

// Load all textures
bool loadAllTextures();

// Load texture file to array
void loadTexture(IMG_names number, std::string name);

// Function of unloading 
void unloadTextures();