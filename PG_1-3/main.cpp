#include <stdio.h>
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

int main(void)
{

	int dice;//�T�C�R���̏o��
	int predict;//�\�z

	srand(time(NULL));
	dice = rand() % 6 + 1;


	printf("��(�)��'1' ��(����)��'0' �Ɠ��͂���Enter�������Ă�������\n");

	//�\�z�����
	scanf_s("%d", &predict);


	PFunc p;
	p = DispResult;
	setTimeout(p, 3);

	//�T�C�R���̏o�ڂ�\��
	printf("�T�C�R���̏o�ڂ�%d\n", dice);

	//������\��
	if (dice % 2 == 0)
	{
		printf("������ '��(����)'�ł�");
	}
	else
	{
		printf("������ '��(�)'�ł�");
	}

	if (dice % 2 == 0 && predict == 0 || dice % 2 == 1 && predict == 1)
	{
		printf("����");
	}
	else
	{
		printf("�s����");
	}

	return 0;
}