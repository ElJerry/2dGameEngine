#include "RendererComponent.hpp"

void RendererComponent::render(){
    // std::cout << "Rendering" << std::endl;
    if(m_texture != NULL && renderer != NULL)
        SDL_RenderCopy(renderer,m_texture,&sourceRect,&destRect);
}


void RendererComponent::update(){
    //make sure all required components are loaded and referenced
    // texture component
    if(!texture){
        texture = gameObject->getComponent<TextureComponent>();
        m_texture = texture->getTexture();
        //load size of texture into sourceRect
        SDL_QueryTexture(m_texture,NULL,NULL,
                            &sourceRect.w,&sourceRect.h);
        
        sourceRect.x = sourceRect.y = 0;
    }

    // transform component
    if(transform==NULL){
        transform = gameObject->getComponent<TransformComponent>();
    }

    //update destRec x and y with transform component
    destRect.x = transform->position.getX();
    destRect.y = transform->position.getY();
    destRect.w = sourceRect.w;
    destRect.h = sourceRect.h;

}

SDL_Rect* RendererComponent::getSourceRect(){
    return &sourceRect;
}