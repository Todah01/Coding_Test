#if 1
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct NODE
{
	char szData[64];

	struct NODE* prev;
	struct NODE* next;
} NODE;

NODE* g_phead;
NODE* g_ptail;
int g_nsize;

void InsertBefore(NODE* psznode, const char* pszData);

void InitList(void)
{
	g_phead = (NODE*)malloc(sizeof(NODE));
	g_ptail = (NODE*)malloc(sizeof(NODE));
	
	g_nsize = 0;

	memset(g_phead, 0, sizeof(NODE));
	memset(g_ptail, 0, sizeof(NODE));

	strcpy_s(g_phead->szData, sizeof(g_phead->szData), "DUMMY HEAD");
	strcpy_s(g_ptail->szData, sizeof(g_ptail->szData), "DUMMY TAIL");

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
		free(pDelete);
	}

	g_phead = NULL;
	g_ptail = NULL;
	g_nsize = 0;

	puts("ReleaseList()");
}

void PrintList(void)
{
	printf("PrintList() : g_nsize : %d, g_phead [%p], g_ptail [%p]\n", g_nsize, g_phead, g_ptail);
	NODE* pTmp = g_phead;
	while (pTmp != NULL)
	{
		printf("[%p] %p, %s [%p]\n", pTmp->prev, pTmp, pTmp->szData, pTmp->next);
		pTmp = pTmp->next;
	}
}

int InsertAtHead(const char* pszData)
{
	NODE* pNewNode = malloc(sizeof(NODE));
	memset(pNewNode, 0, sizeof(NODE));

	strcpy_s(pNewNode->szData, sizeof(pNewNode->szData), pszData);

	pNewNode->next = g_phead->next;
	pNewNode->prev = g_phead;

	g_phead->next = pNewNode;
	pNewNode->next->prev = pNewNode;

	g_nsize++;
	return g_nsize;
}

int InsertAtTail(const char* pszData)
{
	InsertBefore(g_ptail, pszData);

	return g_nsize;
}

NODE* FindNode(const char* pszData)
{
	NODE* pTmp = g_phead->next;
	while (pTmp != g_ptail)
	{
		if (strcmp(pTmp->szData, pszData) == 0)
			return pTmp;

		pTmp = pTmp->next;
	}

	return NULL;
}

int DeleteNode(const char* pszData)
{
	NODE* pNode = FindNode(pszData);

	pNode->prev->next = pNode->next;
	pNode->next->prev = pNode->prev;

	printf("DeleteNode() : [%p]\n", pNode);
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

int InsertAtIdx(int idx, char* pszData)
{
	NODE* pIdxNode = GetAtIdx(idx);

	if (pIdxNode == NULL)
	{
		printf("List index out of range!");
		return 0;
	}

	InsertBefore(pIdxNode, pszData);

	return idx;
}

void InsertBefore(NODE* psznode, const char* pszData)
{
	NODE* pNewNode = malloc(sizeof(NODE));
	memset(pNewNode, 0, sizeof(NODE));

	strcpy_s(pNewNode->szData, sizeof(pNewNode->szData), pszData);

	pNewNode->next = psznode;
	pNewNode->prev = psznode->prev;

	psznode->prev = pNewNode;
	pNewNode->prev->next = pNewNode;

	g_nsize++;
}

int main()
{
	InitList();

	InsertAtTail("TEST01");
	InsertAtTail("TEST02");
	InsertAtTail("TEST03");

	InsertAtIdx(1, "Rabbit_Foot");
	InsertAtIdx(3, "Rabbit_Foot");

	DeleteNode("Rabbit_Foot");

	printf("GetAtIdx() : [%p], %s\n", GetAtIdx(2), GetAtIdx(2)->szData);

	PrintList();

	ReleaseList();

	return 0;
}
#endif