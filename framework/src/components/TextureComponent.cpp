#include "components/TextureComponent.hpp"

void TextureComponent::info(){
    std::cout << "texture path: " << texturePath << std::endl;
}

SDL_Texture* TextureComponent::getTexture(){
    return m_texture;
}

int TextureComponent::getWidth(){
    return width;
}

int TextureComponent::getHeight(){
    return height;
}