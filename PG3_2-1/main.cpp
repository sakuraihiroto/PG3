#include<stdio.h>
#include<stdlib.h>


using namespace std;


typedef struct cell
{
	int val;
	struct cell* next;
}CELL;

void create(CELL* head, int val);	//データを追加する関数のプロトタイプ宣言　
void index(CELL* head);	//一覧を表示する関数のプロトタイプ宣言

int main()
{
	int val;

	CELL head;
	head.next = nullptr;

	while (true)
	{
		printf("好きな数字を入力してください\n入力された値:");
		scanf_s(" %d", &val);

		//最後尾にセルを追加
		create(&head, val);

		printf("\n入力された値一覧: ");
		//リスト一覧の表示
		index(&head);

		printf("\n\n");
	}

	return 0;
}

void create(CELL* head, int val)
{
	CELL* beta;
	//新規作成するセル分のメモリを確保する
	beta = (CELL*)malloc(sizeof(CELL));

	beta->val = val;
	beta->next = nullptr;

	//最後(最新)のセルのアドレスの1つめの処理は引数から持ってきた
	//リストのうち最初にセルのアドレスが該当する
	while (head->next != nullptr) {
		head = head->next;

	}

	head->next = beta;

}

void index(CELL* head) {
	while (head->next != nullptr) {
		head = head->next;
		
		printf("[%d]", head->val);
		
	}
}