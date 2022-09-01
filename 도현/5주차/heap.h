//
//  heap.h
//  heap
//
//  Created by 정도현 on 2022/08/09.
//

#pragma once
#define MAX_SIZE 1001

// 최대 힙 구현 했습니다.
typedef struct _Heap{
    int data[MAX_SIZE];
    int heap_size;
}Heap;

void init(Heap* heap);
void push(Heap* heap, int data);   //data 타입은 자유롭게
void pop(Heap* heap);
int peek(Heap* heap);
int isEmpty(Heap* heap);
void heapify(int *arr, int size, int i);
void heap_sort(int* arr, int n);  //arr[1] ~ arr[n] 까지 정렬
void print_arr(int* arr, int n);
