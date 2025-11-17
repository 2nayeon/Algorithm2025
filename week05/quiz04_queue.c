#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cnode* course_list_pointer;
struct cnode {
    char courseid[10];
    char tname[20];
    unsigned snum;
    unsigned roomnum;
    course_list_pointer next;
};

void print_over40(course_list_pointer ptr);
void search_by_prof(course_list_pointer ptr, char name[]);
void search_by_room(course_list_pointer ptr, unsigned sroomnum);

int main(int argc, char* argv[])
{
    FILE* coursedb;
    course_list_pointer temp = NULL, first = NULL, ptr = NULL, before = NULL;
    char sprof[20];
    unsigned sroomnum, total = 0;

    if (argc != 2) {
        printf("명령인수를 잘못 입력했습니다.");
        exit(1);
    }

    if ((coursedb = fopen(argv[1], "r")) == NULL) {
        printf("데이터 파일을 열 수 없습니다.\n");
        exit(1);
    }

    while (1) {
        temp = (course_list_pointer)malloc(sizeof(struct cnode));
        if (fscanf(coursedb, "%s %s %u %u",
            temp->courseid, temp->tname,
            &(temp->snum), &(temp->roomnum)) == EOF) {
            free(temp);
            break;
        }

        temp->next = NULL;

        if (first == NULL) {
            first = temp;
        }
        else {
            before->next = temp;
        }

        before = temp;
    }
    fclose(coursedb);

    ptr = first;

    printf("저장된 강좌 ID:\n");
    for (; ptr; ptr = ptr->next) {
        printf("%s\n", ptr->courseid);
        total += ptr->snum;
    }

    printf("+++++++++++++++++++++++++++++++\n");
    printf("전체 수강생 수 : %u\n\n", total);

    printf("수강인원이 40명 이상인 강좌 코드 번호를 출력하시오.\n");
    print_over40(first);
    printf("\n");

    printf("검색하고자 하는 교수이름 입력 : ");
    scanf("%s", sprof);
    printf("%s 교수가 강의하는 강좌코드와 강의실 번호를 출력하시오.\n", sprof);
    search_by_prof(first, sprof);
    printf("\n");

    printf("검색하고자 하는 강의실 번호 입력 : ");
    scanf("%u", &sroomnum);
    printf("%u 강의실에 수업하는 강좌코드와 담당교수를 출력하시오.\n", sroomnum);
    search_by_room(first, sroomnum);

    return 0;
}

void print_over40(course_list_pointer ptr)
{
    for (; ptr; ptr = ptr->next)
        if (ptr->snum >= 40)
            printf("%s\n", ptr->courseid);
}

void search_by_prof(course_list_pointer ptr, char name[])
{
    for (; ptr; ptr = ptr->next)
        if (!strcmp(ptr->tname, name))
            printf("%s\t%u\n", ptr->courseid, ptr->roomnum);
}

void search_by_room(course_list_pointer ptr, unsigned sroomnum)
{
    for (; ptr; ptr = ptr->next)
        if (ptr->roomnum == sroomnum)
            printf("%s\t%s\n", ptr->courseid, ptr->tname);
}
