#ifndef INC_2DGAMETEST_MAP_H
#define INC_2DGAMETEST_MAP_H
#define HEIGHT 50
#define WIDTH 50
#include <GameObject.hpp>

class GameMap : public GameObject {

private:
    int map[HEIGHT][WIDTH];
    SDL_Renderer *renderer;

    SDL_Texture *grass;
    SDL_Texture *dirt;

public:
    GameMap(char *name);

    void render();
    void loadMap(int theMap[HEIGHT][WIDTH]);
    void drawMap();

};

#endif //INC_2DGAMETEST_MAP_H
