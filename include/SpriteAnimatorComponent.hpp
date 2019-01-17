#pragma once
#include <iostream>
#include <vector>
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
    bool bounce = false;
    vector<int> columnsInRow;

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
        
        columnsInRow.assign(r,c);
    }
    
    void update() override;  

    void setRow(int row);
    void setColumn(int column);
    void animate(bool animate);

    void setColumnsInRow(int row, int column);

    void setBounce(bool bounce);

};