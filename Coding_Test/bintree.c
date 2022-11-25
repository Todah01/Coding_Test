#if 1
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct NODE {
	char szData[64];

	struct NODE* left;
	struct NODE* right;
} NODE;


NODE* g_proot;
int g_nsize;


void ReleaseTree(NODE* pParent)
{
	if (pParent == NULL)
		return;

	ReleaseTree(pParent->left);
	ReleaseTree(pParent->right);

	printf("free() : %p, %s\n", pParent, pParent->szData);
	free(pParent);
	g_proot = NULL;
	g_nsize = 0;
}

void PrintTree(NODE* pParent)
{
	if (pParent == NULL)
		return;

	PrintTree(pParent->left);

	printf("[%p] %p | %s [%p]\n", 
		pParent->left,
		pParent, pParent->szData,
		pParent->right);

	PrintTree(pParent->right);

	return;
}

int InsertNode(const char* pszData)
{
	NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
	memset(pNewNode, 0, sizeof(NODE));
	strcpy_s(pNewNode->szData, sizeof(pNewNode->szData), pszData);

	if (g_proot == NULL)
	{
		g_proot = pNewNode;
		return 1;
	}

	NODE* pTmp = g_proot;
	while (pTmp != NULL)
	{
		// compare pszData to szData from pTmp
		if (strcmp(pTmp->szData, pNewNode->szData) > 0)
		{
			// go to left
			if (pTmp->left == NULL)
			{
				pTmp->left = pNewNode;
				break;
			}
			else
			{
				pTmp = pTmp->left;
				continue;
			}
		}
		else
		{
			// go to right
			if (pTmp->right == NULL)
			{
				pTmp->right = pNewNode;
				break;
			}
			else
			{
				pTmp = pTmp->right;
				continue;
			}
		}
	}

	return 1;
}

NODE* FindNode(NODE* pParent, const char* pszData)
{
	if (pParent == NULL)
	{
		return NULL;
	}

	//printf("%s is current node.\n", pParent->szData);
	//printf("Comparing %s with %s...", pParent->szData, pszData);
	//printf("Value is %d.\n", strcmp(pParent->szData, pszData));

	if (strcmp(pParent->szData, pszData) == 0)
	{
		// printf("Find %s\n", pszData);
		return pParent;
	}	
	else if (strcmp(pParent->szData, pszData) > 0)
	{
		// puts("Move to left\n");
		return FindNode(pParent->left, pszData);
	}
	else if (strcmp(pParent->szData, pszData) < 0)
	{
		// puts("Move to right\n");
		return FindNode(pParent->right, pszData);
	}

	printf("Can't find %s\n", pszData);

	return NULL;
}

NODE* GetNodeHasMinValue(NODE* pParent)
{
	NODE* pTmp = pParent;
	while (pTmp->left != NULL)
		pTmp = pTmp->left;

	return pTmp;
}

int DeleteNode(NODE* pParent, const char* pszData)
{
	

	return 1;
}

int GetSize(void)
{
	return g_nsize;
}

int GetLength(void)
{
	return GetSize();
}

int IsEmpty()
{

	return GetSize();
}

int main(void)
{
	InsertNode("5번");
	InsertNode("4번");
	InsertNode("7번");
	InsertNode("6번");
	InsertNode("8번");

	printf("FindNode() : [%p], %s\n",
		FindNode(g_proot, "7번"),
		FindNode(g_proot, "7번")->szData);

	PrintTree(g_proot);
	ReleaseTree(g_proot);
	return 0;
}
#endif