#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void deleteElement(int sequence[], int* length, int position) {
    /*
    ˳���ɾ������

    ������
        sequence: ��ɾ��Ԫ�ص�˳������飩
        length: ˳���ĳ��ȣ�ָ�����ͣ�
        position: ��ɾ��Ԫ�ص�λ�ã�������
    */
    if (position < 0 || position >= *length) {
        printf("��Ч��λ��\n");
        return;
    }
    for (int i = position; i < *length - 1; i++) {
        sequence[i] = sequence[i + 1];
    }
    *length -= 1;
}
