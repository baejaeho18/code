#pragma once
#include "Bird.h"

class Duck :
    public Bird
{
protected:
    static int slayer_limit;
    static int slayer_count;
    bool killed;
private:

public:
    Duck(const std::string& name_);
    ~Duck();
    void Skill(BirdList*) override;
    static void SetSlayerLimit(int limit);
    static void ResetSlayerCount();
    void ResetKilled();
    bool DidKill();
};