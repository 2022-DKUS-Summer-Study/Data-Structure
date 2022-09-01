//
//  main.c
//  heap
//
//  Created by 정도현 on 2022/08/09.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heap.h"

int main(int argc, const char * argv[]) {
    Heap *h = (Heap*)malloc(sizeof(Heap));
    init(h);
    
    int menu;
    while(true) {
        printf("힙의 최대 데이터 개수는 1000개로 제한 됩니다. 현재 데이터 수 %d\n", h->heap_size);
        printf("0 - 프로그램 종료 \n");
        printf("1 - 데이터 삽입 \n");
        printf("2 - 데이터 삭제 \n");
        printf("3 - 최대 값 반환 \n");
        printf("4 - 임의의 배열 생성 후 힙정렬 \n");
        printf("원하는 작업 번호를 선택하세요: ");
        
        scanf("%d", &menu);
        switch(menu){
            case 0:
                exit(1);
                break;
            case 1:
                printf("넣을 데이터를 입력하세요: ");
                int data;
                scanf("%d", &data);
                push(h, data);
                printf("\n");
                break;
            case 2:
                printf("루트 데이터를 삭제 합니다.\n");
                pop(h);
                printf("\n");
                break;
            case 3:
                if(isEmpty(h)){
                    printf("heap이 비어있습니다.\n");
                } else {
                    printf("가장 큰 값을 반환 합니다. data -> %d \n", peek(h));
                }
                printf("\n");
                break;
            case 4:
                printf("배열에 넣을 데이터 수를 입력하세요 : ");
                int arr_size;
                scanf("%d", &arr_size);
                int *arr = (int *)malloc(sizeof(int) * arr_size);
                printf("내부 원소들을 한 개씩 입력해주세요\n");
                for(int i = 0; i<arr_size; i++) {
                    scanf("%d", &arr[i]);
                }
                printf(" 정렬 전 상태 \n");
                print_arr(arr, arr_size);
                
                heap_sort(arr, arr_size);
                printf(" 정렬 후 상태 \n");
                print_arr(arr, arr_size);
                printf("\n");
                break;
            default:
                printf("정확하게 다시 입력해주세요");
        }
    }
}
