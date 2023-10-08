#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sequentialSearch(int sequence[], int length, int target) {
    /*
    顺序表查找函数

    参数：
        sequence: 待查找的顺序表（数组）
        length: 顺序表的长度
        target: 目标元素

    返回值：
        如果目标元素在顺序表中，返回其位置；否则返回-1。
    */
    for (int i = 0; i < length; i++) {
        if (sequence[i] == target) {
            return i;
        }
    }
    return -1;
}