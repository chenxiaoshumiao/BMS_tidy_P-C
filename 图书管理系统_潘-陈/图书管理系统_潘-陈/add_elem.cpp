#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100

void insertElement(int sequence[], int* length, int position, int element) {
    /*
    ˳������Ԫ�غ���

    ������
        sequence: �����Ԫ�ص�˳������飩
        length: ˳���ĳ��ȣ�ָ�����ͣ�
        position: �����Ԫ�ص�λ�ã�������
        element: ����ӵ�Ԫ��
    */
    if (*length >= MAX_SIZE) {
        printf("˳����������޷����Ԫ��\n");
        return;
    }
    if (position < 0 || position > *length) {
        printf("��Ч��λ��\n");
        return;
    }
    for (int i = *length; i > position; i--) {
        sequence[i] = sequence[i - 1];
    }
    sequence[position] = element;
    *length += 1;
}
