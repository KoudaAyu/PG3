#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <functional>

void DelayReveal(std::function<void(int, int)> fn, int roll, int userGuess, unsigned int delayMs)
{
    Sleep(delayMs);

    fn(roll, userGuess);
}


int main()
{
    int userGuess;
    int roll;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "サイコロの出目（1～6）を予想してください。\n";
    std::cout << "予想: 奇数(1) または 偶数(0) を入力してください > ";

    if (!(std::cin >> userGuess))
    {
        std::cerr << "入力エラーが発生しました。\n";
        return 1;
    }

    if (userGuess != 0 && userGuess != 1)
    {
        std::cerr << "無効な入力です。1（奇数）または 0（偶数）を入力してください。\n";
        return 1;
    }

    roll = (std::rand() % 6) + 1;

    std::cout << "\n結果発表まで3秒待機します...\n";

    auto showResultLambda = [](int r, int g)
        {
            int rollParity = r % 2;

            std::cout << "出目は " << r << " でした。\n";

            if (rollParity == g)
            {
                std::cout << "「正解」\n";
            }
            else
            {
                std::cout << "「不正解」\n";
            }
        };

    DelayReveal(showResultLambda, roll, userGuess, 3000);

    return 0;
}