#pragma once
#include "Bird.h"

class DodoBird :
    public Bird
{
protected:
private:
public:
    DodoBird(const std::string& name);
    ~DodoBird();
    void Skill(BirdList*) override;
};