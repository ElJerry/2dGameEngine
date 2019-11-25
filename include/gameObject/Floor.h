#ifndef INC_2DGAMETEST_FLOOR_H
#define INC_2DGAMETEST_FLOOR_H

#include <GameObject.hpp>
#include <vector>

class Floor : public GameObject {
private:
    std::vector<GameObject*> objects;

public:
    Floor(char* name, int x, int y);
    ~Floor();

    void update();
};

#endif //INC_2DGAMETEST_FLOOR_H
