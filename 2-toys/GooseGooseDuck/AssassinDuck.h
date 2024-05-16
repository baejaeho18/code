#pragma once
#include "Duck.h"

class AssassinDuck :
    public Duck
{
protected:
private:
public:
    AssassinDuck(const std::string& name_);
    ~AssassinDuck();
    void Skill(BirdList*) override;
};