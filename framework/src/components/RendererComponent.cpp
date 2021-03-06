#include "components/RendererComponent.hpp"
#include <camera/Camera.h>

void RendererComponent::render(){
    // std::cout << "Rendering" << std::endl;
    updateRects();
    if(m_texture != nullptr && renderer != nullptr){
        SDL_RenderCopyEx(renderer, m_texture, &sourceRect, &destRect, 0, nullptr, m_flip);
    }
}

void RendererComponent::updateRects(){
    //make sure all required components are loaded and referenced
    // texture component
    if(!texture){
        texture = gameObject->getComponent<TextureComponent>();
        m_texture = texture->getTexture();
        //load size of texture into sourceRect
        SDL_QueryTexture(m_texture,nullptr,nullptr,
                            &sourceRect.w, &sourceRect.h);
    }

    // transform component
    if(!transform){
        transform = gameObject->getComponent<TransformComponent>();
    }

    //update destRec x and y with transform component
    destRect.x = transform->position.getX();
    destRect.y = transform->position.getY();
    destRect.w = sourceRect.w;
    destRect.h = sourceRect.h;

    // calculate against camera offset
    auto cameraOffset = Camera::getOffset();
    destRect.x -= cameraOffset.getX();
    destRect.y -= cameraOffset.getY(); 

}

SDL_Rect* RendererComponent::getSourceRect(){
    return &sourceRect;
}