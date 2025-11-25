#pragma once
#include <iostream>

// 敵の状態遷移（接近 -> 射撃 -> 離脱）をメンバ関数ポインタで実装
class Enemy
{
public:
    using StateFunc = void (Enemy::*)();

    // コンストラクタ: 初期状態は「接近」
    Enemy()
        : state_(&Enemy::Approach), distance_(12), shotsRemaining_(0)
    {
        std::cout << "敵を作成しました。初期状態: 接近\n";
    }

    // Update はまだ行動が残っている間 true を返す
    bool Update()
    {
        if (state_)
        {
            // 現在の状態関数を呼び出す
            (this->*state_)();
            return true;
        }
        else
        {
            std::cout << "全ての動作が完了しました。\n";
            return false;
        }
    }

private:
    StateFunc state_;      // 現在の状態を指すメンバ関数ポインタ
    int distance_;         // プレイヤーとの簡易距離
    int shotsRemaining_;   // 射撃状態での残り射撃回数

    // 状態を変更するときに呼ぶヘルパー（状態名を表示)
    void SetState(StateFunc s, const char* name)
    {
        state_ = s;
        std::cout << "状態遷移: " << name << "\n";
    }

    // 接近: 距離を縮め、十分に近づいたら射撃状態へ
    void Approach()
    {
        std::cout << "接近中... 距離 = " << distance_ << "\n";
        distance_ -= 3; // 接近する
        if (distance_ <= 3)
        {
            shotsRemaining_ = 3; // 射撃を3回行う
            SetState(&Enemy::Shoot, "射撃");
        }
    }

    // 射撃: 残弾がある間射撃を行い、無くなったら離脱へ
    void Shoot()
    {
        if (shotsRemaining_ > 0)
        {
            std::cout << "射撃！ 残り = " << shotsRemaining_ << "\n";
            --shotsRemaining_;
        }
        if (shotsRemaining_ <= 0)
        {
            SetState(&Enemy::Retreat, "離脱");
        }
    }

    // 離脱: 距離を離し、安全距離に達したら終了
    void Retreat()
    {
        std::cout << "離脱中... 距離 = " << distance_ << "\n";
        distance_ += 4; // 離脱する
        if (distance_ >= 20)
        {
            std::cout << "安全距離まで離脱しました。\n";
            state_ = nullptr; // 全動作終了
        }
    }
};