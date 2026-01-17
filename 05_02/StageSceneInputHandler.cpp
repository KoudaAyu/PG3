#include "StageSceneInputHandler.h"
#include <Novice.h>
#include "SelectorCommand.h"

StageSceneInputHandler::StageSceneInputHandler() {}

void StageSceneInputHandler::UpdateKeyState()
{
    memcpy(preKeys_, keys_, sizeof(keys_));
    Novice::GetHitKeyStateAll(keys_);
}

IStageSceneCommand* StageSceneInputHandler::SelectorHandleInput(Selector* selector)
{
    (void)selector;
   
    if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE]) {
        return new SelectUnitCommand(selector);
    }
    return nullptr;
}

IStageSceneCommand* StageSceneInputHandler::UnitHandleInput(Unit* unit)
{
    (void)unit;
    
    return nullptr;
}
