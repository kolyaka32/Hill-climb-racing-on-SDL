#pragma once

#include "include.hpp"

// Function of getting collision of 2 objects
bool isCollide(SDL_Rect rect1, SDL_Rect rect2);

// Game classes
// Base entity in-game class
class Entity{
protected:
    SDL_Texture *texture;
    SDL_Rect dest;
public:
    Entity();
    ~Entity();
    void blit();
};

// Function of initialasing 
void initSDL();

// Function of closing and deinitialasing all libraries and files
void cleanup(void);

// Main function
int main(int argv, char** args);