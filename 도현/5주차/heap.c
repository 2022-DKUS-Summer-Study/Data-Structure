//
//  heap.c
//  heap
//
//  Created by 정도현 on 2022/08/09.
//

#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

void init(Heap* heap){
    heap->heap_size = 0;    // 초기 개수는 0
}

// 원소 추가
void push(Heap* heap, int data){
    // 내부 원소가 꽉 차 있는 경우
    if(heap->heap_size == MAX_SIZE) {
        printf("HEAP IS FULL!\n");
        return;
    }
    
    heap->data[++(heap->heap_size)] = data;
    
    int idx = heap->heap_size;  // 추가된 자신의 인덱스
    int parentIdx = idx/2; // 부모 인덱스
    
    while(parentIdx > 0) {
        // 부모가 자식보다 작은 경우 부모 자식 Swap
        if(heap->data[parentIdx] < heap->data[idx]) {
            // swap
            int tmp = heap->data[parentIdx];
            heap->data[parentIdx] = heap->data[idx];
            heap->data[idx] = tmp;
            
            idx = parentIdx;    // 바뀐 위치로 인덱스 번호 교체
            parentIdx = idx / 2;    // 새로운 상위 부모 인덱스
        } else
            break;
    }
}

// 최상위 원소 삭제 -> 최대 힙에서는 최대 값 삭제
void pop(Heap* heap){
    if(isEmpty(heap)) {
        printf("no data in HEAP\n");
        return;
    } else {
        heap->data[1] = heap->data[heap->heap_size];    // 마지막 데이터를 루트로 올린다.
        heap->heap_size--; // 크기 1 감소
        
        int now = 1;    // 루트부터 시작
        int child = 2;  // 왼쪽 자식
        
        while (child <= heap->heap_size) {
            // 오른쪽 자식이 힙 크기 이하이고 왼쪽 자식보다 크면 오른쪽 자식으로 대상 교체
            if (child + 1 <= heap->heap_size && heap->data[child] < heap->data[child+1]) {
                child++; // 오른쪽 자식으로 이동
            }
            
            // 자식이 부모보다 큰 경우 교체
            if (heap->data[child] > heap->data[now]) {
                int tmp = heap->data[now];
                heap->data[now] = heap->data[child];
                heap->data[child] = tmp;
                
                // 다음 노드로 이동
                now = child;
                child = now * 2;
            }
            // 자리를 찾은 경우 루프 탈출
            else
                break;
        }
    }
}

// 최 상위 루트 값 리턴
int peek(Heap* heap){
    return heap->data[1];
}

// 비어있는지 여부 확인
int isEmpty(Heap* heap){
    // 비어있다면 1 아니면 0 반환
    return (heap->heap_size ? 0 : 1);
}

void heapify(int *arr, int size, int i) {
    int parent = i;
    int leftIdx = parent*2 + 1;
    int rightIdx = parent*2 + 2;
    int child = parent;
    
    
    if(leftIdx < size && arr[leftIdx] > arr[child])
        child = leftIdx;
    // 우측 노드가 있고 더 크다면 오른쪽 자식으로 교체
    if(rightIdx < size && arr[rightIdx] > arr[child]) {
        child = rightIdx;
    }
    
    if(parent != child) {
        int tmp = arr[child];
        arr[child] = arr[parent];
        arr[parent] = tmp;
        heapify(arr, size, child);
    }
}

void heap_sort(int* arr, int n){
    // 최대 힙 구성
    for(int node = (n/2) - 1; node >= 0; node--) {
        heapify(arr, n, node);
    }
    
    // 힙 정렬
    while(n > 1) {
        int tmp = arr[0];
        arr[0] = arr[n - 1];
        arr[n - 1] = tmp;
        
        n--; // 사이즈  -1
        heapify(arr, n, 0);
    }
}


void print_arr(int* arr, int n) {
    if (n == 0) {
        printf("no data in Array\n");
    } else {
        for(int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
