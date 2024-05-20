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
    void Skill(BirdList*) override;
};

