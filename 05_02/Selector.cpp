#include "Selector.h"
#include <Novice.h>

Selector::Selector()
    : map_{0,0}, mapSize_(0), selectMode_(0), unit_(nullptr), selectedUnit_(nullptr)
{
}

void Selector::Initialize()
{
    map_ = {0,0};
    mapSize_ = 32;
    selectMode_ = 0; 
    selectedUnit_ = nullptr;
}

void Selector::Update()
{
    
}

void Selector::Draw()
{
    Novice::ScreenPrintf(200, 30, "Selector mode: %d", selectMode_);
}

void Selector::Move(IntVector2 pos)
{
    map_ = pos;
}

void Selector::SelectUnit()
{
   
    if (selectMode_ == 0) selectMode_ = 1;
    else selectMode_ = 0;
}
