#include <Novice.h>
#include "SceneManager.h"

const char kWindowTitle[] = "LE2B_07_コウダ_アユ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

    SceneManager sceneManager;
    sceneManager.Initialize();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

        bool consumedSpace = false;
        if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
            switch (sceneManager.GetCurrentType()) {
            case SceneType::Title:
                sceneManager.Change(SceneType::Game);
                consumedSpace = true;
                break;
            case SceneType::Game:
                sceneManager.Change(SceneType::Clear);
                consumedSpace = true;
                break;
            case SceneType::Clear:
                sceneManager.Change(SceneType::Title);
                consumedSpace = true;
                break;
            }
        }

        // Pass modified keys to the new scene update so the newly loaded scene won't see the same SPACE press
        if (consumedSpace) {
            char keysForScene[256];
            memcpy(keysForScene, keys, 256);
            keysForScene[DIK_SPACE] = 0;
            sceneManager.Update(keysForScene, preKeys);
        }
        else {
            sceneManager.Update(keys, preKeys);
        }

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

        sceneManager.Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
