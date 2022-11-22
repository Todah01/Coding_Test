#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "mylist.h"

void InitList(LIST_INFO* pListData)
{
	pListData->phead = (NODE*)malloc(sizeof(NODE));
	pListData->ptail = (NODE*)malloc(sizeof(NODE));

	pListData->nsize = 0;

	memset(pListData->phead, 0, sizeof(NODE));
	memset(pListData->ptail, 0, sizeof(NODE));

	pListData->phead->next = pListData->ptail;
	pListData->ptail->prev = pListData->phead;
}

void ReleaseList(LIST_INFO* pListData)
{
	NODE* pTmp = pListData->phead;
	while (pTmp != NULL)
	{
		NODE* pDelete = pTmp;
		pTmp = pTmp->next;

		printf("free(%p)\n", pDelete);

		free(pDelete->pData);
		free(pDelete);
	}

	pListData->phead = NULL;
	pListData->ptail = NULL;
	pListData->nsize = 0;

	puts("ReleaseList()");
}

// pParam : 호출자가 메모리를 동적 할당 + 값설정까지 해서 전달
int InsertAtHead(LIST_INFO* pListData, void* pParam)
{
	NODE* pNewNode = malloc(sizeof(NODE));
	memset(pNewNode, 0, sizeof(NODE));

	// 관리 대상 자료에 관한 초기화
	pNewNode->pData = pParam;

	// 연결 리스트에 관한 초기화
	pNewNode->next = pListData->phead->next;
	pNewNode->prev = pListData->phead;

	pListData->phead->next = pNewNode;
	pNewNode->next->prev = pNewNode;

	pListData->nsize++;
	return pListData->nsize;
}

int InsertAtTail(LIST_INFO* pListData, void* pParam)
{
	InsertBefore(pListData, pListData->ptail, pParam);

	return pListData->nsize;
}

NODE* GetAtIdx(LIST_INFO* pListData, int idx)
{
	if (idx > pListData->nsize - 1 || idx < 0)
	{
		printf("List index out of range!");
	}
	else
	{
		NODE* pTmp = pListData->phead->next;
		int cur_idx = 0;
		while (pTmp != pListData->ptail)
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

int InsertAtIdx(LIST_INFO* pListData, int idx, void* pParam)
{
	NODE* pIdxNode = GetAtIdx(pListData, idx);

	if (pIdxNode == NULL)
	{
		printf("List index out of range!");
		return 0;
	}

	InsertBefore(pListData, pIdxNode, pParam);

	return idx;
}

void InsertBefore(LIST_INFO* pListData, NODE* pDstnode, void* pParam)
{
	NODE* pNewNode = malloc(sizeof(NODE));
	memset(pNewNode, 0, sizeof(NODE));

	pNewNode->pData = pParam;

	pNewNode->next = pDstnode;
	pNewNode->prev = pDstnode->prev;

	pDstnode->prev = pNewNode;
	pNewNode->prev->next = pNewNode;

	pListData->nsize++;
}

NODE* FindNode(LIST_INFO* pListData, const char* pszKey)
{
	NODE* pTmp = pListData->phead->next;
	const char* (*pfGetKey)(void*) = NULL;
	while (pTmp != pListData->ptail)
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

int DeleteNode(LIST_INFO* pListData, const char* pszKey)
{
	NODE* pNode = FindNode(pListData, pszKey);

	if (pNode == NULL)
		return puts("Can't find key in list");

	pNode->prev->next = pNode->next;
	pNode->next->prev = pNode->prev;

	printf("DeleteNode() : [%p]\n", pNode);
	free(pNode->pData);
	free(pNode);

	pListData->nsize--;

	return 0;
}

int GetSize(LIST_INFO* pListData)
{
	return pListData->nsize;
}

int GetLength(LIST_INFO* pListData)
{
	return GetSize(pListData);
}

int IsEmpty(LIST_INFO* pListData)
{
	return GetSize(pListData);
}