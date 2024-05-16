#pragma once
#include "Bird.h"

class Duck :
    public Bird
{
protected:
    static int slayer_limit;
    static int slayer_count;
private:

public:
    Duck();
    ~Duck();
    void Skill(BirdList*);
};