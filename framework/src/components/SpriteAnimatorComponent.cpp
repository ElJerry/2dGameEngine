#include <components/SpriteAnimatorComponent.hpp>

void SpriteAnimatorComponent::update(){

    // Check if gameobject has a sourceRect from the renderer component
    if(!sourceRect){
        renderer = gameObject->getComponent<RendererComponent>();
        sourceRect = renderer->getSourceRect();

        if(!sourceRect) return;
    }

    // check if gameobject has texture from the texture component
    if(!texture){
        texture = gameObject->getComponent<TextureComponent>();
        if(!texture) return;

        textureHeight = texture->getHeight();
        textureWidth = texture->getWidth();
    }

    if(sourceRect){
        int x;
        x = (currentColumn * width) % textureWidth;

        if(animateFlag){
            int columns = columnsInRow[currentRow];
            int ticks = SDL_GetTicks();

            // if bounce image should repeat petter 1..n..1
            if(bounce){
                int frame = (ticks/100) % columns;
                
                int modifier = (((ticks/100)/columns) %2);
                if(modifier){
                    x = (columns-1 ) - frame;
                }
                else{
                    x = frame;
                }
                x = width * x;
            }
            else{
                //update x to next frame every 100ms
                x = (width * ((ticks / 100)% columns));
            }
        }

        if(!sourceRect)
            return;

        sourceRect->x = x;
        sourceRect->y = currentRow * height;
        sourceRect->w = width;
        sourceRect->h = height;
    }
}

void SpriteAnimatorComponent::setRow(int row){
    currentRow = row;
}

void SpriteAnimatorComponent::setColumnsInRow(int rows, int columns){
    columnsInRow[rows] = columns;
}

void SpriteAnimatorComponent::animate(bool animate) {
    animateFlag = animate;
}

/*  
    When bounce is set to 'true', the animation will go from
    frame 1 to frame n and then back from n to 1
    IE: 1,2,3,4,3,2,1
*/
void SpriteAnimatorComponent::setBounce(bool bounce){
    this->bounce = bounce;
}