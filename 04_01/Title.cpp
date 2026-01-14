#include <Novice.h>
#include "Title.h"

Title::Title() {}
Title::~Title() {}

void Title::Initialize() {}

void Title::Update(const char* keys, const char* preKeys) {
   
    if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
       
    }
}

void Title::Draw() {
    Novice::ScreenPrintf(10, 10, "Title Scene: Press SPACE to start");
}

