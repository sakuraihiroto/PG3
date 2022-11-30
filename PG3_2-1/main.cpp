#include <stdio.h>
#include <list>
#include <string.h>

using namespace std;

int main()
{
	list<const char*>stations =
	{
		"Shinagawa","Tamachi",
		"Hamamatsucho",
		"Shinbashi","Yurakucho",
		"Tokyo","Kanda","Akihabara",
		"Okachimachi","Ueno",
		"Uguisudani","Nippori",
		"Tabata"
	};


	//1970年
	printf("---1970---\n");
	for (auto itr = stations.begin(); itr != stations.end(); itr++)
	{
		printf("%s\n", *itr);
	}

	//1971年
	for (auto itr = stations.begin(); itr != stations.end(); itr++)
	{
		if (strcmp(*itr, "Tabata") == 0)
		{
			stations.insert(itr, "Nishi-Nippori");
			break;
		}
	}

	//2019年
	printf("---2019---\n");
	for (auto itr = stations.begin(); itr != stations.end(); itr++)
	{
		printf("%s\n", *itr);
	}

	//2020年
	for (auto itr = stations.begin(); itr != stations.end(); itr++)
	{
		if (strcmp(*itr, "Tamachi") == 0)
		{
			stations.insert(itr, "Takanawa-Geto-Way");
			break;
		}
	}

	//2022年
	printf("---2022---\n");
	for (auto itr = stations.begin(); itr != stations.end(); itr++)
	{
		printf("%s\n", *itr);
	}

	return 0;
}