#pragma once
#include "Bird.h"

class Falcon :
    public Bird
{
protected:
private:
public:
    Falcon(const std::string& name_);
    ~Falcon();
    void Skill(BirdList*) override;
    void Vote(BirdList*) override;
};