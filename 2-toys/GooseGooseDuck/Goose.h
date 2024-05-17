#pragma once
#include "Bird.h"

class Goose :
    public Bird
{
protected:
private:
public:
    Goose(const std::string& name);
    ~Goose();
    virtual void Skill(BirdList*) override;
};

