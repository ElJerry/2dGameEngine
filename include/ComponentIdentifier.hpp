#pragma once

class ComponentIdentifier {
private:
    static int getNewID(){
        static int id = 0;
        return id++;
    }
public:
    template <typename T>
    static int getComponentID(){
        static int compId = getNewID();
        return compId;
    }
};