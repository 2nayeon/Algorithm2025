#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	struct node* left;
	char* word;
	int count;
	struct node* right;
} NODETYPE;

int insert_node(NODETYPE* root, char* str);
NODETYPE* search(NODETYPE* root, char* key);
void inorder(NODETYPE* root);

main()
{
	NODETYPE* tree = NULL;
	NODETYPE* ptr;
	char wbuf[30];
	int count = 0;

	printf("  검색 트리에 저장할 단어를 입력하세요.\n  입력의 끝에는 quit를 입력하세요.\n");

	while (1) {
		if (fgets(wbuf, sizeof(wbuf), stdin) == NULL) {
			break; // 입력 오류 시 종료
		}

		// strcspn 함수는 문자열에서 \n 문자를 찾아 그 위치(인덱스)를 반환합니다.
		// 그 위치의 문자를 널 문자(\0)로 바꾸어 문자열을 종료시킵니다.
		wbuf[strcspn(wbuf, "\n")] = '\0';

		if (strcmp(wbuf, "quit") == 0) {
			break; // "quit"가 입력되면 루프 탈출
		}

		if (!tree) {  // 트리가 비었을때
			tree = (NODETYPE*)malloc(sizeof(NODETYPE));
			tree->word = (char*)malloc(strlen(wbuf) + 1);
			strcpy(tree->word, wbuf);
			tree->left = tree->right = NULL;
			tree->count = 1;
		}
		else
			insert_node(tree, wbuf);
	}

	printf("\n\nEnter a key to search : ");
	fgets(wbuf, sizeof(wbuf), stdin);
	wbuf[strcspn(wbuf, "\n")] = '\0';
	ptr = search(tree, wbuf);
	if (ptr)
		printf("%s is in this tree.\n\n", ptr->word);
	else
		printf("%s is not exist.\n\n", wbuf);

	printf("------- 트리안의 단어들 (사전식 순서) --------\n\n");
	inorder(tree);
}

NODETYPE* search(NODETYPE* root, char* key) {
	NODETYPE* tptr = root;
	int cmp;
	while (tptr) {
		cmp = strcmp(key, tptr->word);
		if (cmp < 0)
			tptr = tptr->left;
		else if (cmp > 0)
			tptr = tptr->right;
		else        // found
			return tptr;
	}
	return NULL;   // not found
}

int insert_node(NODETYPE* root, char* word) {
	NODETYPE* tptr = root, * before = NULL;
	int cmp;
	while (tptr) {
		cmp = strcmp(word, tptr->word);
		if (cmp < 0) {
			before = tptr;
			tptr = tptr->left;
		}
		else if (cmp > 0) {
			before = tptr;
			tptr = tptr->right;
		}
		else {    // found
			(tptr->count)++;
			return 0;
		}
	}
	tptr = (NODETYPE*)malloc(sizeof(NODETYPE));
	tptr->word = (char*)malloc(strlen(word) + 1);
	strcpy(tptr->word, word);
	tptr->left = tptr->right = NULL;
	tptr->count = 1;
	if (cmp < 0) before->left = tptr;
	else  before->right = tptr;
	return 1;
}

void inorder(NODETYPE* ptr) {
	if (ptr) {
		inorder(ptr->left);
		printf("%s %d\n", ptr->word, ptr->count);
		inorder(ptr->right);
	}
}

