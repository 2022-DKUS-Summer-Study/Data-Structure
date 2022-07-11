#pragma once

typedef struct __int_array {
	int* arr; // �迭�� ������
	int size; // �迭�� �ִ� �������� ��
	int capacity; // �迭�� ������ �� �ִ� �������� ��
}int_array;

void init(int_array* array, const int capacity);    //�迭 �ʱ�ȭ
int peek(int_array* array, const int index);
int insert(int_array* array, const int index, const int value);
void push(int_array* array, const int value);
int delete(int_array* array, const int index);