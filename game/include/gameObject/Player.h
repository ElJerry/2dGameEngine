#ifndef INC_2DGAMETEST_PLAYER_H
#define INC_2DGAMETEST_PLAYER_H

#include <GameObject.hpp>

class Player : public GameObject {

public:
    Player(char *name);
    ~Player();
};


#endif
