#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sequentialSearch(int sequence[], int length, int target) {
    /*
    ˳�����Һ���

    ������
        sequence: �����ҵ�˳������飩
        length: ˳���ĳ���
        target: Ŀ��Ԫ��

    ����ֵ��
        ���Ŀ��Ԫ����˳����У�������λ�ã����򷵻�-1��
    */
    for (int i = 0; i < length; i++) {
        if (sequence[i] == target) {
            return i;
        }
    }
    return -1;
}