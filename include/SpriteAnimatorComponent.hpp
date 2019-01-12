#pragma once
#include <iostream>
#include <Component.hpp>
#include <TransformComponent.hpp>
#include <RendererComponent.hpp>
#include <TextureComponent.hpp>

class SpriteAnimatorComponent : public Component {
private:
    int rows, columns;
    int presentRow, presentColumn;
    int width, height, textureWidth, textureHeight;
    bool animateFlag = true;

    TransformComponent *transform = NULL;
    RendererComponent *renderer = NULL;
    TextureComponent *texture = NULL;

    SDL_Rect *sourceRect = NULL;

public:

    SpriteAnimatorComponent(int r, int c, int w, int h){
        rows = r;
        columns = c;
        width = w;
        height = h;

        presentRow = 0;
        // std::cout << "valores de creacion de animator\n";
        // std::cout << r << " " << c << " " << w << " " << h << "\n";
        // int pause;
        // std::cin >> pause;
    }
    
    void update() override;  

    void setRow(int row);
    void setColumn(int column);
    void animate(bool animate);

};