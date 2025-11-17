#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
    struct node* left;
    int eid;
    int syear;
    char grade;
    struct node* right;
} ENODE;

int insert_node(ENODE* root, int num, int year, char score);
// ENODE* search(ENODE* root, int key);
ENODE* rsearch(ENODE* root, int key);
void inorder(ENODE* ptr);
void year_search(ENODE* ptr, int year);

int main(int argc, char* argv[])
{
    ENODE* tree = NULL, * ptr;
    int id, year;
    char score;
    FILE* input;

    if ((input = fopen(argv[1], "r")) == NULL) {  // fill in 
        printf("Invalid input file...\n");
        exit(1);
    }

    while (fscanf(input, "%d %d %c", &id, &year, &score) != EOF) {
        if (!tree) {  // 트리가 비었을때
            tree = (ENODE*)malloc(sizeof(ENODE));
            tree->eid = id;
            tree->syear = year;
            tree->grade = score;
            tree->left = tree->right = NULL;   // fill in 
        }
        else
            insert_node(tree, id, year, score);    // fill in : call insert_node()
    }

    printf("\n 트리에 구축된 사원정보 : \n");
    inorder(tree);   // fill in : call inorder()

    printf("\n 입사년도 : ");
    scanf("%d", &year);
    year_search(tree, year);   // fill in : call year_search()

    getchar();
    printf("\n 사원 번호 : ");
    scanf("%d", &id);
    ptr = rsearch(tree, id);   // fill in : call search()

    if (ptr)
        printf("%d번 사원의 정보 : %d\t%c\n", ptr->eid, ptr->syear, ptr->grade);
    else
        printf("%d번 사원에 대한 정보는 없습니다.\n", id);

}

int insert_node(ENODE* root, int id, int year, char score) {
    ENODE* tptr = root, * before = NULL;

    while (tptr) {

        if (id < tptr->eid) {
            before = tptr;    // fill in 
            tptr = tptr->left;
        }
        else if (id > tptr->eid) {
            before = tptr;    // fill in 
            tptr = tptr->right;
        }
        else        // found
            return 0;
    }

    tptr = (ENODE*)malloc(sizeof(ENODE));    // fill in 
    tptr->eid = id;
    tptr->syear = year;
    tptr->grade = score;
    tptr->left = tptr->right = NULL;
    if (id < before->eid) before->left = tptr;  // 조건문 fill in 
    else  before->right = tptr;
    return 1;
}

void year_search(ENODE* ptr, int year) {
    if (ptr) {
        year_search(ptr->left, year);
        if ((ptr->syear) == year)
            printf("%d\t%c\n", ptr->eid, ptr->grade);
        year_search(ptr->right, year);
    }
}

void inorder(ENODE* ptr) {
    if (ptr) {
        inorder(ptr->left);
        printf("%d\t%d\t%c\n", ptr->eid, ptr->syear, ptr->grade);
        inorder(ptr->right);
    }
}

/*
ENODE* search(ENODE* root, int key) {
    ENODE* tptr = root;

    while (tptr) {   // fill in 
        if (key < tptr->eid)
            tptr = tptr->left;
        else if (key > tptr->eid)
            tptr = tptr->right;
        else        // found
            return tptr;
    }
    return NULL;   // not found
}
*/

ENODE* rsearch(ENODE* root, int key) {
    if (root) {
        if (key < root->eid)
            return rsearch(root->left, key);
        else if (key > root->eid)
            return rsearch(root->right, key);
        else
            return root;
    }
    return NULL;
}