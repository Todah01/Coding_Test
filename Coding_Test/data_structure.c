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

NODE g_head = { 0 };
NODE* g_ptail = 0;

void PrintList(void)
{
	NODE* phead = g_head.next;
	while (phead != NULL)
	{
		printf("[%p] %s, next[%p]\n", phead, phead->szData, phead->next);
		phead = phead->next;
	}

	putchar('\n');
}

int IsEmpty()
{
	if (g_head.next == NULL)
		return 1;

	return 0;
}

int InsertAtHead(char* pszData)
{
	NODE* pNode = (NODE*)malloc(sizeof(NODE));
	memset(pNode, 0, sizeof(NODE));
	strcpy_s(pNode->szData, sizeof(pNode->szData), pszData);
	
	if (IsEmpty())
	{
		g_head.next = pNode;
		g_ptail = pNode;
	}	
	else {
		pNode->next = g_head.next;
		g_head.next = pNode;
	}
}

int InsertAtTail(char* pszData)
{
	NODE* pNode = (NODE*)malloc(sizeof(NODE));
	memset(pNode, 0, sizeof(NODE));
	strcpy_s(pNode->szData, sizeof(pNode->szData), pszData);

	if (IsEmpty()) g_head.next = pNode;
	else g_ptail->next = pNode;

	g_ptail = pNode;
}

void ReleaseList(void)
{
	NODE* pTmp = g_head.next;
	while (pTmp != NULL)
	{
		NODE* pDelete = pTmp;
		pTmp = pTmp->next;

		printf("Delete : [%p] %s\n", pDelete, pDelete->szData);
		free(pDelete);
	}

	g_head.next = 0;
	g_ptail = 0;
}

NODE* FindData(char* pszData)
{
	NODE* pCur = g_head.next;
	NODE* pPrev = &g_head;
	while (pCur != NULL)
	{
		// 찾은 노드의 앞 노드 주소를 반환.
		// 더미 헤드가 존재하기 때문에 이렇게 해도 문제x.
		if (strcmp(pCur->szData, pszData) == 0)
			return pPrev;
		pCur = pCur->next;
		pPrev = pPrev->next;
	}

	return 0;
}

int DeleteData(char* pszData)
{
	NODE* pPrev = FindData(pszData);
	if (pPrev != 0)
	{
		NODE* pDelete = pPrev->next;
		pPrev->next = pDelete->next;

		printf("DeleteData() : %s\n", pDelete->szData);
		
		if (pDelete == g_ptail)
			g_ptail = 0;
		
		free(pDelete);

		return 1;
	}

	return 0;
}

void PushData(char* pszData)
{
	InsertAtHead(pszData);
}

int Enqueue(char* pszData)
{
	return InsertAtTail(pszData);
}

int Dequeue(NODE* pGetNode)
{
	return PopData(pGetNode);
}

int PopData(NODE* pPopNode)
{
	NODE* sp = g_head.next;
	if (IsEmpty())
		return 0;

	memcpy(pPopNode, sp, sizeof(NODE));

	g_head.next = sp->next;
	free(sp);

	return 1;
}

int main()
{
	/*puts("------InsertHead------");
	InsertAtHead("TEST01");
	InsertAtHead("TEST02");
	InsertAtHead("TEST03");
	PrintList();

	if (FindData("TEST01") == 1)
		printf("FindData():TEST01 found\n");
	if (FindData("TEST02") == 1)
		printf("FindData():TEST02 found\n");
	if (FindData("TEST03") == 1)
		printf("FindData():TEST03 found\n");

	DeleteData("TEST01");
	DeleteData("TEST02");
	DeleteData("TEST03");
	PrintList();

	puts("------InsertTail------");
	InsertAtTail("TEST01");
	InsertAtTail("TEST02");
	InsertAtTail("TEST03");
	PrintList();

	if (FindData("TEST01") == 1)
		printf("FindData():TEST01 found\n");
	if (FindData("TEST02") == 1)
		printf("FindData():TEST02 found\n");
	if (FindData("TEST03") == 1)
		printf("FindData():TEST03 found\n");

	DeleteData("TEST01");
	DeleteData("TEST02");
	DeleteData("TEST03");
	PrintList();

	ReleaseList();*/

	// Stack Test
	puts("------Stack------");
	PushData("TEST01");
	PushData("TEST02");
	PushData("TEST03");

	NODE node = { 0 };
	PopData(&node);
	printf("Pop : %s\n", node.szData);
	PopData(&node);
	printf("Pop : %s\n", node.szData);

	ReleaseList();

	// Queue Test
	puts("------Queue------");
	Enqueue("TEST01");
	Enqueue("TEST02");
	Enqueue("TEST03");

	PrintList();

	Dequeue(&node);
	printf("Dequeue : %s\n", node.szData);
	PrintList();

	Dequeue(&node);
	printf("Dequeue : %s\n", node.szData);
	PrintList();

	Enqueue("TEST01");
	Enqueue("TEST02");
	Enqueue("TEST03");

	ReleaseList();

	return 0;
}
#endif