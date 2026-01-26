#include <stdlib.h>
#include <iostream>

#include<stdio.h>
#include<list>

using namespace std;

//駅名リストを表示する関数
void CoutStations(const list<const char*>& stations)
{
	for (const auto& name : stations)
	{
		cout << name << endl;
	}
}

//指定した駅名のイテレータ(本でいうしおり)を取得
list<const char*>::iterator findStation(list<const char*>& stations, const char* name)
{
	for (auto it = stations.begin(); it != stations.end(); ++it)
	{
		if (strcmp(*it, name) == 0)
		{
			return it;
		}
	}
	return stations.end();
}

int main()
{
	list<const char*> stationList;
	const char* Station1970[] = {
		"Tokyo","Kanda","Akihabara","Okachimachi","Ueno",
		"Uguisudani","Nippori","Tabata","Komagome",
		"Sugamo","Otsuka","Ikebukuro","Mejiro","Takadanobaba",
		"Shin-Okubo","Shinjuku","Yoyogi","Harajuku","Shibuya",
		"Ebisu","Meguro","Gotanda","Osaki","Shinagawa",
		"Tamachi","Hamamatsucho","Shimbashi","Yurakucho"
	};
	for (const char* name : Station1970)
	{
		stationList.push_back(name);
	}
	cout << "--- Yamanote Line Stations (1970) ---" << endl;
	CoutStations(stationList);

	//西日暮里を追加
	list<const char*> stations2019 = stationList;
	auto it2019 = findStation(stations2019, "Nippori");
	if (it2019 != stations2019.end())
	{
		++it2019; // Nipporiの次
		stations2019.insert(it2019, "Nishi-Nippori");
	}
	cout << "--- Yamanote Line Stations (2019) ---" << endl;
	CoutStations(stations2019);

	//高輪ゲートウェイを追加
	list<const char*> stations2022 = stations2019;
	auto it2022 = findStation(stations2022, "Shinagawa");
	if (it2022 != stations2022.end())
	{
		++it2022; // Shinagawaの次
		stations2022.insert(it2022, "Takanawa Gateway");
	}

	cout << "--- Yamanote Line Stations (2022) ---" << endl;
	CoutStations(stations2022);
	
	return 0;
}