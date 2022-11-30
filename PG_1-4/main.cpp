#include <stdio.h>
#include <functional>
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

int main(int argc, const char* argv[])
{

	std::function<int()>dice = []()
	{
		srand(time(NULL));

		int a = rand() % 6 + 1;

		return a;

	};



	auto Result = [](int a, int b)
	{
		if (a % 2 == 0)
		{
			if (b % 2 == 0)
			{
				return printf("正解\n");
			}
			else
			{
				return printf("不正解\n");
			}
		}
		else if (b % 2 == 1)
		{
			if (a % 2 == 1)
			{
				return printf("正解\n");
			}
			else
			{
				return printf("不正解\n");
			}
		}
	};

	int predict;

	printf("半(奇数)は'1' 丁(偶数)は'0' と入力してEnterを押してください\n");
	//予想を入力
	scanf_s("%d", &predict);



	PFunc p;
	p = DispResult;
	setTimeout(p, 3);

	int num = dice();

	//サイコロの出目を表示
	printf("サイコロの出目は%d\n", num);

	Result(predict, num);

	return 0;
}