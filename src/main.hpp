#pragma once

#include "include.hpp"

// Function of getting collision of 2 objects
bool isCollide(SDL_Rect rect1, SDL_Rect rect2);

// Function of initialasing 
void initSDL();

// Function of closing and deinitialasing all libraries and files
void cleanup(void);

// Main function
int main(int argv, char** args);