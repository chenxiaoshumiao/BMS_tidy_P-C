#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void deleteElement(int sequence[], int* length, int position) {
    /*
    顺序表删除函数

    参数：
        sequence: 待删除元素的顺序表（数组）
        length: 顺序表的长度（指针类型）
        position: 待删除元素的位置（索引）
    */
    if (position < 0 || position >= *length) {
        printf("无效的位置\n");
        return;
    }
    for (int i = position; i < *length - 1; i++) {
        sequence[i] = sequence[i + 1];
    }
    *length -= 1;
}
