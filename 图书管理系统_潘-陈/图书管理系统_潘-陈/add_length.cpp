#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int* increaseLength(int sequence[], int* length, int increaseBy) {
    /*
    增加顺序表长度函数

    参数：
        sequence: 原始顺序表（数组）
        length: 原始顺序表的长度（指针类型）
        increaseBy: 增加的长度

    返回值：
        新的顺序表（数组）
    */
    int newLength = *length + increaseBy;
    if (newLength > MAX_SIZE) {
        printf("增加的长度超过了最大限制\n");
        return NULL;
    }

    // 创建新的顺序表
    int* newSequence = (int*)malloc(newLength * sizeof(int));
    if (newSequence == NULL) {
        printf("内存分配失败\n");
        return NULL;
    }

    // 复制原始顺序表数据到新的顺序表
    for (int i = 0; i < *length; i++) {
        newSequence[i] = sequence[i];
    }

    // 释放原始顺序表的内存
    free(sequence);

    // 更新顺序表长度
    *length = newLength;

    return newSequence;
}
