#pragma once
#include <memory>
#include "Scene.h"

enum class SceneType {
    Title,
    Game,
    Clear
};

class SceneManager {
public:
    SceneManager();
    ~SceneManager();

    void Change(SceneType next);

    void Initialize();
    void Update(const char* keys, const char* preKeys);
    void Draw();

    SceneType GetCurrentType() const { return currentType_; }

private:
    std::unique_ptr<Scene> current_;
    SceneType currentType_;

    std::unique_ptr<Scene> CreateScene(SceneType type);
};
