#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct bstnode {
    struct bstnode* left;
    int key;
    float score;
    struct bstnode* right;
} BSTNODE;

int insert_bst(BSTNODE* root, int id, float score);
void scan_bst(BSTNODE* ptr);

int main()
{
    BSTNODE* tree = NULL, * ptr = NULL;  //참조되지 않는 지역변수
    int sid;
    float grade;

    printf("  트리에 저장할 아이디와 평균평점을 입력하세요.\n");
    printf("  입력의 끝에는 0 0 을 입력하세요.\n");
    scanf("%d %f", &sid, &grade);

    while (sid != 0) {
        if (!tree) { // tree == NULL
            tree = (BSTNODE*)malloc(sizeof(BSTNODE));
            tree->key = sid;
            tree->left = tree->right = NULL;
            tree->score = grade;
        }
        else
            insert_bst(tree, sid, grade);
        scanf("%d %f", &sid, &grade);
    }
    scan_bst(tree);
    return 0;
}

int insert_bst(BSTNODE *root, int id, float score) {
    BSTNODE* tptr = root, * before = NULL, * node;
    while (tptr) {
        if (id < tptr->key) {
            before = tptr;
            tptr = tptr->left;
        }
        else if (id > tptr->key) {
            before = tptr;
            tptr = tptr->right;
        }
        else
            return 0;
    }
    node = (BSTNODE*)malloc(sizeof(BSTNODE));
    node->key = id;
    node->score = score;
    node->left = node->right = NULL;

    if (id < before->key) before->left = node;
    else before->right = node;
    return 1;
}

void scan_bst(BSTNODE* ptr) {
    if (ptr == NULL){
        scan_bst(ptr->left);
        printf("ID: %d, Score: %.2f\n", ptr->key, ptr->score);
        scan_bst(ptr->right);
    }
}