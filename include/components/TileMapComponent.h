#ifndef INC_2DGAMETEST_TILEMAPCOMPONENT_H
#define INC_2DGAMETEST_TILEMAPCOMPONENT_H

#include "Component.hpp"

class TileMapComponent : public Component {
private:
    std::vector<std::vector<int>> tileMap;
    std::vector<SDL_Texture*> textures;

public:
    int m_width, m_height;

    TileMapComponent(int height, int width);

    void setWidth(int width);
    void setHeight(int height);

    void loadTexture(std::string path);
    void deleteTexture(int handle);

    bool loadMap(std::vector<std::vector<int>> map);
    void createRandomMap();

    void render() override;
    void update() override;
    void handleEvents(SDL_Event) override;
};

#endif //INC_2DGAMETEST_TILEMAPCOMPONENT_H
