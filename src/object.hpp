#pragma once

#include "include.hpp"
#include "im_load.hpp"
#include "entity.hpp"

// Game classes
// Base entity in-game class
class Vehicle:public Entity{
private:
    int x, y;
    Wheel* tires;
public:
    Vehicle( SDL_Texture* body, Wheel* subEntities[]);
    void blit();
    void update();
};

extern Vehicle Car(
    Textures[IMG_body],
    {
        {20, 20, Textures[IMG_tire]},
        {60, 20, Textures[IMG_tire]}
    }
);