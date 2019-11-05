#pragma once
#include <iostream>
#include <vector>
#include <components/Component.hpp>
#include <components/TransformComponent.hpp>
#include <components/RendererComponent.hpp>
#include <components/TextureComponent.hpp>

class SpriteAnimatorComponent : public Component {
private:
    int rows, columns;
    int currentRow, currentColumn;
    int width, height, textureWidth, textureHeight;
    bool animateFlag = true;
    bool bounce = false;
    vector<int> columnsInRow;

    TransformComponent *transform = nullptr;
    RendererComponent *renderer = nullptr;
    TextureComponent *texture = nullptr;

    SDL_Rect *sourceRect = nullptr;

public:

    SpriteAnimatorComponent(int rows, int columns, int width, int height){
        this->rows = rows;
        this->columns = columns;
        this->width = width;
        this->height = height;

        currentColumn = currentRow = 0;
        
        columnsInRow.assign(rows, columns);
    }
    
    void update() override;  

    void setRow(int row);

    void setColumn(int column);
    void animate(bool animate);

    void setColumnsInRow(int row, int column);

    void setBounce(bool bounce);

};