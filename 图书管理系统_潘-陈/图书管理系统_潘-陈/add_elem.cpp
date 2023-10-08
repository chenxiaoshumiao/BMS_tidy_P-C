#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100

void insertElement(int sequence[], int* length, int position, int element) {
    /*
    顺序表添加元素函数

    参数：
        sequence: 待添加元素的顺序表（数组）
        length: 顺序表的长度（指针类型）
        position: 待添加元素的位置（索引）
        element: 待添加的元素
    */
    if (*length >= MAX_SIZE) {
        printf("顺序表已满，无法添加元素\n");
        return;
    }
    if (position < 0 || position > *length) {
        printf("无效的位置\n");
        return;
    }
    for (int i = *length; i > position; i--) {
        sequence[i] = sequence[i - 1];
    }
    sequence[position] = element;
    *length += 1;
}
