#include "ComponentIdentifier.hpp"

int ComponentIdentifier::getNewID(){
    static int id = 0;
    return id++;
}