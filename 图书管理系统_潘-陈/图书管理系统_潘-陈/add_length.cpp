#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int* increaseLength(int sequence[], int* length, int increaseBy) {
    /*
    ����˳����Ⱥ���

    ������
        sequence: ԭʼ˳������飩
        length: ԭʼ˳���ĳ��ȣ�ָ�����ͣ�
        increaseBy: ���ӵĳ���

    ����ֵ��
        �µ�˳������飩
    */
    int newLength = *length + increaseBy;
    if (newLength > MAX_SIZE) {
        printf("���ӵĳ��ȳ������������\n");
        return NULL;
    }

    // �����µ�˳���
    int* newSequence = (int*)malloc(newLength * sizeof(int));
    if (newSequence == NULL) {
        printf("�ڴ����ʧ��\n");
        return NULL;
    }

    // ����ԭʼ˳������ݵ��µ�˳���
    for (int i = 0; i < *length; i++) {
        newSequence[i] = sequence[i];
    }

    // �ͷ�ԭʼ˳�����ڴ�
    free(sequence);

    // ����˳�����
    *length = newLength;

    return newSequence;
}
