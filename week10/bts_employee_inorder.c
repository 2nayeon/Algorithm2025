#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    struct node* left;
    int eid;
    int syear;
    char grade;
    struct node* right;
} ENODE;

int insert_node(ENODE* root, int id, int year, char score);
void inorder(ENODE* ptr);
void year_search(ENODE* ptr, int year);
ENODE* search(ENODE* root, int key);

int main() {
    ENODE* tree = NULL, * ptr;
    int id, year;
    char score;

    printf("검색 트리에 저장할 사원정보를 입력하세요.\n");
    printf("사원번호 입사년도 인사등급을 입력하고\n");
    printf("입력의 끝에는 (0 0 0)을 입력하세요.\n");

    while (1) {
        scanf("%d %d %c", &id, &year, &score);
        if (id == 0 && year == 0 && score == '0') break;

        if (!tree) {
            tree = (ENODE*)malloc(sizeof(ENODE));
            tree->eid = id;
            tree->syear = year;
            tree->grade = score;
            tree->left = tree->right = NULL;
        }
        else {
            insert_node(tree, id, year, score);
        }
    }

    printf("\n트리에 구축된 사원정보:\n");
    inorder(tree);

    printf("\n검색할 입사년도: ");
    scanf("%d", &year);
    year_search(tree, year);

    printf("\n검색할 사원 번호: ");
    scanf("%d", &id);
    ptr = search(tree, id);

    if (ptr)
        printf("%d번 사원의 정보: %d\t%c\n", ptr->eid, ptr->syear, ptr->grade);
    else
        printf("%d번 사원에 대한 정보는 없습니다.\n", id);

    return 0;
}

int insert_node(ENODE* root, int id, int year, char score) {
    ENODE* tptr = root;
    ENODE* before = NULL;

    while (tptr) {
        before = tptr;
        if (id < tptr->eid) {
            tptr = tptr->left;
        }
        else if (id > tptr->eid) {
            tptr = tptr->right;
        }
        else {
            return 0;  // 중복된 ID는 삽입하지 않음
        }
    }

    tptr = (ENODE*)malloc(sizeof(ENODE));
    tptr->eid = id;
    tptr->syear = year;
    tptr->grade = score;
    tptr->left = tptr->right = NULL;

    if (id < before->eid)
        before->left = tptr;
    else
        before->right = tptr;

    return 1;
}

void inorder(ENODE* ptr) {
    if (ptr) {
        inorder(ptr->left);
        printf("%d\t%d\t%c\n", ptr->eid, ptr->syear, ptr->grade);
        inorder(ptr->right);
    }
}

void year_search(ENODE* ptr, int year) {
    if (ptr) {
        year_search(ptr->left, year);
        if (ptr->syear == year)
            printf("%d\t%d\t%c\n", ptr->eid, ptr->syear, ptr->grade);
        year_search(ptr->right, year);
    }
}

ENODE* search(ENODE* root, int key) {
    ENODE* tptr = root;
    while (tptr) {
        if (key < tptr->eid)
            tptr = tptr->left;
        else if (key > tptr->eid)
            tptr = tptr->right;
        else
            return tptr;
    }
    return NULL;
}
