#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP_SIZE 101 
// 최대 100개의 요소를 인덱스 1부터 100에 저장 가능

int heap[MAX_HEAP_SIZE];
int heap_size = 0;

void swap(int* a, int* b);
void insert(int value);
int deleteMax();
void maxHeapify(int i);
void printHeap();

int main() {
    printf("=== 인덱스 1 기반 최대 힙(Max Heap) 테스트 ===\n");

    // 1. 삽입(Insert/Heap_Push) 연산 테스트
    printf("\n[삽입 연산]\n");
    insert(10);
    insert(5);
    insert(20);
    insert(33);
    insert(70);
    insert(30);
    insert(50);
    insert(90);
    insert(7);
    insert(40);

    printHeap(); // Heap (Array, Index 1부터): 40 20 10 3 5 (Size: 5)

    // 2. 최댓값 추출(DeleteMax/Heap_Pop) 연산 테스트
    printf("\n[삭제 연산]\n");

    int max_val;

    max_val = deleteMax();
    printf("추출된 최댓값: %d\n", max_val);
    printHeap();

    max_val = deleteMax();
    printf("추출된 최댓값: %d\n", max_val);
    printHeap();

    max_val = deleteMax();
    printf("추출된 최댓값: %d\n", max_val);
    printHeap();

    deleteMax();
    deleteMax();
    deleteMax();
    printHeap();

    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int value) {
    if (heap_size >= MAX_HEAP_SIZE - 1) {
        printf("오류: 힙이 가득 찼습니다. 삽입 실패\n");
        return;
    }
    heap_size++;
    int current = heap_size;
    heap[current] = value;
    while (current > 1) {
        int parent = current / 2; // 부모 노드의 인덱스
        if (heap[current] > heap[parent]) {
            swap(&heap[current], &heap[parent]);
            current = parent; // 부모 인덱스로 이동하여 계속 비교
        }
        else {
            break; // 힙 속성 만족, 종료
        }
    }
}

int deleteMax() {
    // 힙이 비어 있는지 확인 (루트가 인덱스 1이므로 heap_size가 0인지 확인)
    if (heap_size <= 0) {
        printf("오류: 힙이 비어 있습니다. 삭제 실패\n");
        return -1; // 오류 값 반환
    }

    int  max_value = heap[1];
    heap[1] = heap[heap_size];
    heap_size--;

    // Down-heap 과정: 루트로 이동한 새 요소를 정렬하여 힙 만들기
    maxHeapify(1); // 루트 인덱스 1에서 시작 : Down-heap
    return max_value;
}

void maxHeapify(int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= heap_size && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right <= heap_size && heap[right] > heap[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        maxHeapify(largest);
    }
}

void printHeap() {
    if (heap_size == 0) {
        printf("Heap: (Empty)\n");
        return;
    }
    printf("Heap (Array, Index 1부터): ");
    for (int i = 1; i <= heap_size; i++) {
        printf("%d ", heap[i]);
    }
    printf("(Size: %d)\n", heap_size);
}