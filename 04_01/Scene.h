#pragma once

class Scene {
public:
    virtual ~Scene() = default;
    virtual void Initialize() = 0;
    virtual void Update(const char* keys, const char* preKeys) = 0;
    virtual void Draw() = 0;
};
