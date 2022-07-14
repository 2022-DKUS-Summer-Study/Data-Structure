#pragma once

typedef struct int_array
{
  int *ptr;
  int size;
  int capacity;
} int_array;

void init(int_array *array, const int capacity); //�迭 �ʱ�ȭ
int peek(int_array *array, const int index);
int insert(int_array *array, const int index, const int value);
void push(int_array *array, const int value);
int delete (int_array *array, const int index);
void print_arr(int_array *array);



