#include "SelectorCommand.h"
#include "Selector.h"

SelectorMoveCommand::SelectorMoveCommand(Selector* selector, IntVector2 pos)
    : selector_(selector), pos(pos) {}

void SelectorMoveCommand::Execute()
{
    if (selector_) selector_->Move(pos);
}

SelectUnitCommand::SelectUnitCommand(Selector* selector) : selector_(selector) {}

void SelectUnitCommand::Execute()
{
    if (selector_) selector_->SelectUnit();
}

UnitMoveCommand::UnitMoveCommand(Unit* unit, IntVector2 pos) : unit_(unit), pos_(pos) {}

void UnitMoveCommand::Execute()
{
    if (unit_) unit_->Move(pos_);
}

UnitMoveEndCommand::UnitMoveEndCommand(Unit* unit, Selector* selector) : unit_(unit), selector_(selector) {}

void UnitMoveEndCommand::Execute()
{
    if (unit_) unit_->MoveEnd(selector_);
}
