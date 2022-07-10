#include "sample.h"
#include <stdio.h>
#include <stdlib.h>

void init(int_array *array, const int capacity) //�迭 �ʱ�ȭ �Լ�
{
  array->capacity = capacity;
  array->ptr = (int *)malloc(sizeof(int) * capacity);
  array->size = 0;
}

int peek(int_array *array, const int index)
{
  if (index < 0 && index >= array->size) //�ε����� �������� ������ 0����
    return 0;
  return array->ptr[index]; //�װԾƴѰ�� �ش� index�� ��ġ�ϴ� value ����
}

int insert(int_array *array, const int index, const int value) //���Ը޼ҵ�
{
  if ((index >= 0) && (index <= array->size)) // index�� ���� ���� �ִ°��
  {
    for (int i = (array->size - 1); i >= index; i--)
      array->ptr[i + 1] = array->ptr[i];
    array->ptr[index] = value;
    array->size++;
  }
}

void push(int_array *array, const int value)
{
  if (array->size == array->capacity) //�迭�� �������
  {
    free(array->ptr);
    realloc(array->ptr, sizeof(int) * (array->capacity * 2)); //���Ҵ�+capacity�� 2�� �÷���
    array->capacity *= 2;                                     //����ü ��������� capacity�� �Ȱ��� 2��÷���
  }

  else                                 //�迭�� ������ �������
    array->ptr[array->size++] = value; //������ ��ġ�� ���� ������
}

int delete (int_array *array, const int index)
{
  if (index < 0 || index >= array->size) //�迭�� ũ�⸦ ����� index�Է½�
    return 0;

  else if (array->ptr[index] && index >= 0 && index <= array->size) // ptr[index]�� ���� ������ ����  (������ �Ǵ°��)
  {
    for (int i = index; i < (array->size - 1); i++)
      array->ptr[i] = array->ptr[i + 1];
    array->size--;
    return 1;
  }

  else //������ �ȵǴ°�� false ����
    return 0;
}

void print_arr(int_array *array) //�迭 ���(�޼ҵ带 �߰�����)
{
  for (int i = 0; i < array->size; i++)
  {
    printf("%d  ", array->ptr[i]);
  }
}