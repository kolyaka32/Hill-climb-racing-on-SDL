
#include "include.hpp"
#include "define.hpp"
#include "structs.hpp"
#include "object.hpp"
#include "perlin.hpp"

// Game classes
// Base entity in-game class
/*
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
*/


Vehicle::Vehicle( SDL_Texture* body, Wheel* fwheel, Wheel* swheel ){
    texture = body;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    dest.w/=2; dest.h/=2;
    tires[0] = fwheel;
    tires[1] = swheel;
    x = 100; y = per(x);
    tires[0]->set(x); tires[1]->set(x);
    rotation = 0;
}

void Vehicle::blit(){
    dest.x = x; dest.y = y - 50;
    SDL_RenderCopyEx(app.renderer, texture, NULL, &dest, rotation*90, NULL, SDL_FLIP_NONE);
    for(int i=0; i<(sizeof(tires)/sizeof(*tires)); ++i){
        //tires[i]->blit(x, y, rotation);
        tires[i]->blit(x);
    }
}

void Vehicle::update( int ddx ){
    /*for(int i=0; i<(sizeof(tires)/sizeof(*tires)); ++i){
        tires[i]->update(x + i, y);
    }*/
    rotation = SDL_atan2f( tires[1]->getH(ddx + dest.x) - tires[0]->getH(ddx + dest.x), 80 );
    
    y = tires[0]->getH(ddx + dest.x + 50);
    for(int i=0; i<(sizeof(tires)/sizeof(*tires)); ++i){
        tires[i]->update(ddx+x);
    }
}