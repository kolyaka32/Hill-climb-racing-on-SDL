#pragma once

#include "include.hpp"

// Function of getting collision of 2 rectangles
bool rectCoolideExternal(SDL_Rect rect1, SDL_Rect rect2);

// Game classes
// Base entity in-game class
class Entity{
private:
    SDL_Texture *texture;
    SDL_Rect dest;
    SDL_Point location;
public:
    Entity(int cx, int cy, SDL_Texture* tex);
    void blit();
    void update(int cx, int cy);
    void set(int x, int y);
};

class Wheel:public Entity
{
private:
    float rotate;
public:
    Wheel(/* args */);
    ~Wheel();

    // Function of 
    SDL_Point update(int h);
};
