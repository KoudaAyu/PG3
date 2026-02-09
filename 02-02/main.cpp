#include<Windows.h>
#include<iostream>
#include <stdio.h>
int Recursive_rental_system(int hours)
{
	if (hours == 1)
	{
		return 100;
	}
	if (hours < 1)
	{
		return 0;

	}
	else
	{
		//一時間前の時給
		int Hourly_wage_one_hour_ago = Recursive_rental_system(hours - 1);
		
		//今回の時給
		int Current_hourly_wage = Hourly_wage_one_hour_ago * 2 - 50;
		return Current_hourly_wage;
	}
}

//一般的な賃貸体系と再帰的な賃貸体系の比較
void Comparison(int hours, int general_hourly_wage)
{
    int total_general_salary = 0;   // 一般的な時給体系の総賃金
    int total_recursive_salary = 0; // 再帰的な時給体系の総賃金

   printf("| 時間 |   一般   | 再帰時給 |   再帰   |\n");
    printf("|------|--------------|----------|--------------|\n");

    // 1時間目から総労働時間までループ
    for (int h = 1; h <= hours; h++)
    {
        // 再帰的な時給を計算
        int current_recursive_wage = Recursive_rental_system(h);

        // 累計額の更新
        total_general_salary += general_hourly_wage; // 引数で受け取った時給を加算
        total_recursive_salary += current_recursive_wage;

        // 途中経過の出力
        printf("| %4d | %12d | %8d | %12d |\n",
            h, total_general_salary, current_recursive_wage, total_recursive_salary);
    }

    // 最終比較結果の出力
    printf("\n--- 最終結果 ---\n");
    printf("一般時給体系での総賃金: %d円\n", total_general_salary);
    printf("再帰時給体系での総賃金: %d円\n", total_recursive_salary);

    // どちらが得か判定
    if (total_recursive_salary > total_general_salary)
    {
        printf("結論: 再帰時給体系の方が %d円 得です。\n", total_recursive_salary - total_general_salary);
    }
    else if (total_recursive_salary < total_general_salary)
    {
        printf("結論: 一般時給体系の方が %d円 得です。\n", total_general_salary - total_recursive_salary);
    }
    else
    {
        printf("結論: 両者の総賃金は同額です。\n");
    }
}



int main()
{
    SetConsoleOutputCP(65001);

    // 一般的な時給をmain関数内でローカル変数として定義
    int General_hourly_wage = 1226;

    // 比較したい時間を設定
    int hours_to_work = 30;

    // Comparison関数に両方の値を渡す
    Comparison(hours_to_work, General_hourly_wage);

    return 0;
}