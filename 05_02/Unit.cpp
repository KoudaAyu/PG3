#include "Unit.h"
#include "Selector.h"
#include <Novice.h>

void Unit::Initialize(int idref)
{
    id_ = idref;
    map_ = { 0, 0 };
    isSelected_ = false;
}

void Unit::Update()
{
   
}

void Unit::Draw()
{
   
    Novice::ScreenPrintf(300 + id_ * 80, 100, "Unit %d (%d,%d)", id_, map_.x, map_.y);
}

void Unit::Move(IntVector2 pos)
{
    map_ = pos;
}

void Unit::MoveEnd(Selector* selector)
{
    (void)selector;
   
}
