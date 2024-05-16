#pragma once
#include "Goose.h"

class MorticianGoose :
    public Goose
{
protected:
private:
public:
    MorticianGoose(const std::string& name);
    ~MorticianGoose();
    void Skill(BirdList*) override;
};

