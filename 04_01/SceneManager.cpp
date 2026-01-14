#include "SceneManager.h"
#include "Title.h"
#include "GameScene.h"
#include "ClearScene.h"

SceneManager::SceneManager() : currentType_(SceneType::Title) {
    current_ = CreateScene(currentType_);
}

SceneManager::~SceneManager() = default;

std::unique_ptr<Scene> SceneManager::CreateScene(SceneType type) {
    switch (type) {
    case SceneType::Title:
        return std::make_unique<Title>();
    case SceneType::Game:
        return std::make_unique<GameScene>();
    case SceneType::Clear:
        return std::make_unique<ClearScene>();
    }
    return nullptr;
}

void SceneManager::Change(SceneType next) {
    currentType_ = next;
    current_ = CreateScene(currentType_);
    if (current_) current_->Initialize();
}

void SceneManager::Initialize() {
    if (current_) current_->Initialize();
}

void SceneManager::Update(const char* keys, const char* preKeys) {
    if (current_) current_->Update(keys, preKeys);

   
    if (currentType_ == SceneType::Game) {
        GameScene* game = dynamic_cast<GameScene*>(current_.get());
        if (game && game->IsCleared()) {
            Change(SceneType::Clear);
        }
    }
}

void SceneManager::Draw() {
    if (current_) current_->Draw();
}
