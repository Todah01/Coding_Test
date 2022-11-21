#if 1
#include <stdio.h>
#include <string.h>
#include <malloc.h>


typedef struct NODE
{
	// 관리 대상 자료
	void* pData;

	// 자료구조
	struct NODE* prev;
	struct NODE* next;
} NODE;

NODE* g_phead;
NODE* g_ptail;
int g_nsize;


int InsertAtHead(void* pParam);
int InsertAtTail(void* pParam);
void InsertBefore(NODE* psznode, void* pParam);

typedef struct USERDATA
{
	// 멤버 함수 포인터
	const char* (*GetKey)(void*);

	char szName[64];
	char szPhone[64];
} USERDATA;

const char* GetKeyFromUserData(USERDATA* pUser)
{
	return pUser->szName;
}

USERDATA* CreateUserData(const char* pszName, const char* pszPhone)
{
	USERDATA* pNewData = (USERDATA*)malloc(sizeof(USERDATA));
	memset(pNewData, 0, sizeof(USERDATA));
	
	strcpy_s(pNewData->szName, sizeof(pNewData->szName), pszName);
	strcpy_s(pNewData->szPhone, sizeof(pNewData->szPhone), pszPhone);

	// C++ 내부구조 Ex) this 생성자
	// 구조체 멤버 함수 포인터 초기화
	pNewData->GetKey = GetKeyFromUserData;

	return pNewData;
}


void InitList(void)
{
	g_phead = (NODE*)malloc(sizeof(NODE));
	g_ptail = (NODE*)malloc(sizeof(NODE));
	
	g_nsize = 0;

	memset(g_phead, 0, sizeof(NODE));
	memset(g_ptail, 0, sizeof(NODE));

	g_phead->next = g_ptail;
	g_ptail->prev = g_phead;
}

void ReleaseList(void)
{
	NODE* pTmp = g_phead;
	while (pTmp != NULL)
	{
		NODE* pDelete = pTmp;
		pTmp = pTmp->next;

		printf("free(%p)\n", pDelete);

		free(pDelete->pData);
		free(pDelete);
	}

	g_phead = NULL;
	g_ptail = NULL;
	g_nsize = 0;

	puts("ReleaseList()");
}

void PrintList(void)
{
	int i = 0;
	printf("PrintList() : g_nsize : %d, g_phead [%p], g_ptail [%p]\n", g_nsize, g_phead, g_ptail);
	NODE* pTmp = g_phead;
	while (pTmp != NULL)
	{
		if (pTmp == g_phead || pTmp == g_ptail)
			puts("DUMMY DATA");
		else
		{
			USERDATA* pUser = pTmp->pData;
			printf("Index : %d | Name : %s\n", i,
				pUser->GetKey(pUser));
			++i;
		}
		pTmp = pTmp->next;
	}

	putchar('\n');
}

// pParam : 호출자가 메모리를 동적 할당 + 값설정까지 해서 전달
int InsertAtHead(void* pParam)
{
	NODE* pNewNode = malloc(sizeof(NODE));
	memset(pNewNode, 0, sizeof(NODE));

	// 관리 대상 자료에 관한 초기화
	pNewNode->pData = pParam;

	// 연결 리스트에 관한 초기화
	pNewNode->next = g_phead->next;
	pNewNode->prev = g_phead;

	g_phead->next = pNewNode;
	pNewNode->next->prev = pNewNode;

	g_nsize++;
	return g_nsize;
}

int InsertAtTail(void* pParam)
{
	InsertBefore(g_ptail, pParam);

	return g_nsize;
}

NODE* FindNode(const char* pszKey)
{
	NODE* pTmp = g_phead->next;
	const char* (*pfGetKey)(void*) = NULL;
	while (pTmp != g_ptail)
	{
		// C++ 내부구조 Ex) this 생성자
		// 관리 대상 데이터 구조체 첫 번째 멤버가 함수 포인터 임을 가정
		pfGetKey = pTmp->pData;
		if (strcmp(pfGetKey(pTmp->pData), pszKey) == 0)
			return pTmp;

		pTmp = pTmp->next;
	}

	return NULL;
}

int DeleteNode(const char* pszKey)
{
	NODE* pNode = FindNode(pszKey);

	pNode->prev->next = pNode->next;
	pNode->next->prev = pNode->prev;

	printf("DeleteNode() : [%p]\n", pNode);
	free(pNode->pData);
	free(pNode);

	g_nsize--;

	return 0;
}

int GetSize(void)
{
	return g_nsize;
}

int GetLength(void)
{
	return GetSize();
}

int IsEmpty(void)
{
	return GetSize();
}


NODE* GetAtIdx(int idx)
{
	if (idx > g_nsize - 1 || idx < 0)
	{
		printf("List index out of range!");
	}
	else
	{
		NODE* pTmp = g_phead->next;
		int cur_idx = 0;
		while (pTmp != g_ptail)
		{
			if (cur_idx == idx)
			{
				return pTmp;
			}
			else
			{
				pTmp = pTmp->next;
				cur_idx++;
			}
		}
	}

	return NULL;
}

int InsertAtIdx(int idx, void* pParam)
{
	NODE* pIdxNode = GetAtIdx(idx);

	if (pIdxNode == NULL)
	{
		printf("List index out of range!");
		return 0;
	}

	InsertBefore(pIdxNode, pParam);

	return idx;
}

void InsertBefore(NODE* psznode, void* pParam)
{
	NODE* pNewNode = malloc(sizeof(NODE));
	memset(pNewNode, 0, sizeof(NODE));

	pNewNode->pData = pParam;

	pNewNode->next = psznode;
	pNewNode->prev = psznode->prev;

	psznode->prev = pNewNode;
	pNewNode->prev->next = pNewNode;

	g_nsize++;
}

int main(void)
{
	InitList();

	USERDATA* pNewData = NULL;
	pNewData = CreateUserData("WB", "010-1234-5678");
	InsertAtTail(pNewData);
	pNewData = CreateUserData("KZ", "010-7777-7777");
	InsertAtTail(pNewData);

	// DeleteNode("WB");

	PrintList();
	ReleaseList();

	return 0;
}
#endif