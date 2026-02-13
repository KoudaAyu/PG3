#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// 出目とユーザーの入力を比較し、結果を表示する
void ShowResult(int roll, int userGuess)
{
    int rollParity = roll % 2;

    printf("出目は %d でした。\n", roll);

    if (rollParity == userGuess)
    {
        printf("「正解" "」\n");
    }
    else
    {
        printf("「不正解" "」\n");
    }
}

void DelayReveal(void (*fn)(int, int), int roll, int userGuess, unsigned int delayMs)
{
    Sleep(delayMs);

    (*fn)(roll, userGuess);
}

int main()
{
    int userGuess;
    int roll;

    srand((unsigned)time(NULL));

    printf("サイコロの出目（1～6）を予想してください。\n");
    printf("予想: 奇数(1) または 偶数(0) を入力してください > ");

    if (scanf_s("%d", &userGuess) != 1)
    {
        printf("入力エラーが発生しました。\n");
        return 1;
    }

    if (userGuess != 0 && userGuess != 1)
    {
        printf("無効な入力です。1（奇数）または 0（偶数）を入力してください。\n");
        return 1;
    }

    roll = (rand() % 6) + 1;

    printf("\n結果発表まで3秒待機します...\n");

    DelayReveal(ShowResult, roll, userGuess, 3000);

    return 0;
}