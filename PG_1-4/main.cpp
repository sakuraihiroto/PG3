#include <stdio.h>
#include <functional>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

typedef void (*PFunc)(int*);

void DispResult(int* s)
{
	printf("%d�b�҂��ĕ\�����ꂽ��\n", *s);
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
				return printf("����\n");
			}
			else
			{
				return printf("�s����\n");
			}
		}
		else if (b % 2 == 1)
		{
			if (a % 2 == 1)
			{
				return printf("����\n");
			}
			else
			{
				return printf("�s����\n");
			}
		}
	};

	int predict;

	printf("��(�)��'1' ��(����)��'0' �Ɠ��͂���Enter�������Ă�������\n");
	//�\�z�����
	scanf_s("%d", &predict);



	PFunc p;
	p = DispResult;
	setTimeout(p, 3);

	int num = dice();

	//�T�C�R���̏o�ڂ�\��
	printf("�T�C�R���̏o�ڂ�%d\n", num);

	Result(predict, num);

	return 0;
}