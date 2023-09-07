#pragma once

#include "include.hpp"
#include "entity.hpp"

// Game classes
// Base entity in-game class
class Vehicle{
private:
    SDL_Texture *texture;
    int x, y;
    float rotation;
    SDL_Rect dest;
    Wheel* tires[2];
public:
    Vehicle( SDL_Texture* body, Wheel* fwheel, Wheel* swheel );
    void blit();
    void update( int ddx );
};

extern Vehicle Car;