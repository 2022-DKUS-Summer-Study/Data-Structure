#include "sample.h"
#include <stdio.h>
#include <stdlib.h>

void init(int_array *array, const int capacity)
{
  array->size = capacity;
  array->size = 0;
  array->ptr = (int *)malloc(sizeof(int) * capacity);
}

int peek(int_array *array, const int index)
{
  if (index < 0 && index >= array->size)
    return 0;
  return array->ptr[index];
}

int insert(int_array *array, const int index, const int value)
{
  if (!is_full(array) && (index >= 0) && (index <= array->size))
  {
    for (int i = (array->size - 1); i >= index; i--)
      array->ptr[i + 1] = array->ptr[i];
    array->ptr[index] = value;
    array->size++;
  }
}

void push(int_array *array, const int value)
{
  if (is_full(array))
  {
    free(array->ptr);
    realloc(array->ptr, sizeof(int) * 200);
    array->ptr[array->size++] = value;
  }

  else
    array->ptr[array->size++] = value;
}

int delete (int_array *array, const int index)
{
  if (index < 0 || index >= array->size) //배열의 크기를 벗어나는 index입력시
    return 0;

  else if (array->ptr[index] && index >= 0 && index <= array->size) // ptr[index]에 값이 있으면 삭제
  {
    for (int i = index; i < (array->size - 1); i++)
      array->ptr[i] = array->ptr[i + 1];
    array->size--;
    return 1;
  }
}

int is_empty(int_array *array)
{
  if (array->size == 0)
    return 1;
  else
    return 0;
}

int is_full(int_array *array)
{
  return array->size == 100;
}

void print_arr(int_array *array)
{
  for (int i = 0; i < array->size; i++)
  {
    printf("%d  ", array->ptr[i]);
  }
}