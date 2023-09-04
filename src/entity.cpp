
#include "include.hpp"
#include "define.hpp"
#include "structs.hpp"

#include "perlin.hpp"

#include "entity.hpp"

Entity::Entity(int cx, int cy, SDL_Texture* tex){
    location = {cx, cy};
    texture = tex;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
}
void Entity::blit(){
    SDL_RenderCopy(app.renderer, texture, NULL, &dest); 
};

void Entity::update(int cx, int cy){
    dest.x = cx + location.x; dest.y = cy + location.y;
};

void Entity::set(int x, int y){
    dest.x = x; dest.y = y;
}

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
/*bool rectCoolideInternal(SDL_Rect rect1, SDL_Rect rect2){
    return (
        ((rect1.y < rect2.y+rect2.h) &&
        (rect1.y+rect1.h > rect2.y))
        &&
        ((rect1.x < rect2.x+rect2.w) &&
        (rect1.x+rect1.w > rect2.x))
    );
}*/

SDL_Point Wheel::update(int h){
    
}

