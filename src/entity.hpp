#pragma once

#include "include.hpp"

// Function of getting collision of 2 rectangles
bool rectCoolideExternal(SDL_Rect rect1, SDL_Rect rect2);

// Game classes
// Base entity in-game class
class Entity{
protected:
    SDL_Texture *texture;
    SDL_Rect dest;
    SDL_Point location;
public:
    //Entity(int cx, int cy, SDL_Texture* newTexture);
    void blit();
    void update(int cx, int cy);
};

class Wheel:public Entity
{
private:
    float rotate;
    int cx, cy;
public:
    Wheel(const int cx, const int cy, SDL_Texture* newTexture);
    void set(int x);
    //~Wheel();
    void blit(int x, int y, float angle);
    //
    void blit(int x);
    // Function of 
    int update(int x, int y);
    void update(int x);
    //
    int getH(int x);
};
