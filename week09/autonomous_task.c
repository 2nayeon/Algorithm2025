#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define PAGE_NAME_LENGTH 100

typedef struct {
    char pages[MAX][PAGE_NAME_LENGTH];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

int is_empty(Stack* s) {
    return s->top == -1;
}

int is_full(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, const char* page) {
    if (is_full(s)) {
        printf("스택이 가득 찼습니다.\n");
        return;
    }
    strcpy(s->pages[++(s->top)], page);
    printf("방문: %s\n", page);
}

void pop(Stack* s) {
    if (is_empty(s)) {
        printf("뒤로 갈 수 없습니다.\n");
        return;
    }
    s->top--;
    if (!is_empty(s)) {
        printf("이전 페이지로 이동: %s\n", s->pages[s->top]);
    }
    else {
        printf("더 이상 이전 페이지가 없습니다.\n");
    }
}

const char* current_page(Stack* s) {
    if (is_empty(s)) return "페이지 없음";
    return s->pages[s->top];
}

int main() {
    Stack browser;
    init(&browser);

    push(&browser, "google.com");
    push(&browser, "naver.com");
    push(&browser, "gptonline.ai");

    printf("현재 페이지: %s\n", current_page(&browser));

    pop(&browser);
    printf("현재 페이지: %s\n", current_page(&browser));

    pop(&browser);
    printf("현재 페이지: %s\n", current_page(&browser));

    pop(&browser);  // 더 이상 뒤로 갈 수 없음
    printf("현재 페이지: %s\n", current_page(&browser));

    return 0;
}
