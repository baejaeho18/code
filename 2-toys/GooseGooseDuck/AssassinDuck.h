#pragma once
#include "Duck.h"

class AssassinDuck :
    public Duck
{
protected:
private:
    int max_assassin_limit;
    int count_assassin;
public:
    AssassinDuck(const std::string& name_);
    ~AssassinDuck();
    void Skill(BirdList*) override;
};