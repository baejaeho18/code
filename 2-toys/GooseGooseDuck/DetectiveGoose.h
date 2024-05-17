#pragma once
#include "Goose.h"

class DetectiveGoose :
    public Goose
{
protected:
private:
public:
    DetectiveGoose(const std::string& name);
    ~DetectiveGoose();
    void Skill(BirdList*) override;
    void Vote(BirdList*) override;
};

