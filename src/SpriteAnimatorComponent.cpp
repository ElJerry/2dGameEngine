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
            int columns = columnsInRow[presentRow];
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
                //update x to next frame every 500ms
                x = (width * ((ticks / 100)% columns));
            }
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

void SpriteAnimatorComponent::setColumnsInRow(int rows, int columns){
    columnsInRow[rows] = columns;
}

/*  
    When bounce is set to 'true', the animation will go from
    frame 1 to frame n and then back from n to 1
    IE: 1,2,3,4,3,2,1
*/
void SpriteAnimatorComponent::setBounce(bool bounce){
    this->bounce = bounce;
}