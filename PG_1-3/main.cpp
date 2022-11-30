#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

typedef void (*PFunc)(int*);

void DispResult(int* s)
{
	printf("%d秒待って表示されたよ\n", *s);
}

void setTimeout(PFunc p, int second)
{
	Sleep(second * 1000);

	p(&second);
}

int main(void)
{

	int dice;//サイコロの出目
	int predict;//予想

	srand(time(NULL));
	dice = rand() % 6 + 1;


	printf("半(奇数)は'1' 丁(偶数)は'0' と入力してEnterを押してください\n");

	//予想を入力
	scanf_s("%d", &predict);


	PFunc p;
	p = DispResult;
	setTimeout(p, 3);

	//サイコロの出目を表示
	printf("サイコロの出目は%d\n", dice);

	//正解を表示
	if (dice % 2 == 0)
	{
		printf("正解は '丁(偶数)'です");
	}
	else
	{
		printf("正解は '半(奇数)'です");
	}

	if (dice % 2 == 0 && predict == 0 || dice % 2 == 1 && predict == 1)
	{
		printf("正解");
	}
	else
	{
		printf("不正解");
	}

	return 0;
}