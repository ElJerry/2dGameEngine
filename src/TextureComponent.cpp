#include "TextureComponent.hpp"

void TextureComponent::info(){
    std::cout << "texture path: " << texturePath << std::endl;
}

SDL_Texture* TextureComponent::getTexture(){
    return m_texture;
}