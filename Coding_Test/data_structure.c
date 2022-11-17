#if 0
#include <stdio.h>

int _cdecl test(int a)
{
	if (a <= 0) return;

	printf("test(%d)\n", a);
	return test(a - 1);
}

int main(void)
{
	test(5);
	return 0;
}
#endif

#if 0
#include <stdio.h>

typedef struct NODE {
	// 관리될 데이터
	int nData;

	// 데이터 관리를 위한 포인터
	struct NODE* next;
} NODE;

int main()
{
	NODE list[5] = { 0 };

	// 값 초기화
	list[0].nData = 100;
	list[1].nData = 200;
	list[2].nData = 300;
	list[3].nData = 400;
	list[4].nData = 500;

	// 연결 리스트 구조화
	list[0].next = &list[4];
	list[1].next = &list[2];
	list[2].next = &list[3];
	list[3].next = NULL;
	list[4].next = &list[1];

	for (int i = 0; i < 5; ++i)
	{
		printf("list[%d] : %d\n", i, list[i].nData);
	}

	NODE* pTmp = &list[0];

	while (pTmp != NULL)
	{
		printf("%p : %d\n", pTmp, pTmp->nData);
		pTmp = pTmp->next;
	}

	return 0;
}
#endif

#if 1
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct NODE {
	char szData[64];
	struct NODE* next;
} NODE;

NODE* g_phead = NULL;

void PrintList(void)
{
	NODE* phead = g_phead;
	while (phead != NULL)
	{
		printf("[%p] %s, next[%p]\n", phead, phead->szData, phead->next);
		phead = phead->next;
	}

	putchar('\n');
}

int InsertNewNode(char* pszData)
{
	NODE* pNode = (NODE*)malloc(sizeof(NODE));
	memset(pNode, 0, sizeof(NODE));
	strcpy_s(pNode->szData, sizeof(pNode->szData), pszData);
	
	if (g_phead == NULL)
		g_phead = pNode;
	else {
		pNode->next = g_phead;
		g_phead = pNode;
	}

	return 1;
}

int main()
{
	InsertNewNode("TEST01");
	PrintList();

	InsertNewNode("TEST02");
	PrintList();

	InsertNewNode("TEST03");
	PrintList();

	return 0;
}
#endif