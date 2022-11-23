#if 0
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "mylist.h"

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

void PrintList(LIST_INFO* pListData)
{
	int i = 0;
	printf("PrintList() : g_nsize : %d, g_phead [%p], g_ptail [%p]\n",
		pListData->nsize, pListData->phead, pListData->ptail);
	NODE* pTmp = pListData->phead;
	while (pTmp != NULL)
	{
		if (pTmp == pListData->phead || pTmp == pListData->ptail)
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

int main(void)
{
	LIST_INFO userList01 = { 0 };
	InitList(&userList01);

	USERDATA* pNewData = CreateUserData("WB", "010-1234-5678");
	InsertAtTail(&userList01, pNewData);
	pNewData = CreateUserData("KZ", "010-7777-7777");
	InsertAtHead(&userList01, pNewData);
	pNewData = CreateUserData("HW", "010-2222-2222");
	InsertAtTail(&userList01, pNewData);

	DeleteNode(&userList01, "HW");

	LIST_INFO userList02 = { 0 };
	InitList(&userList02);

	pNewData = CreateUserData("TR", "010-3333-3333");
	InsertAtHead(&userList02, pNewData);
	pNewData = CreateUserData("GT", "010-0000-1111");
	InsertAtTail(&userList02, pNewData);

	PrintList(&userList01);
	PrintList(&userList02);

	ReleaseList(&userList01);
	ReleaseList(&userList02);

	return 0;
}
#endif