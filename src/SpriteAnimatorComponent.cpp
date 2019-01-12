#include <SpriteAnimatorComponent.hpp>

void SpriteAnimatorComponent::update(){
    
    if(!sourceRect){
        renderer = gameObject->getComponent<RendererComponent>();
        sourceRect = renderer->getSourceRect();

        if(!sourceRect) return;

    }

    if(!texture){
        texture = gameObject->getComponent<TextureComponent>();
        if(!texture) return;

        textureHeight = texture->getHeight();
        textureWidth = texture->getWidth();
    }

    if(sourceRect){
        int x;
        x = (presentColumn * width) % textureWidth;

        if(animateFlag){
            //update x to next frame every 500ms
            int ticks = SDL_GetTicks();
            x = (width * ((ticks / 100)% columns));
        }

        sourceRect->x = x;
        sourceRect->y = presentRow * height;
        sourceRect->w = width;
        sourceRect->h = height;
    }
}

void SpriteAnimatorComponent::setRow(int row){
    presentRow = row;
}