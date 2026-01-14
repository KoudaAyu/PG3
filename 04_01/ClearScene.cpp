#include <Novice.h>
#include "ClearScene.h"

ClearScene::ClearScene() {}
ClearScene::~ClearScene() {}

void ClearScene::Initialize() {}

void ClearScene::Update(const char* keys, const char* preKeys) {
    (void)keys; (void)preKeys;
}

void ClearScene::Draw() {
    Novice::ScreenPrintf(10, 50, "Clear Scene: Press SPACE to go to title");
}
