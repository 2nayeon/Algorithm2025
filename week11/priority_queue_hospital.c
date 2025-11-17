#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[30];
    int priority; // 낮을수록 우선순위 높음
} Patient;

Patient heap[MAX];
int size = 0;

// 환자 교환
void swap(int a, int b) {
    Patient temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}

// 힙에 환자 추가
void insert(char* name, int priority) {
    int i = ++size;
    strcpy(heap[i].name, name);
    heap[i].priority = priority;

    // 최소 힙 구성
    while (i > 1 && heap[i].priority < heap[i / 2].priority) {
        swap(i, i / 2);
        i /= 2;
    }
}

// 가장 우선순위 높은 환자 꺼내기
Patient delete_min() {
    Patient min = heap[1];
    heap[1] = heap[size--];

    int parent = 1, child = 2;
    while (child <= size) {
        if (child + 1 <= size && heap[child + 1].priority < heap[child].priority)
            child++;
        if (heap[parent].priority <= heap[child].priority)
            break;
        swap(parent, child);
        parent = child;
        child *= 2;
    }

    return min;
}

int main() {
    // 환자 등록
    insert("환자A (안정)", 3);
    insert("환자B (위급)", 1);
    insert("환자C (보통)", 2);
    insert("환자D (안정)", 3);
    insert("환자E (위급)", 1);

    printf("== 응급실 진료 순서 ==\n");

    while (size > 0) {
        Patient p = delete_min();
        printf("진료 대상: %s, 우선순위: %d\n", p.name, p.priority);
    }

    return 0;
}
