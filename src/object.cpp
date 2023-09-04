
#include "include.hpp"
#include "define.hpp"
#include "structs.hpp"
#include "object.hpp"

// Game classes
// Base entity in-game class

Vehicle( SDL_Texture* body, Wheel* subEntities[]){
    Tir
};

void Vehicle::blit(){
    for(int i=0;i<(sizeof(links)/sizeof(*links));++i){
        links[i].blit();
    }
};

void Vehicle::update(){
    for(int i=0;i<(sizeof(links)/sizeof(*links));++i){
        links[i].update(x, y);
    }
};