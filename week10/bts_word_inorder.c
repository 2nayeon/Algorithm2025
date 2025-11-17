#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	struct node* left;
	char* word;
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
	printf("  검색 트리에 저장할 단어를 입력하세요.\n                   입력의 끝에는 quit를 입력하세요.\n");
	while (1) {
		if (fgets(wbuf, sizeof(wbuf), stdin) == NULL) {
			break;
		}
		// strcspn함수는 문자열에서 \n 문자를 찾아 그 위치(인덱스)를 반환한다.
		// 그 위치의 문자를 널 문자(\0)로 바꾸어 문자열을 종료시킨다.
		wbuf[strcspn(wbuf, "\n")] = '\0';

		if (strcmp(wbuf, "quit") == 0)
			break;

		if (!tree) {  // 트리가 비었을때
			tree = (NODETYPE*)malloc(sizeof(NODETYPE));
			tree->word = (char*)malloc(strlen(wbuf) + 1);
			strcpy(tree->word, wbuf);
			tree->left = tree->right = NULL;    // fill in
		}
		else
			insert_node(tree, wbuf);
	}
	printf("\n\nEnter a key to search : ");
	// gets(wbuf);
	fgets(wbuf, sizeof(wbuf), stdin);

	ptr = search(tree, wbuf);    // fill in : call search()
	if (ptr)
		printf("%s is in this tree.\n\n", ptr->word);
	else
		printf("%s is not exist.\n\n", wbuf);

	printf("------ 트리안의 단어들 (사전식 순서) ----------------\n\n");
	inorder(tree);    // fill in : call inorder()
}

NODETYPE* search(NODETYPE* root, char* key) {
	NODETYPE* tptr = root;
	int cmp;
	while (tptr) {
		cmp = strcmp(key, tptr->word);
		if (cmp < 0)
			tptr = tptr->left;    // fill in 
		else if (cmp > 0)
			tptr = tptr->right;    // fill in
		else        // found
			return tptr;    // fill in 
	}
	return NULL;   // not found
}

int insert_node(NODETYPE* root, char* word) {
	NODETYPE* tptr = root, * before = NULL;
	int cmp;
	while (tptr) {
		cmp = strcmp(word, tptr->word);
		if (cmp < 0) {
			before = tptr;    // fill in 
			tptr = tptr->left;    // fill in 
		}
		else if (cmp > 0) {
			before = tptr;    // fill in 
			tptr = tptr->right;    // fill in 
		}
		else        // found
			return 0;
	}

	tptr = (NODETYPE*)malloc(sizeof(NODETYPE));
	tptr->word = (char*)malloc(strlen(word) + 1);
	strcpy(tptr->word, word);
	tptr->left = tptr->right = NULL;
	if (cmp < 0) before->left = tptr;    // fill in 
	else  before->right = tptr;    // fill in 
	return 1;
}

void inorder(NODETYPE* ptr) {
	if (ptr) {
		inorder(ptr->left);  // fill in 
		printf("%s\n", ptr->word);
		inorder(ptr->right);// fill in 
	}
}
