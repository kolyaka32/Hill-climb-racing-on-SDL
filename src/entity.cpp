
#include "include.hpp"
#include "define.hpp"
#include "structs.hpp"

#include "perlin.hpp"

#include "entity.hpp"

/*Entity::Entity(int cx, int cy, SDL_Texture* newTexture){
    location = {cx, cy};
    texture = newTexture;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
}*/

void Entity::blit(){
    SDL_RenderCopy(app.renderer, texture, NULL, &dest); 
};

void Entity::update(int cx, int cy){
    dest.x = cx + location.x; dest.y = cy + location.y;
};

// Function of getting collision of 2 objects extern
bool rectCoolideExternal(SDL_Rect rect1, SDL_Rect rect2){
    return (
        ((rect1.y < rect2.y+rect2.h) &&
        (rect1.y+rect1.h > rect2.y))
        &&
        ((rect1.x < rect2.x+rect2.w) &&
        (rect1.x+rect1.w > rect2.x))
    );
}

// Function of getting collision of 2 objects internal

Wheel::Wheel(const int ncx, const int ncy, SDL_Texture* newTexture){
    texture = newTexture; 
    cx = ncx; cy = ncy; texture = newTexture;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    dest.w/=2; dest.h/=2;

}

void Wheel::set(int x){
    dest.x = x+cx;
}

void Wheel::blit(int x, int y, float angle){
    dest.x = (x + cx);// * SDL_cosf(angle); 
    dest.y = SCREEN_HEIGHT - y - (cy); //* SDL_sinf(angle);
    SDL_RenderCopyEx(app.renderer, texture, NULL, &dest, rotate, NULL, SDL_FLIP_NONE);
}

void Wheel::blit(int x){
    SDL_RenderCopyEx(app.renderer, texture, NULL, &dest, rotate, NULL, SDL_FLIP_NONE);
}

int Wheel::update( int x, int y ){
    int dd=0;
    for(int dx = 0; dx<dest.w; ++dx){
        if(per(x+cx) < y+cy ){
            dd += per(x+cx) - y+cy;
        }
    }
    return dd;
}

void Wheel::update( int x ){
    dest.y = per(x+cx)-dest.h;
    rotate = x % 3;
}

int Wheel::getH( int x ){
    return per(x+cx) - dest.h/2;
}