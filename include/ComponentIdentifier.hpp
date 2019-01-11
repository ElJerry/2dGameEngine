#pragma once

class ComponentIdentifier {
private:
    static int getNewID();
    
public:
    template <typename T>
    static int getComponentID(){
        static int compId = getNewID();
        return compId;
    }
};